#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, hanyados, maradek;
    printf("Adj meg ket szamot:");
    scanf("%lf", &a);
    scanf("%lf", &b);
    hanyados = a / b;
    maradek = fmod(a, b);
    printf("Az osztas: %lf / %lf = %.1lf, maradek a(z) %.1lf", a, b, hanyados, maradek);
    return 0;
}
