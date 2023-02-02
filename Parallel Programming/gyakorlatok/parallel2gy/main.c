#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum_of_array(const int arr[], int n);
int max_of_array(const int arr[], int n);
int min_of_array(const int arr[], int n);

int main() {
    printf("Hello, World!\n");

    int arr[5] = {1,2,3,4,5};
    clock_t tic = clock();
    printf("Sum of array is %d\n", sum_of_array(arr, sizeof(arr)/sizeof(int)));
    printf("Max of array is %d\n", max_of_array(arr, sizeof(arr)/sizeof(int)));
    printf("Min of array is %d\n", min_of_array(arr, sizeof(arr)/sizeof(int)));
    clock_t toc = clock();
    double time_spent = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("CPU time spent: %f\n", time_spent);
    printf("\n");

    int random_array[sizeof(arr)/sizeof(int)];
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        random_array[i] = rand() % 6;
    }

    return 0;
}


int sum_of_array(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int min_of_array(const int arr[], int n) {
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int max_of_array(const int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}