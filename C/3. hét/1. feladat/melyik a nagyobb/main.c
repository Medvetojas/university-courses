#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Adj meg ket szamot, es a program megmondja, melyik a nagyobb\n");
    scanf("%d %d", &a, &b);
    if (a == b){
        printf("A ket szam egyenlo.");
    }
    else if (a > b){
        printf("Az elso szam nagyobb, mint a masodik.");
    }
    else{
        printf("A masodik szam nagyobb, mint az elso.");
    }
    return 0;
}
