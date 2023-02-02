#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INTERVAL 100000000

double random_double(double min, double max);

int main() {
    int i;
    double circle_points = 0, square_points = 0;
    double x, y, d, pi, time;
    clock_t clock_start, clock_end;

    clock_start = clock();
    for (i = 0; i < INTERVAL; i++) {
        x = random_double(0, 1);
        y = random_double(0, 1);
        d = pow(x, 2) + pow(y, 2);
        if (d <= 1) {
            circle_points++;
        }
        square_points++;
    }
    clock_end = clock();
    pi = 4 * (circle_points / square_points);

    printf("[Estimation of pi with %d points]\n", INTERVAL);
    printf("Estimation of pi = %f\n", pi);
    printf("Value of pi = %f\n", M_PI);
    printf("Error of estimation = %f\n", M_PI - pi);
    time = (double) (clock_end - clock_start) / CLOCKS_PER_SEC;
    printf("Time of computation: %f second(s)", time);
    return 1;
}

double random_double(double min, double max) {
        double part = ((double) rand()) / ((double) RAND_MAX);
        double num = part * (max - min) + min;
        return num;
}