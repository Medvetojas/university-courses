#include <stdio.h>
#include <stdlib.h>

typedef struct datum{
    int ev;
    int honap;
    int nap;
} Datum;

void beolvasDatum(Datum* d);
int hanyadiknap(Datum d);
void beolvasEvNap(Datum* d);
void melyiknap(Datum d);

int main()
{
    Datum d1;
    printf("A program eloszor kiszamitja egy datumrol, hogy hanyadik napja az evnek.\n");
    beolvasDatum(&d1);
    printf("A megadott datum az ev %d. napja.\n", hanyadiknap(d1));

    Datum d2;
    printf("Most pedig forditva: a program visszaadja az ev napja alapjan a datumot.\n");
    beolvasEvNap(&d2);
    melyiknap(d2);
    return 0;
}

void beolvasDatum(Datum* d){
    printf("Add meg a datumot, pl: '2002. 2. 8.': ");
    scanf("%d. %d. %d.", &d->ev, &d->honap, &d->nap);
    return;
}

int hanyadiknap(Datum d){
    int napokSzama[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(((d.ev % 4 == 0) && (d.ev % 100 != 0)) || (d.ev % 400 == 0)){ //szökõév vizsgálat
        napokSzama[2] = 29;
    }
    int i;
    int evnapja = 0;
    for(i=1; i<d.honap; i++){
        evnapja += napokSzama[i];
    }
    evnapja += d.nap;
    return evnapja;
}

void beolvasEvNap(Datum* d){
    printf("Add meg az evet:");
    scanf("%d", &d->ev);
    printf("Add meg a napot:");
    scanf("%d", &d->nap);
    return;
}

void melyiknap(Datum d){
    int februarinapok = 28;
    if(((d.ev % 4 == 0) && (d.ev % 100 != 0)) || (d.ev % 400 == 0)){ //szökõév vizsgálat
        februarinapok = 29;
    }

    if(d.nap>0 && d.nap<=31){
        printf("Januar %d.", d.nap);
    }
    else if(d.nap>31 && d.nap<=31+februarinapok){
        printf("Februar %d.", d.nap-31);
    }
    else if(d.nap>31+februarinapok && d.nap<=31+februarinapok+31){
        printf("Marcius %d.", d.nap-31-februarinapok);
    }
    else if(d.nap>31+februarinapok+31 && d.nap<=31+februarinapok+31+30){
        printf("Aprilis %d.", d.nap-31-februarinapok-31);
    }
    else if(d.nap>31+februarinapok+31+30 && d.nap<=31+februarinapok+31+30+31){
        printf("Majus %d.", d.nap-31-februarinapok-31-30);
    }
    else if(d.nap>31+februarinapok+31+30+31 && d.nap<=31+februarinapok+31+30+31+30){
        printf("Junius %d.", d.nap-31-februarinapok-31-30-31);
    }
    else if(d.nap>31+februarinapok+31+30+31+30 && d.nap<=31+februarinapok+31+30+31+30+31){
        printf("Julius %d.", d.nap-31-februarinapok-31-30-31-30);
    }
    else if(d.nap>31+februarinapok+31+30+31+30+31 && d.nap<=31+februarinapok+31+30+31+30+31+30){
        printf("Augusztus %d.", d.nap-31-februarinapok-31-30-31-30-31);
    }
    else if(d.nap>31+februarinapok+31+30+31+30+31+30 && d.nap<=31+februarinapok+31+30+31+30+31+30+31){
        printf("Szeptember %d.", d.nap-31-februarinapok-31-30-31-30-31-30);
    }
    else if(d.nap>31+februarinapok+31+30+31+30+31+30+31 && d.nap<=31+februarinapok+31+30+31+30+31+30+31+30){
        printf("Oktober %d.", d.nap-31-februarinapok-31-30-31-30-31-30-31);
    }
    else if(d.nap>31+februarinapok+31+30+31+30+31+30+31+30 && d.nap<=31+februarinapok+31+30+31+30+31+30+31+30+31){
        printf("November %d.", d.nap-31-februarinapok-31-30-31-30-31-30-31-30);
    }
    else if(d.nap>30+februarinapok+31+30+31+30+31+30+31+30+31 && d.nap<=31+februarinapok+31+30+31+30+31+30+31+30+31+30){
        printf("December %d.", d.nap-31-februarinapok-31-30-31-30-31-30-31-30-31);
    }
    else{
        printf("Hibas szamot adtal meg!");
    }

    return;
}
