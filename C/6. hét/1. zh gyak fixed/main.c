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

    //harmadik hónap beolvasása
    int ok;
    char c;
    printf("Add meg a harmadik hónap benzin átlagárát. (350 Ft és 420 Ft között): ");
    do{
        ok = 1;
        if((scanf("%f", &arak[2]))!= 1){
            printf("Nem számot írtál be! Próbáld újra: ");
            ok = 0;
            while((c = getchar()) != '\n');
        } else if(arak[2]<MIN || arak[2]>MAX){
            printf("Nem jó a szám értéke! Próbáld újra: ");
            ok = 0;
            while ((c = getchar()) != '\n');
        }
    }while (!ok);

    //monoton csökkent-e?

    int csokken = 1;
    int i;
    for(i=1;i<=3;i++){
        if(arak[i] > arak[i-1]){
                csokken = 0;
                break;
        }
    }
    if(csokken == 0){
        printf("A benzin átlagára monoton csökkent: nem\n");
    }
    else{
        printf("A benzin átlagára monoton csökkent: igen\n");
    }

    //benzinárak sorozata
    printf("A benzinarak sorozata: %.1f; %.1f; %.1f", arak[0], arak[1]-arak[0], arak[2]-arak[1]);
    return 0;
}
