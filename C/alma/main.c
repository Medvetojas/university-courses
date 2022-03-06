#include <stdio.h>
#include <stdlib.h>

void beolvas(FILE * fP);
void kiiras(FILE * fP);

int main()
{
    FILE * fPointer;
    fPointer = NULL;
    beolvas(fPointer);
    kiiras(fPointer);
    fclose(fPointer);
    return 0;
}

void beolvas(FILE * fP)
{
    fP = fopen("alma.txt", "w");
    fprintf(fP, "Szeretem az almat, mert finom!");
    fclose(fP);
    return;
}

void kiiras(FILE * fP)
{
    fP = fopen("alma.txt", "r");
    char * line;
    line = (char*) malloc(100 * sizeof(char));
    while(!feof(fP)){
        fgets(line, 100, fP);
        puts(line);
    }
    free(line);
    return;
}
