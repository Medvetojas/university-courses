#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#define INTERVAL 10000000

double random_double(double min, double max);

void MonteCarlo_test();

void Leibniz_test();

void Riemann_test();

void Wallis_test();

void evaluate_results(float est, double time);

clock_t clock_start, clock_end;

int main() {
    printf("~Convergence test with Monte Carlo's method~\n");
    MonteCarlo_test();
    printf("~Convergence test with Leibniz's method~\n");
    Leibniz_test();
    printf("~Convergence test with Riemann's method~\n");
    Riemann_test();
    printf("~Convergence test with Wallis' method~\n");
    Wallis_test();
    return 1;
}

double random_double(double min, double max) {
    if (min >= max) {
        double temp = min;
        min = max;
        max = temp;
    } else {
        double part = ((double) rand()) / ((double) RAND_MAX);
        double num = part * (max - min) + min;
        return num;
    }
}

void Wallis_test() {
    int i;
    double pi = 1;
    double time;
    clock_start = clock();
#pragma omp parallel for reduction(*:pi)
    for (i = 1; i < INTERVAL; i++) {
        pi *= (4.0 * pow(i, 2)) / ((4.0 * pow(i, 2)) - 1.0);
    }
    pi *= 2;
    clock_end = clock();
    time = (double) (clock_end - clock_start) / CLOCKS_PER_SEC;
    evaluate_results(pi, time);
}

void Riemann_test() {
    double time;

    double delta_x = 1 / (double) INTERVAL;
    double x = 0;
    double pi = 0;
    clock_start = clock();
    while (x < 1) {
        double f_x = sqrt(1 - pow(x, 2));
        pi += f_x * delta_x;
        x += delta_x;
    }
    pi = 4 * pi;
    clock_end = clock();
    time = (double) (clock_end - clock_start) / CLOCKS_PER_SEC;
    evaluate_results(pi, time);
}

void Leibniz_test() {
    double time;

    int i;
    double pi = 1.0;
    double devider = 3;

    clock_start = clock();
#pragma omp parallel for
    for (i = 0; i < INTERVAL; i++) {
        if (i % 2) {
            pi += 1 / devider;
        } else {
            pi -= 1 / devider;
        }
        devider += 2;
    }
    pi *= 4;
    clock_end = clock();
    time = (double) (clock_end - clock_start) / CLOCKS_PER_SEC;
    evaluate_results(pi, time);
}


void MonteCarlo_test() {
    double time;
    int i;
    double circle_points = 0;
    double square_points = 0;
    double x, y, d, pi,

            clock_start = clock();
#pragma omp parallel for private(x, y, d)
    for (i = 0; i < INTERVAL; i++) {
        x = random_double(0, 1);
        y = random_double(0, 1);
        d = pow(x, 2) + pow(y, 2);
        if (d <= 1) {
            circle_points++;
        }
        square_points++;
    }
    pi = 4 * (circle_points / square_points);
    clock_end = clock();
    time = (double) (clock_end - clock_start) / CLOCKS_PER_SEC;
    evaluate_results(pi, time);
}

void evaluate_results(float est, double time) {
    printf("[Estimation of pi with %d samples]\n", INTERVAL);
    printf("Estimation of pi = %f\n", est);
    printf("Value of pi = %f\n", M_PI);
    printf("Error of estimation = %f\n", fabs(M_PI - est));
    printf("Time of computation: %f second(s)\n\n", time);
}

double fact(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (n * fact(n - 1));
    }
}
