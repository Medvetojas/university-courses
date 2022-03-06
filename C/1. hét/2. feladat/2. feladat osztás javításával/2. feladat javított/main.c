#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("2. feladat\n");
    //szamok bekerese
    int a, b;
    printf("Adj meg ket szamot!\n");
    printf("Elso szam: ");
    scanf("%d", &a);
    printf("Masodik szam: ");
    scanf("%d", &b);

    //számolás és kíírás
    printf("Szamitas...\n");
    printf("Osszeadas: %d + %d = %d\n", a, b, a+b);
    printf("Kivonas: %d - %d = %d\n", a, b, a-b);
    printf("Szorzas: %d * %d = %d\n", a, b, a*b);
    if (b == 0){
        printf("Az oszto nem lehet 0, ez nincs ertelmezve.");
        return 1;
    }
    printf("Osztas: %d / %d = %d", a, b, a/b);
    return 0;
}
