#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b;
    printf("Adj meg ket szamot, es a program megadja a szamtani es mertani kozepuket!\n");
    scanf("%lf %lf", &a, &b);
    printf("A szamtani kozep: %.3lf\n", (a+b)/2);
    printf("A mertani kozep: %.3lf", sqrt(a*b));
    return 0;
}
