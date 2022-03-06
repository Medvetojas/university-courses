#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct{
    int tipp;
} Tipp;

void valasztas(Tipp* jatekos);
void sorsolas(Tipp* gep);
int eldontes(Tipp jatekos, Tipp gep);

int main()
{
    srand(time(NULL));
    char tovabb;
    Tipp jatekos;
    Tipp gep;
    int jatekoswin, gepwin, eredmeny;
    printf("Ko-papir-ollo jatek!\n");

    do{
        valasztas(&jatekos);
        sorsolas(&gep);
        eredmeny = eldontes(jatekos, gep);

        if (eredmeny == 0){
            printf("Dontetlen!\n");
        }else if (eredmeny == 1){
            printf("Te nyertel!\n");
            jatekoswin++;
        }else if (eredmeny == 2){
            printf("A gep nyert!\n");
            gepwin++;
        }

        printf("A jelenlegi eredmeny: %d : %d", jatekoswin, gepwin);
        printf("Akarsz meg jatszani?");
        scanf("%c", &tovabb);
    }while(tovabb == "i" || tovabb == "I");
    return 0;
}

void valasztas(Tipp* jatekos)
{
    printf("Ko, papir, ollo?\n");
    enum tipp {KO, PAPIR, OLLO}; //KO = 0, PAPIR = 1, OLLO = 2
    bool ok;
    do{
        ok = true;
        if(scanf("%d", &(jatekos->tipp)) != 1){
            ok = false;
            printf("Hibas adat!");
            while(getchar() != '\n');
        }else if (jatekos->tipp < 0 || jatekos->tipp > 2){
            ok = false;
            printf("Hibas intervallum!");
            while(getchar() != '\n');
            }
    }while(!ok);
    return;
}

void sorsolas(Tipp* gep)
{
    gep->tipp = rand()%3; //0-2 közötti véletlenszám
    return;
}

int eldontes(Tipp jatekos, Tipp gep)
{
    if(jatekos.tipp == gep.tipp){
        return 0;
    }else if(jatekos.tipp)
}
