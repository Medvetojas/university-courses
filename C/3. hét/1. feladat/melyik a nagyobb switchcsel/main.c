#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Adj meg ket szamot, es a program megmondja melyik a nagyobb (switchcsel)\n");
    scanf("%d %d", &a, &b);
    switch(a < b){
        case 0: printf("Az elso szam nagyobb, mint a masodik."); break;
        case 1: printf("A masodik szam nagyobb, mint az elso."); break;
    }
    return 0;
}
