#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define JEGYEK 6

int main()
{

    setlocale(LC_ALL, "hun");
	printf("Babik Szil�rd - gyakorlat_05.pdf 2. h�zi feladata\n");

	int jegyek[JEGYEK];
	int i;
	float osszeg, atlag;
	for(i=0; i<JEGYEK; i++){ //jegyek megad�sa
	    printf("�rd be az %d. vizsgajegyed: ", i+1);
        scanf("%d", &jegyek[i]);
        osszeg = osszeg + jegyek[i];
	}

	atlag = osszeg / JEGYEK; //�tlag sz�m�t�s
	printf("A vizsgajegyek �tlaga = %.1f\n", atlag);

    if(atlag <= 3.5){ //�szt�nd�j �sszeg�nek ki�r�sa
        printf("Az �szt�nd�j �sszege: 0 Ft/h�");
    }else if(atlag >= 3.6 && atlag <= 4.0){
         printf("Az �szt�nd�j �sszege: 5000 Ft/h�");
    }else if (atlag >=4.1 && atlag <= 4.5){
        printf("Az �szt�nd�j �sszege: 10000 Ft/h�");
    }else if (atlag >=4.6){
        printf("Az �szt�nd�j �sszege: 15000 Ft/h�");
    }
    return 0;
}
