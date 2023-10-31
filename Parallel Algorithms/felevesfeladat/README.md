# Párhuzamos eszközök programozása féléves feladat

Ezen readme tartalmazza a párhuzamos eszközök beadandóm leírását.

## A feladat leírása

A feladatban az úgynevezett Cooley-Tukey féle, Decimation in Time Fast Fourier Transform (DIT-FFT) algoritmust implementáltam C nyelvben.

![](https://github.com/Medvetojas/parallel_devices/blob/main/felevesfeladat/algorithm.svg?raw=true)

Fontos, hogy az algoritmus csak 2-nek a hatványaira működik megbízhatóan az algoritmus miatt.

Két darab program készült:
  * egy OpenCL könyvtárral készült GPU-n futó program, illetve
  * egy sima szinkron CPU-n futó program

A cél annak a demonstrálása, hogy az OpenCL változat gyorsabban végzi a számításokat, így a programfutás is sokkal hamarabb fejeződik be.

## A készült szoftver rövid leírása

  * Az OpenCL változatban deklarálom az OpenCL működéséhez elengedhetetlen változókat, létrehozom az OpenCL kontextust, a queuet, és betöltöm az fft.cl fájlt ami tartalmazza az algoritmust.
    * A szinkron változatban ezek kimaradnak, az algoritmus a main.c fájlban található egyből, így betölteni azt nem kell a kernelbe
  * A kódban egy #define-ban előre meghatározott MAX_TASK_SIZE-ig (2-nek MAX_TASK_SIZE hatványáig) elkezd dolgozni az algoritmus.
    * Elindul egy stopper
    * Létrehozódik az input (float) és az output (float2) tömbök, majd ezek beállítódnak kernelargumentumként
      * Mivel a float2 struktúra az OpenCL saját struktúrája, ezért a szinkron változatban definiáltam mint saját struktúra
    * Az OpenCL kódban a clEnqueueNDRangeKernel függvény meghívódik, mely a kernel futtatását megkezdi
      * A szinkron változatban a tömbök szimplán átadásra kerülnek az algoritmusnak
    * Az algoritmus a fenti képen látható módon lefut
    * A futás után a főprogram beolvassa a bufferből az eredményt, majd azok kiprintelődnek a konzolra
  * Kiíratódik a futási idő, majd a program leáll

A programok C nyelven, CLion fejlesztői környezet használatával készültek.
A futtatáshoz a CMakeLists.txt fájlt mellékeltem.

## Futási eredmények

Az összehasonlításhoz a következő hardver állt rendelkezésemre:
  * Laptop:
    * Intel Core i7-4800MQ @ 2.70GHz 4 mag, 8 logikai mag
    * NVIDIA GeForce 730M
  * Asztali PC:
    * AMD Ryzen 7 5800X @ 3.80Ghz 8 mag, 16 logikai mag
    * NVIDIA GeForce RTX 4070 Ti

A futási eredményekről összehasonlító diagramot készítettem.

![](https://github.com/Medvetojas/parallel_devices/blob/main/felevesfeladat/1-32768.png?raw=true)
![](https://github.com/Medvetojas/parallel_devices/blob/main/felevesfeladat/4096-32768.png?raw=true)

 * Összességében elmondható, hogy a számítógépek az algoritmust GPU-n futtatva a gyengébb és a nála sokkal gyorsabb hardveren is, gyakorlatilag azonnal elvégezték a számítást.
 * Míg a CPU-n futó algoritmus mindkét processzoron sokkal lassabb volt, mint a GPU-n futó társa.
