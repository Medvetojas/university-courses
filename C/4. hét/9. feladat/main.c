#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 5

int main()
{
    setlocale(LC_ALL, "hun");
	int min, max;
	int ok;
	char ch;
	printf("Add meg az alsóhatárt: "); //alsóhatár
	do{
        ok = 1;
        if(scanf("%d", &min) !=1){
            printf("Rossz bemenet! Próbáld újra: ");
            ok = 0;
            while((ch=getchar()) !='\n');
        }
	} while (!ok);

	printf("Add meg a felsõhatárt: "); //felsõhatár
    do{
        ok = 1;
        if(scanf("%d", &max) !=1){
            printf("Rossz bemenet! Próbáld újra: ");
            ok = 0;
            while((ch=getchar()) !='\n');
        }
        if(max <= min){
            printf("A maximum nagyobb, vagy egyenlõ mint a minimum! Próbáld újra: ");
            ok = 0;
            while((ch=getchar()) !='\n');
        }
	} while (!ok);

	int tomb[N]; //N darab szám beolvasása
	int i;
	for(i=0; i<N; i++){
        printf("Add meg a tömb %d. elemét: ", i+1);
        do{
            ok = 1;
            if(scanf("%d", &tomb[i]) !=1){
                printf("Rossz bemenet! Próbáld újra: ");
                ok = 0;
                while((ch=getchar()) !='\n');
            }
        } while (!ok);
	}

    int correct;
	for(i=0; i<N; i++){ //Hány db szám esik az intervallumba?
        if(tomb[i] < max && tomb[i] > min){
            correct++;
        }
	}

	printf("Az intervallumba esõ számok száma: %d", correct);
    return 0;
}
