#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fPointer = fopen("vezeteknev.txt", "w+");
    fprintf(fPointer, "Babik Szil�rd, progremtervez� informatikus alapk�pz�s, A6NQW1");
    fclose(fPointer);
    return 0;
}
