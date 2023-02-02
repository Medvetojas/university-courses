#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

    // 2. feladat
    printf("2. feladat\n");
    int number = 10;
    printf("%08d\n", number);

    //3. feladat
    printf("3. feladat\n");
    printf("A kod masodpercenkent kiirja az i emelkedo ertekeit.\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", i);
        sleep(1);
    }

    //4. feladat
    printf("4. feladat\n");
    printf("Random szam kiirasa 500 es 1000 kozott\n");
    srand(time(NULL));
    int randomNumber = rand() % ((1000 + 1) - 500) + 500;
    printf("%d\n", randomNumber);

    //5. feladat
    printf("5. feladat\n");
    printf("Bemeneti argumentumkent kapott szam kozott general random szamokat\n");
    int randomNumber2 = rand() % ((atoi(argv[2]) + 1) - atoi(argv[1])) + atoi(argv[1]);
    printf("%d\n", randomNumber2);

    //6. feladat
    printf("6. feladat\n");
    

    return 0;
}


