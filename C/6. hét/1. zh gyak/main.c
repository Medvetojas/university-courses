#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MIN 350
#define MAX 420

int main()
{
    setlocale(LC_ALL, "hun");
    float arak[3] = {388.9, 390.3};

    //harmadik hónap beolvasása
    int ok = 1;
    char c;
    do{
        printf("Add meg a harmadik honap benzin atlagarat. (350 Ft és 420 Ft kozott)\n");
        if((scanf("%f", &arak[3]))!= 1 || arak[3]<350 || arak[3]>420){
            printf("Hibas adatok!\n");
            ok = 0;
            while((c = getchar()) != '\n');
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
        printf("A benzin atlagara monoton csokkent: nem\n"); //NEM JÓ A BEOLVASÁS
    }else{
        printf("A benzin atlagara monoton nott: igen\n");
    }

    //benzinárak sorozata
    printf("A benzinarak sorozata: %.1f; %.1f; %.1f;", arak[0], arak[1]-arak[0], arak[2]-arak[1]);
    return 0;
}
