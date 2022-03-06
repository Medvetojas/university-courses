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
    Datum szuletett; //felhasználhatok egy másik struktúrát is egy struktúrában
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
    printf("i = %d\n", i); //mert hiszen ez egy egész!
    lebegopontos f = 20;
    printf("f = %d\n", f); //mert hiszen ez is egy egész!


    struct datum d; //elõre megadva a struktúra
    d.ev = 2020;
    d.honap = 11;
    d.nap = 19;
    printf("A mai dátum: %d. %d. %d\n", d.ev, d.honap, d.nap);


    Datum d1;
    beolvasDatum(&d1);
    kiirDatum(d1);
    if(joDatum(d1)){ //rendes if
        printf("\nA dátum helyes.\n");
    }else{
        printf("\nA dátum hibás.\n");
        return 1;
    }

    Datum d2;
    beolvasDatum(&d2);
    kiirDatum(d2);
    printf("\n%s\n", joDatum(d2) ? "A dátum helyes." : "A dátum hibás."); //shorthand if
    if (!joDatum(d2)) return 1; // a returnhöz muszáj az if, tehát hosszabb lesz


    printf("\nA régebbi dátum: ");
    kiirDatum(regebbiDatum(d, d2));


    Ember en;
    strcpy(en.nev, "Szilárd"); //en.nev = "Babik"; nem fog mûködni, mert így nem lehet megadni stringet
    en.szuletett.ev = 2002;
    en.szuletett.honap = 2;
    en.szuletett.nap = 8;
    kiirDatum(en.szuletett);
    printf("%s életkora: %d", en.nev, hanyeves(en));


    return 0;
}

void beolvasDatum(Datum* d){
    printf("\nAdj meg egy dátumot!\n");
    printf("Év: ");     scanf("%d", &(d->ev)); //a zárójel elhagyható, mint a többiben
    printf("Hónap: ");  scanf("%d", &d->honap);
    printf("Nap: ");    scanf("%d", &d->nap);
    return;
}


void kiirDatum(Datum d){ //itt már nem kell pointer, mert nem változtatjuk meg, csak felhasználjuk
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
    if(szokoevE(d.ev)){ //szökõév vizsgálat alapján a februárt átállítjuk
        napokSzama[2] = 29;
    }
    if (d.nap < 1 || d.nap > napokSzama[d.honap]){ //szökõévekre is kalkulálva
        return false;
    }
    return true; //ha egyik feltétel sem teljesül, akkor a dátum jó
}


bool szokoevE(int ev){
    if(((ev % 4 == 0) && (ev % 100 != 0)) || (ev % 400 == 0)){ //szökõév vizsgálat
        return true;
    }
    return false;
}


int hanyeves(Ember e){
    char ho[4]; //a hónapot 3 betûvel fogja visszaadni, de kell a zárónullának a hely, ezért lesz 4 a méret
    int ev, nap;
    sscanf(__DATE__, "%s %d %d", ho, &nap, &ev);
    return ev - e.szuletett.ev;
}
