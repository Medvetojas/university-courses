#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum{GEIK, MFK, MAK, AJK, GTK, BTK, EGK, BZI} kar_tipus;

typedef struct{
    char nev[30];
    kar_tipus kar;
    int munkakezd;
    int fizetes;
} Alkalmazott;

Alkalmazott beolvas(Alkalmazott * beolvasott);


int main()
{
    Alkalmazott tanar;
    beolvas(&tanar);
    return 0;
}

Alkalmazott beolvas(Alkalmazott * beolvasott)
{
    int i;
    bool ok1, ok2, ok3, ok4;

    printf("Add meg a nevet:");
    do{
        ok1 = true;
        if(scanf("%s", &beolvasott->nev) != 1){
            ok1 = false;
            while(getchar() != '\n');
            printf("Hibas nev! Add meg ujra:");
        }
    }while(!ok1);

    printf("Add meg a kart:");
    do{
        ok2 = true;
        if(scanf("%s", &beolvasott->kar) != 1){
            ok2 = false;
            while(getchar() != '\n');
            printf("Hibas kar! Add meg ujra:");
        }
    }while(!ok2);

    printf("Add meg a munkarendet:");
    do{
        ok3 = true;
        if(scanf("%d", &beolvasott->munkakezd) != 1){
            ok3 = false;
            while(getchar() != '\n');
            printf("Hibas munkarend! Add meg ujra:");
        }
    }while(!ok3);

    printf("Add meg a fizetest:");
    do{
        ok4 = true;
        if(scanf("%d", &beolvasott->fizetes) != 1){
            ok4 = false;
            while(getchar() != '\n');
            printf("Hibas nev! Add meg ujra:");
        }
    }while(!ok4);
    return *beolvasott;
}
