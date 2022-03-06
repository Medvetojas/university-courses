#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

typedef int egesz;

typedef int lebegopontos;

typedef struct datum{
    int ev;
    int honap;
    int nap;
} Datum;

typedef struct ember{
    char nev[50];
    Datum szuletett; //felhaszn�lhatok egy m�sik strukt�r�t is egy strukt�r�ban
} Ember;

void beolvasDatum(Datum* d);
void kiirDatum(Datum d);
Datum regebbiDatum(Datum d1, Datum d2);
bool joDatum(Datum d);
bool szokoevE(int ev);
int hanyeves(Ember e);

int main()
{
    setlocale(LC_ALL, "hun");


    egesz i = 10;
    printf("i = %d\n", i); //mert hiszen ez egy eg�sz!
    lebegopontos f = 20;
    printf("f = %d\n", f); //mert hiszen ez is egy eg�sz!


    struct datum d; //el�re megadva a strukt�ra
    d.ev = 2020;
    d.honap = 11;
    d.nap = 19;
    printf("A mai d�tum: %d. %d. %d\n", d.ev, d.honap, d.nap);


    Datum d1;
    beolvasDatum(&d1);
    kiirDatum(d1);
    if(joDatum(d1)){ //rendes if
        printf("\nA d�tum helyes.\n");
    }else{
        printf("\nA d�tum hib�s.\n");
        return 1;
    }

    Datum d2;
    beolvasDatum(&d2);
    kiirDatum(d2);
    printf("\n%s\n", joDatum(d2) ? "A d�tum helyes." : "A d�tum hib�s."); //shorthand if
    if (!joDatum(d2)) return 1; // a returnh�z musz�j az if, teh�t hosszabb lesz


    printf("\nA r�gebbi d�tum: ");
    kiirDatum(regebbiDatum(d, d2));


    Ember en;
    strcpy(en.nev, "Szil�rd"); //en.nev = "Babik"; nem fog m�k�dni, mert �gy nem lehet megadni stringet
    en.szuletett.ev = 2002;
    en.szuletett.honap = 2;
    en.szuletett.nap = 8;
    kiirDatum(en.szuletett);
    printf("%s �letkora: %d", en.nev, hanyeves(en));


    return 0;
}

void beolvasDatum(Datum* d){
    printf("\nAdj meg egy d�tumot!\n");
    printf("�v: ");     scanf("%d", &(d->ev)); //a z�r�jel elhagyhat�, mint a t�bbiben
    printf("H�nap: ");  scanf("%d", &d->honap);
    printf("Nap: ");    scanf("%d", &d->nap);
    return;
}


void kiirDatum(Datum d){ //itt m�r nem kell pointer, mert nem v�ltoztatjuk meg, csak felhaszn�ljuk
    printf("%d. %d. %d.\n", d.ev, d.honap, d.nap);
    return;
}


Datum regebbiDatum(Datum d1, Datum d2){
    if (d1.ev == d2.ev){
        if (d1.honap == d2.honap){
            if (d1.nap < d2. nap){
                return d1;
            }else{
                return d2;
            }
        }else if (d1.honap < d2.honap){
            return d1;
        }else{
            return d2;
        }
    } else if(d1.ev < d2.ev){
        return d1;
    }else{
        return d2;
    }
}


bool joDatum(Datum d){
    int napokSzama[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.ev < 1587 || d.ev > 2040){
        return false;
    }
    if (d.honap < 1 || d.honap > 12){
        return false;
    }
    if(szokoevE(d.ev)){ //sz�k��v vizsg�lat alapj�n a febru�rt �t�ll�tjuk
        napokSzama[2] = 29;
    }
    if (d.nap < 1 || d.nap > napokSzama[d.honap]){ //sz�k��vekre is kalkul�lva
        return false;
    }
    return true; //ha egyik felt�tel sem teljes�l, akkor a d�tum j�
}


bool szokoevE(int ev){
    if(((ev % 4 == 0) && (ev % 100 != 0)) || (ev % 400 == 0)){ //sz�k��v vizsg�lat
        return true;
    }
    return false;
}


int hanyeves(Ember e){
    char ho[4]; //a h�napot 3 bet�vel fogja visszaadni, de kell a z�r�null�nak a hely, ez�rt lesz 4 a m�ret
    int ev, nap;
    sscanf(__DATE__, "%s %d %d", ho, &nap, &ev);
    return ev - e.szuletett.ev;
}
