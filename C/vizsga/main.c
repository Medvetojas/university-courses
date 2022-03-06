#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void konvert(float Celsius[]);
void ellenorzott(int* min, int* max);
float elteres(float Celsius[]);

int main()
{
    float Celsius[] = {10.1, 13.2, 14.0, 13.5, 13.3};
    konvert(Celsius);

    int i;
    FILE *fPointer = fopen("szamsor.txt", "w+");
    for(i=0;i<=4;i++){
        fprintf(fPointer, "%f K\n", Celsius[i]);
    }
    fclose(fPointer);

    int min, max;
    ellenorzott(&min, &max);

    printf("Az elteres: %f", elteres(Celsius));

    return 0;

}

void konvert(float Celsius[])
{
    int i;
    for (i=0;i<=4;i++){
        Celsius[i] = Celsius[i] + 273.13;
    }
    return;
}

void ellenorzott(int* min, int* max)
{
    bool ok;
    do{
        ok = true;
        if(scanf("%d", &min) != 1){
            ok = false;
            printf("\nHibas min intervallum! ");
            while(getchar() != '\n');
        }
    }while(!ok);


    do{
       ok = true;
        if(scanf("%d", &max) != 1){
            ok = false;
            printf("\nHibas max intervallum! ");
            while(getchar() != '\n');
            }else if(min >= max){
            ok = false;
            printf("\nMin nagyobb mint a max! ");
            while(getchar() != '\n');
            }
        }while(!ok);

    return;
}

float elteres(float Celsius[])
{
    int i;
    float min = Celsius[0];
    float max = 0;

    for (i=0; i<=4; i++){
        if (Celsius[i] < min){
            min = Celsius[i];
        }
        if (Celsius[i] > max){
            max = Celsius[i];
        }
    }

    float elteres;
    elteres = max - min;
    return elteres;
}
