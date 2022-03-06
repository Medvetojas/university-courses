#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float tti(float magassag, float tomeg);
void rendezes(float* index, int meret);
void csere(float* a, float* b);
void kiiras(float index);
void ellenorzottbeolvasas(int* min, int* max);
int hanygyerek(int min, int max, float* index, int meret);


int main()
{
    int i;
    float magassag[5] = {1.20, 1.16, 1.52, 1.18, 1.34};
    float tomeg[5] =  {38, 30, 45, 42, 44};
    float index[5];

    printf("A TTI-k sorban: ");
    for(i=0; i<=4; i++){
        index[i] = tti(magassag[i], tomeg[i]);
        printf("%f, ", index[i]);
    }


    printf("\nTTI rendezese csokkenoen, novekvoen kivalaszto rendezessel:\n");
    rendezes(index, 5);
    for(i=0;i<5;i++){
        kiiras(index[i]);
    }

    int min, max;
    ellenorzottbeolvasas(&min,&max);

    printf("A %d-%d intervallumba %d gyerek esik.", min, max, hanygyerek(min, max, index, 5));

    return 0;
}

float tti(float magassag, float tomeg)
{
    return tomeg / (magassag*magassag);
}

void rendezes(float* index, int meret)
{
    int i, j;
    int min = 0;
    for(i=0;i<meret;i++){
        min = i;
        for(j=i+1;j<meret;j++){
            if(index[j] < index[min]){
                min = j;
            }
    }
        csere(&index[i], &index[min]);
    }
    return;
}

void csere(float* a, float* b)
{
        float seged;
        seged = *a;
        *a = *b;
        *b = seged;
        return;
}

void kiiras(float index)
{
    printf("%f\n", index);
    return;
}

void ellenorzottbeolvasas(int* min, int* max)
{
    bool ok;
    printf("Adj meg egy minimum erteket 15 es 45 kozott: ");
    do{
        ok = true;
        if(scanf("%d", min) != 1){
            ok = false;
            printf("Hibas input! Add meg ujra a mint:");
            while(getchar() != '\n');
        }else if(*min < 15 || *min >= 45){
            ok = false;
            printf("Rossz intervallum! Add meg ujra a mint: ");
            while(getchar() != '\n');
            }
        }while (!ok);

    printf("Adj meg egy maximum erteket 15 es 45 kozott, ami nagyobb mint a min: ");
    do{
        ok = true;
        if(scanf("%d", max) != 1){
            ok = false;
            printf("Hibas input! Add meg ujra a maxot: ");
            while(getchar() != '\n');
        }else if(*max < 15 || *max > 45 || *min > *max){
            ok = false;
            printf("Rossz intervallum! Add meg ujra a maxot: ");
            while(getchar() != '\n');
            }
        }while (!ok);

    return;
}

int hanygyerek(int min, int max, float* index, int meret)
{
    int i, szamlalo = 0;
    for(i=0;i<meret;i++){
        if(index[i] < max && index[i] > min){
            szamlalo++;
        }
    }
    return szamlalo;
}
