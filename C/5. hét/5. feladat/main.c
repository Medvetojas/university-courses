#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MERET 10

    // N�v: Babik Szil�rd Krist�f
    // Neptun k�d: A6NQW1
    // K�sz�lt: 2020.10.15.
    // R�vid le�r�s: A program meg�llap�tja a max. 10 karakteres inputr�l, hogy C azonos�t�-e.

int main()
{
    setlocale(LC_ALL, "hun");
    char ch;
    int i;
    char azonosito[MERET];
    printf("Add meg az ellen�rizni k�v�nt karaktersorozatot: ");
    ch = getchar();
    azonosito[MERET] = ch;

    for(i=0;i<=MERET;i++){
        if(!(azonosito[i] >= 'a' && azonosito[i] <= 'z' || azonosito[i] >= 'A' && azonosito[i] <= 'Z' || azonosito[i] >= '0' && azonosito[i] <= '9' || azonosito[i] == '_')){
            printf("A");
        }
    }
}
