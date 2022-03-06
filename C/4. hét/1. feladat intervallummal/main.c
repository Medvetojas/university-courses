#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "hun");
	int ok, lower, upper;
	char ch;
	do{ //als� intervallum
        ok = 1;
        printf("Add meg az als� hat�rt. (Minimum 1000.)\n");
        if(scanf("%d", &lower)!=1 || lower<1000){
            printf("Hib�s als� hat�r.");
            ok = 0;
            while((ch=getchar())!='\n');
        }
	}while (!ok);
    do{ //fels� intervallum
        ok = 1;
        printf("Add meg a fels� hat�rt (Maximum 3020, �s nagyobb mint az als� hat�r.)\n");
        if(scanf("%d", &upper)!=1 || upper>3020 || upper <= lower){
            printf("Hib�s fels� hat�r.");
            ok = 0;
            while((ch=getchar())!='\n');
        }
    }while (!ok);
    printf("A megadott intervallumod: %d - %d\n", lower, upper); //intervallumok megjelen�t�se

    int szamlalo = 0;

    while (lower <= upper){
        if ( ((lower % 4 == 0) && (lower % 100 !=0)) || (lower % 400==0) ){
            szamlalo++;
            lower++;
        }else{
            lower++;
            continue;
            }
    }
    printf("A megadott intervallumban %d sz�k��v volt.", szamlalo);
    return 0;
}
