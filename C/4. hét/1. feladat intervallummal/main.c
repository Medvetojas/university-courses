#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "hun");
	int ok, lower, upper;
	char ch;
	do{ //alsó intervallum
        ok = 1;
        printf("Add meg az alsó határt. (Minimum 1000.)\n");
        if(scanf("%d", &lower)!=1 || lower<1000){
            printf("Hibás alsó határ.");
            ok = 0;
            while((ch=getchar())!='\n');
        }
	}while (!ok);
    do{ //felsõ intervallum
        ok = 1;
        printf("Add meg a felsõ határt (Maximum 3020, és nagyobb mint az alsó határ.)\n");
        if(scanf("%d", &upper)!=1 || upper>3020 || upper <= lower){
            printf("Hibás felsõ határ.");
            ok = 0;
            while((ch=getchar())!='\n');
        }
    }while (!ok);
    printf("A megadott intervallumod: %d - %d\n", lower, upper); //intervallumok megjelenítése

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
    printf("A megadott intervallumban %d szökõév volt.", szamlalo);
    return 0;
}
