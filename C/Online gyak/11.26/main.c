#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SZERZOHOSSZ 50
#define CIMHOSSZ 50
#define KONYVTARMERET 100

typedef struct konyv{
    char szerzo[SZERZOHOSSZ+1];
    char cim[CIMHOSSZ+1];
    int kiadasEve;
    int ar;
} Konyv;

int beolvasKonyvFilebol(FILE* fp, Konyv* konyvek);
void kiirKonyvet(Konyv* konyvek, int meret);
void kiirKonyvetFileba(char* filenev, Konyv* konyvek, int meret);

int main()
{
    setlocale(LC_ALL, "hun");


    Konyv konyvtar[KONYVTARMERET];
    //Konyv kivalogatott[KONYVARMERET]; //Ismert, de helypocsékló megoldás
    Konyv * kivalogatott;
    int konyvekSzama;
    FILE *fp;
    const char filenev[] = "konyvek.txt";
    if ((fp = fopen(filenev, "rt")) == NULL){
        printf("A %s file megnyitása sikertelen!", filenev);
        exit(-1); //olyan fgv., amelyik sikertelen fájlmegnyitás után leállítja a program futását
    }
    konyvekSzama = beolvasKonyvFilebol(fp, konyvtar);
    kiirKonyvet(konyvtar, konyvekSzama);
    kiirKonyvetFileba("lista.txt", konyvtar, konyvekSzama);

    return 0;
}

int beolvasKonyvFilebol(FILE* fp, Konyv* konyvek){
    int db = 0;
    while (fscanf(fp, "%s %s %d %d", konyvek[db].szerzo, konyvek[db].cim, &konyvek[db].kiadasEve, &konyvek[db].ar) == 4){ //kell az &, mert számot olvasok be, és while-ba teszem, mert annyi adatot olvasok be
        db++;
    }
    return db+1;
}

void kiirKonyvet(Konyv* konyvek, int meret){
    for (int i = 0; i<meret; i++){
        printf("%s %s %d %d\n", konyvek[i].szerzo, konyvek[i].cim, konyvek[i].kiadasEve, konyvek[i].ar);
    }
}
void kiirKonyvetFileba(char* filenev, Konyv* konyvek, int meret){
    FILE* fp;
    if ((fp = fopen(filenev, "wt")) == NULL){
        printf("A %s file megnyitása sikertelen!", filenev);
        return -1;
    }
    for (int i = 0; i<meret; i++){
        fprintf(fp, "%s %s %d %d\n", konyvek[i].szerzo, konyvek[i].cim, konyvek[i].kiadasEve, konyvek[i].ar);
    }

    fclose(fp);
    return;
}
