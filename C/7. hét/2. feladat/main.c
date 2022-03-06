#include <stdio.h>
#include <stdlib.h>

int beolvasas();
int szamjegyosszeg(int szam, int maradek, int osszeg);

int main()
{
	int szam, maradek, osszeg = 0;

	szam = beolvasas();

	osszeg = szamjegyosszeg(szam, maradek, osszeg);

	printf("A szamjegyek osszege: %d", osszeg);

    return 0;
}

int beolvasas(){
    int beolvasottszam, ok;
    char ch;
    printf("Add meg a szamot: ");
    do{
        ok = 1;
        if(scanf("%d", &beolvasottszam) != 1){
            printf("Hibás beolvasás, próbáld újra: ");
            ok = 0;
            while((ch=getchar()) != '\n');
        }

    }while (!ok);
    return beolvasottszam;
}

int szamjegyosszeg(int szam, int maradek, int osszeg){
    while(szam != 0){
        maradek = szam % 10;
        osszeg += maradek;
        szam = szam / 10;
    }
    return osszeg;
}
