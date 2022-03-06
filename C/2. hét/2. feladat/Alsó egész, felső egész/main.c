#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("2. feladat!\n");
    double a;
    printf("Adj meg egy barmilyen valos szamot:");
    if (scanf("%lf", &a) == 1) {
        printf("Alsoegesz: %.1lf\n", ceil(a));
        printf("Felsoegesz: %.1lf\n", floor(a));
    }
    else {
        printf("Elbasztad...!\n");
    }

    return 0;
}
