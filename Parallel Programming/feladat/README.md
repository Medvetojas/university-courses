# Párhuzamos algoritmusok féléves feladat

Ezen fájl tartalmazza a párhuzamos algoritmusok beadandóim leírását.
A projektek rövid leírása az alábbiakban látható:

* OpenMP - C projekt:
  * A projektben a Monte Carlo, a Leibniz, a Riemann és a Wallis Pi közelítési módokat implementáltam.
  * A Monte Carlo közelítés feltöltésre került szekvenciális változatban is, és a futási ideje összehasonlításra került
    OpenMP-ben írt párhuzamos megvalósításával is.
  * Továbbá összehasonlításra kerültek többi Pi közelítési módszerek is párhuzamos megvalósításban.
  * Összességében elmondható, hogy a leggyorsabb Pi közelítés a Wallis módszere, a leglassabb pedig a Riemann módszer.

* pthread - C projekt:
  * A projekt a processzorok Hyperthreading funkcióinak hátrányát mutatja be.
  * A program 5 szálat használ egy string 180000-szeres fájlba írására, szálanként egy fileba. A szálak alapvetően
    versengenek a lemezre írás lehetőségéért.
  * Hyperthreading módban több "processzor" küzd ezért az írási jogért, de egyszerre csak egy írhat.
  * Hyperthreading használata nélkül kevesebb "processzor" van, így gyorsabb lesz a program futása.
  * A cél az volna, hogy láthatóvű váljon, hogy a modern CPUk technológiái nem feltétlenül előnyösek minden esetben.

* Threading - Python projekt:
  * A projekt egy Snake játék, mely eredetileg szekvenciális futással lett megírva, de kis módosítással párhuzamos
    futásra alkalmas.
  * A párhuzamosított részek:
    * Input kezelés
    * Megjelenített kép frissítése, "renderelése"
  * A párhuzamosítás jelen esetben szabad szemmel látható változással, javulással **nem** jár, a projekt sajátossága
    miatt nehezen mérhető a futásteljesítmény.

A párhuzamosan és szekvenciálisan futó projektek tehát ***C** nyelven, **pthread, OpenMP** könyvtárak* használatával, *
illetve **Python** nyelv és a **threading** könyvtár* segítségével készült el.
