#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ARRAY_LENGTH 3

void sequential_Multiplication(double pDouble[ARRAY_LENGTH]);
void openmp_Reduction_Multiplication(double pDouble[ARRAY_LENGTH]);
void openmp_For_Multiplication(double pDouble[ARRAY_LENGTH]);

int main() {
    srand(time(NULL));

    double randArray[ARRAY_LENGTH];

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        randArray[i] = (float)rand()/(float)(1000);
    }

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%f\n", randArray[i]);
    }

    sequential_Multiplication(randArray);
    openmp_Reduction_Multiplication(randArray);
    openmp_For_Multiplication(randArray);
    return 0;
}

void openmp_Reduction_Multiplication(double pDouble[ARRAY_LENGTH]) {
    double result = 1;
    #pragma omp parallel for reduction(*:result)
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        result *= pDouble[i];
    }
    printf("OpenMP Reduction multiplication result: %f\n", result);
}

void sequential_Multiplication(double pDouble[ARRAY_LENGTH]) {
    double result = 1;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        result *= pDouble[i];
    }
    printf("Sequential multiplication result: %f\n", result);
}

void openmp_For_Multiplication(double pDouble[ARRAY_LENGTH]){
    double result = 1;
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        result *= pDouble[i];
    }
    printf("OpenMP For multiplication result: %f\n", result);
}