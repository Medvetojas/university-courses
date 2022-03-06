#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, i;
    int fakt = 1;
    printf("Adj meg egy szamot 0 es 10 kozott, es a program kiszamitja a faktorialist!\n");
    scanf("%d", &a);
    while (a < 0 || a > 10){
        printf("Nem 0 es 10 kozotti szamot adtal meg, legkozelebb adj meg egy helyes szabot!");
        return 0;
    }
    for (i = 1; i <= a; ++i) {
        fakt *= i;
    }
    printf("A %d faktorialisa = %d", a, fakt);
    return 0;
}
