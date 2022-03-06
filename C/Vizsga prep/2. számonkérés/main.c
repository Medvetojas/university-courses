/*Írjon C programot saját függvények és a top-down programfejlesztési technika alkalmazásával.
Keresse meg 10 és N között az összes relatív prím számpárt. N 10-nél nagyobb egész szám, amit
ellenőrzötten olvasson be. A megtalált számpárokat írja ki a képernyőre.
Két szám egymáshoz képest relatív prím, ha legnagyobb közös osztójuk 1. A feladat megoldása
során használja fel az euklidészi LNKO algoritmust:

Be: a, b
Amíg b>0
segéd ← b
b ← a/b maradéka
a ← segéd
Ciklus vége
lnko ← a
Ki: lnko

Tesztadatok:
N = 15

Eredmény:
(10,11) ; (10,13) ; (11,12) ; (11,13) ; (11,14) ; (11,15) ; (12,13) ; (13,14) ; (13,15); (14,15)*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lnko (int a, int b);

int main()
{

    int a=10, b, N, elenkao;
    bool ok;
    do{ //ellenorzott szambekeres
        ok = true;
        printf("Az 1. szam %d. Add meg a masodik szamot: ", a);
        if(scanf("%d", &N) != 1){
            printf("Hibas beolvasas!\n");
            ok = false;
            while(getchar() != '\n');
        }
        else if(N < 10){
            printf("A masodik szamnak nagyobbnak kell lennie, mint %d!\n", a);
            ok = false;
            while(getchar() != '\n');
        }
    }while(!ok);

    for(a=10;a<=N-1;a++){
        for(b=a+1;b<=N;b++){
            elenkao = lnko(a, b); //lnko kiszamitasa
            if (elenkao == 1){
            printf("(%d,%d) ; ", a, b);
            }
        }
    }
    return 0;
}

int lnko (int a, int b){
    int seged;
    while(b>0){
        seged = b;
        b = a%b;
        a = seged;
    }
    return a;
}
