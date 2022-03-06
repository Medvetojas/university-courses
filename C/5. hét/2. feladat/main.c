#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define JEGYEK 6

int main()
{

    setlocale(LC_ALL, "hun");
	printf("Babik Szilárd - gyakorlat_05.pdf 2. házi feladata\n");

	int jegyek[JEGYEK];
	int i;
	float osszeg, atlag;
	for(i=0; i<JEGYEK; i++){ //jegyek megadása
	    printf("Írd be az %d. vizsgajegyed: ", i+1);
        scanf("%d", &jegyek[i]);
        osszeg = osszeg + jegyek[i];
	}

	atlag = osszeg / JEGYEK; //átlag számítás
	printf("A vizsgajegyek átlaga = %.1f\n", atlag);

    if(atlag <= 3.5){ //ösztöndíj összegének kiírása
        printf("Az ösztöndíj összege: 0 Ft/hó");
    }else if(atlag >= 3.6 && atlag <= 4.0){
         printf("Az ösztöndíj összege: 5000 Ft/hó");
    }else if (atlag >=4.1 && atlag <= 4.5){
        printf("Az ösztöndíj összege: 10000 Ft/hó");
    }else if (atlag >=4.6){
        printf("Az ösztöndíj összege: 15000 Ft/hó");
    }
    return 0;
}
