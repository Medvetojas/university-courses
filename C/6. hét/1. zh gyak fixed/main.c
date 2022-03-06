#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MIN 350
#define MAX 420
#define HONAPOK 3

int main()
{
    setlocale(LC_ALL, "hun");
    float arak[HONAPOK] = {388.9, 390.3};

    //harmadik h�nap beolvas�sa
    int ok;
    char c;
    printf("Add meg a harmadik h�nap benzin �tlag�r�t. (350 Ft �s 420 Ft k�z�tt): ");
    do{
        ok = 1;
        if((scanf("%f", &arak[2]))!= 1){
            printf("Nem sz�mot �rt�l be! Pr�b�ld �jra: ");
            ok = 0;
            while((c = getchar()) != '\n');
        } else if(arak[2]<MIN || arak[2]>MAX){
            printf("Nem j� a sz�m �rt�ke! Pr�b�ld �jra: ");
            ok = 0;
            while ((c = getchar()) != '\n');
        }
    }while (!ok);

    //monoton cs�kkent-e?

    int csokken = 1;
    int i;
    for(i=1;i<=3;i++){
        if(arak[i] > arak[i-1]){
                csokken = 0;
                break;
        }
    }
    if(csokken == 0){
        printf("A benzin �tlag�ra monoton cs�kkent: nem\n");
    }
    else{
        printf("A benzin �tlag�ra monoton cs�kkent: igen\n");
    }

    //benzin�rak sorozata
    printf("A benzinarak sorozata: %.1f; %.1f; %.1f", arak[0], arak[1]-arak[0], arak[2]-arak[1]);
    return 0;
}
