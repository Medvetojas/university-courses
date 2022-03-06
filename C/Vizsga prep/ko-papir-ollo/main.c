#include <stdio.h>
#include <ctype.h>
int ki_nyert (int Fvalasz, int Gvalasz);
int beolvas (int * Fvalasz);
typedef enum {KO, PAPIR, OLLO} valasz_tipus;
typedef enum {SENKI, FELH, GEP} jatekos_tipus;
int main() {
 int jo, fpont = 0, gpont = 0, jatek = 0;
 char ujra;
 srand(time(0));
 valasz_tipus Fvalasztas, Gvalasztas;
 jatekos_tipus nyertes;
 printf("Jatsszunk ko-papir-ollo-t!\n");
 do {
 do { jo=beolvas(&Fvalasztas); } while (!jo); // ellenõrzött beolvasás
 Gvalasztas = rand()%2; // 0, 1, vagy 2
 printf("Gep: %d\n", Gvalasztas);
 jatek++;
 nyertes = ki_nyert(Fvalasztas, Gvalasztas);
 switch (nyertes) {
 case FELH:
 printf("Te gyoztel!\n"); fpont++;
  break;
 case GEP:
 printf("En gyoztem!\n"); gpont++;
 break;
 default:
 printf("Dontetlen!\n");
 }
 printf("Akarsz meg jatszani (i/n)? ");
 scanf(" %c", &ujra); // %c elõtt space van!!!
 } while (ujra=='i' || ujra=='I');
 printf("Osszesites: %d-bol %d-szor nyertel.", jatek, fpont);
 return 0;
}
int beolvas (int * Fvalasz) {
 printf("Mit valasztasz? 0-ko, 1-papir, 2-ollo: ");
 if (scanf("%d", Fvalasz)!=1) {
 printf("Rossz valasz!\n");
 exit(-1);
 }
 else if ( *Fvalasz != 0 && *Fvalasz != 1 && *Fvalasz != 2 ) {
 printf("Rossz valasz!\n");
 return 0;
 }
 return 1;
}
int ki_nyert (int Fvalasz, int Gvalasz) {
 if (Fvalasz == Gvalasz) return SENKI;
 switch (Fvalasz) {
 case KO :
 if (Gvalasz==PAPIR) return GEP;
 else return FELH;
 break;
 case PAPIR :
 if (Gvalasz==OLLO) return GEP;
 else return FELH;
 break;
 case OLLO :
 if (Gvalasz==KO) return GEP;
 else return FELH;
 break;
 }
}
