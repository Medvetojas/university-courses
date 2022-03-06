#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int szamok[5];
} Tipp;

int beker(Tipp bekertszam);

//void filebairas(Tipp bekertszam);

int main()
{
    FILE *fp = fopen("kimenet.txt", "w");
    if(fp == NULL){
        printf("Sikertelen fajlmegnyitas!");
        return 0;
    }

    int nyertesszamok[5] = {5, 27, 32, 67, 90};

    int i;
    Tipp bekertszamok[6];
    for(i=0;i<=5;i++){
        printf("%d. tippsorozat:\n", i+1);
        bekertszamok[i] = beker(bekertszamok[i]);
    }

//    void filebairas(Tipp bekertszamok, FILE* fp);

    return 0;
}

int beker(Tipp bekertszam)
{
    int i;
    for(i=0;i<=4;i++){
        bool ok = false;
        while(!ok){
            ok = true;
            if(scanf("%d", &bekertszam.szamok[i]) != 1){
               printf("Hibas adat!");
               while(getchar() != '\n');
               ok = false;
            }else if(bekertszam.szamok[i]<1 || bekertszam.szamok[i]>95){
               printf("Rossz intervallum!");
               while(getchar() != '\n');
               ok = false;
            }else if(i!=0){
                if(bekertszam.szamok[i] <= bekertszam.szamok[i-1]){
                    printf("Kisebb szamot adtal meg az elozonel!");
                    while(getchar() != '\n');
                    ok = false;
                }
            }
        }
    }
    return bekertszam;
}




/*void filebairas(Tipp bekertszam, FILE *fp)
{

    int i, j;
    for(i=0; i<=5; i++){
        for(j=0; j<=4; i++){
            fprintf(fp, "%d ", bekertszam)
        }
    }
}*/
