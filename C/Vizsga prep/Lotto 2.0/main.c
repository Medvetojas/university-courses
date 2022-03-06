#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{

    int szamok[5];

} Mezo;

Mezo szambekeres();
int egyezes(Mezo bekertmezo, int nyertesszamok[]);

int main()
{
    FILE *fPointer = fopen("tippeltszamok.txt", "w+");
    int nyertesszamok[5] = {5, 27, 32, 67, 90};
    int i, j;

    Mezo bekertmezo[6];

    for(i=0;i<6;i++){
        printf("%d. mezo:\n", i+1);
        bekertmezo[i] = szambekeres();
    }

    for(i=0;i<6;i++){
        for(j=0;j<5;j++){
            fprintf(fPointer, "%d ", bekertmezo[i].szamok[j]);
        }
        fprintf(fPointer, "\n");
    }

    fclose(fPointer);

    for(i=0;i<6;i++){
            printf("\nA %d. mezonek %d szama egyezik a nyertesszamokkal.", i+1, egyezes(bekertmezo[i], nyertesszamok));
    }


    return 0;
}

Mezo szambekeres()
{
    Mezo bekertmezo;
    int i;
    bool ok;
    for(i=0;i<5;i++){
        do{
            ok = true;
            if(scanf("%d", &bekertmezo.szamok[i]) != 1){
                ok = false;
                while(getchar() != '\n');
                printf("Hibas adat!\n");
            }else if(bekertmezo.szamok[i] < 1 || bekertmezo.szamok[i] > 95){
                ok = false;
                while(getchar() != '\n');
                printf("Hibas intervallum!\n");
            }else if(i != 0){
                if(bekertmezo.szamok[i-1] >= bekertmezo.szamok[i]){
                    ok = false;
                    while(getchar() != '\n');
                    printf("Novekvo sorrendben add meg a szamokat!\n");
                }
            }
        }while(!ok);
    }
    return bekertmezo;
}

int egyezes(Mezo bekertmezo, int nyertesszamok[])
{
    int szamlalo = 0;
    int i, j;
    for(i=0;i<5;i++){
            for(j=0;i<5;i++){
                if(bekertmezo.szamok[i] == nyertesszamok[j]){
                szamlalo++;
            }
        }
    }
    return szamlalo;
}
