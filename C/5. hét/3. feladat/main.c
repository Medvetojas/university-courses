#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define UPPER 100
#define LOWER 1

int main()
{
    setlocale(LC_ALL, "hun");
	printf("Babik Szilárd - gyakorlat_05.pdf - 3. házi feladat\n\n");

	int randomszam, tipp, ok, folytatas;

	srand(time(0)); //random szám generátor inicializálása

	for(;;){
        randomszam = rand()%UPPER+LOWER; //random szám generálás
            do{
                ok = 0;
                printf("Tippeld meg a sorsolt számot, 1 és 100 között: ");
                scanf("%d", &tipp);
                if (tipp == randomszam){ //ha helyesen tippelt, kiléphet vagy folytathatja új számmal
                    printf("Gratulálok, eltaláltad a számot! Szeretnéd folytatni a játékot? 0 - kilépés, 1 - folytatás új számmal: ");
                    scanf("%d", &folytatas);
                        if(folytatas == 1){
                            printf("A játék folytatódik, újonnan generált számmal.\n\n"); //új számmal folytatás
                            ok = 1;
                        } else{ //kilépés a játékból
                            return 0;
                        }
                } else if (tipp < randomszam){ //ha a tippelt szám kisebb mint a random szám
                    printf("Az általad tippelt szám kisebb, mint a sorsolt szám. Próbáld újra!\n\n");
                    continue;
                } else if (tipp > randomszam){ //ha a tippelt szám nagyobb mint a random szám
                    printf("Az általad tippelt szám nagyobb, mint a sorsolt szám. Próbáld újra!\n\n");
                    continue;
                }
            }while (!ok);
    }
    return 0;
}
