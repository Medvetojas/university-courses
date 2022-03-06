#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fPointer = fopen("vezeteknev.txt", "w+");
    fprintf(fPointer, "Babik Szilárd, progremtervezõ informatikus alapképzés, A6NQW1");
    fclose(fPointer);
    return 0;
}
