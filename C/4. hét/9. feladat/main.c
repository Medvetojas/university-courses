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
	printf("Add meg az als�hat�rt: "); //als�hat�r
	do{
        ok = 1;
        if(scanf("%d", &min) !=1){
            printf("Rossz bemenet! Pr�b�ld �jra: ");
            ok = 0;
            while((ch=getchar()) !='\n');
        }
	} while (!ok);

	printf("Add meg a fels�hat�rt: "); //fels�hat�r
    do{
        ok = 1;
        if(scanf("%d", &max) !=1){
            printf("Rossz bemenet! Pr�b�ld �jra: ");
            ok = 0;
            while((ch=getchar()) !='\n');
        }
        if(max <= min){
            printf("A maximum nagyobb, vagy egyenl� mint a minimum! Pr�b�ld �jra: ");
            ok = 0;
            while((ch=getchar()) !='\n');
        }
	} while (!ok);

	int tomb[N]; //N darab sz�m beolvas�sa
	int i;
	for(i=0; i<N; i++){
        printf("Add meg a t�mb %d. elem�t: ", i+1);
        do{
            ok = 1;
            if(scanf("%d", &tomb[i]) !=1){
                printf("Rossz bemenet! Pr�b�ld �jra: ");
                ok = 0;
                while((ch=getchar()) !='\n');
            }
        } while (!ok);
	}

    int correct;
	for(i=0; i<N; i++){ //H�ny db sz�m esik az intervallumba?
        if(tomb[i] < max && tomb[i] > min){
            correct++;
        }
	}

	printf("Az intervallumba es� sz�mok sz�ma: %d", correct);
    return 0;
}
