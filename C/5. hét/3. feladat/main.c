#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define UPPER 100
#define LOWER 1

int main()
{
    setlocale(LC_ALL, "hun");
	printf("Babik Szil�rd - gyakorlat_05.pdf - 3. h�zi feladat\n\n");

	int randomszam, tipp, ok, folytatas;

	srand(time(0)); //random sz�m gener�tor inicializ�l�sa

	for(;;){
        randomszam = rand()%UPPER+LOWER; //random sz�m gener�l�s
            do{
                ok = 0;
                printf("Tippeld meg a sorsolt sz�mot, 1 �s 100 k�z�tt: ");
                scanf("%d", &tipp);
                if (tipp == randomszam){ //ha helyesen tippelt, kil�phet vagy folytathatja �j sz�mmal
                    printf("Gratul�lok, eltal�ltad a sz�mot! Szeretn�d folytatni a j�t�kot? 0 - kil�p�s, 1 - folytat�s �j sz�mmal: ");
                    scanf("%d", &folytatas);
                        if(folytatas == 1){
                            printf("A j�t�k folytat�dik, �jonnan gener�lt sz�mmal.\n\n"); //�j sz�mmal folytat�s
                            ok = 1;
                        } else{ //kil�p�s a j�t�kb�l
                            return 0;
                        }
                } else if (tipp < randomszam){ //ha a tippelt sz�m kisebb mint a random sz�m
                    printf("Az �ltalad tippelt sz�m kisebb, mint a sorsolt sz�m. Pr�b�ld �jra!\n\n");
                    continue;
                } else if (tipp > randomszam){ //ha a tippelt sz�m nagyobb mint a random sz�m
                    printf("Az �ltalad tippelt sz�m nagyobb, mint a sorsolt sz�m. Pr�b�ld �jra!\n\n");
                    continue;
                }
            }while (!ok);
    }
    return 0;
}
