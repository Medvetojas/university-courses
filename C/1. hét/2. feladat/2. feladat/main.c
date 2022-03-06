#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("2. feladat\n");
    //szamok bekerese
    int a, b, osszeadas, kivonas, szorzas, osztas;
    printf("Adj meg ket szamot!\n");
    printf("Elso szam: ");
    scanf("%d", &a);
    printf("Masodik szam: ");
    scanf("%d", &b);

    //muveletek elvegzese
    osszeadas = a+b;
    kivonas = a-b;
    szorzas = a*b;
    osztas = a/b;

    printf("Osszeadas: %d + %d = %d\n", a, b, osszeadas);
    printf("Kivonas: %d - %d = %d\n", a, b, kivonas);
    printf("Szorzas: %d * %d = %d\n", a, b, szorzas);
    printf("Osztas: %d / %d = %d\n", a, b, osztas);

    printf("Feladat vege!");
    return 0;
}
