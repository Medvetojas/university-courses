#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MERET 10

    // Név: Babik Szilárd Kristóf
    // Neptun kód: A6NQW1
    // Készült: 2020.10.15.
    // Rövid leírás: A program megállapítja a max. 10 karakteres inputról, hogy C azonosító-e.

int main()
{
    setlocale(LC_ALL, "hun");
    char ch;
    int i;
    char azonosito[MERET];
    printf("Add meg az ellenõrizni kívánt karaktersorozatot: ");
    ch = getchar();
    azonosito[MERET] = ch;

    for(i=0;i<=MERET;i++){
        if(!(azonosito[i] >= 'a' && azonosito[i] <= 'z' || azonosito[i] >= 'A' && azonosito[i] <= 'Z' || azonosito[i] >= '0' && azonosito[i] <= '9' || azonosito[i] == '_')){
            printf("A");
        }
    }
}
