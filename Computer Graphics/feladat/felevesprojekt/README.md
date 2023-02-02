# Számítógépi grafika féléves feladat

Ezen fájl tartalmazza a számítógépi grafika beadandóm leírását. A feladatnak *külön koncepciója* nincsen, tulajdonképpen
egy basic *tech demo*, már ha lehet egy ilyen OpenGL projektet annak nevezni.

* Input:

  A kamera szabadon mozgatható a

  * **W, A, S, D, Space és LCtrl** gombokkal + **egérrel**, illetve
  * Xbox One Controller **analógokkal**

* Fényerő:
  * **F1** és **F2** gombokkal növelni és csökkenteni

* Egyéb extrák:
  * **F12** gomb segítségével .bmp formátumú képernyőmentés készíthető
  * **1, 2, 3** gombok megnyomásával az Unreal Superhero zene játszódik le háromféle kiadásban
  * **P** gomb használatával kapcsolható a háznak az ütközésvizsgálata
  * **H** gombbal pedig kiírható a konzolra a kamera jelenlegi X, Y, Z koordinátája (debug funkció)

* Help menü:
  * **Tab** gomb megnyomásával előhozható a fenti *használati utasításokat* előhozó segítség menü

A program indítása után a kamera egy házban kerül megjelenítésre. Itt alapvető berendezési elemek kerültek elhelyezésre.
A ház egy dombokkal tarkított területen került elhelyezésre. A ház előtt megtalálható az *átlátszóságot demonstráló **
fűcsomó***, a térkép felett pedig körbe-körbe repül egy kacsa.

Látható még, hogy a kacsával hasonlóan egy ***fénycsóva** is mozog* a pályán. Az egész térképet egy ***skybox*** veszi
körül. A pálya szélén egy ***hatalmas nyúl*** figyel a pályára.

A projekt ***C** nyelven, **SDL** könyvtár* használatával, *régi **OpenGL*** segítségével készült el.
