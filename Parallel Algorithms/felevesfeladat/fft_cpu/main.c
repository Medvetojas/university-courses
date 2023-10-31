#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TASK_SIZE 3

typedef struct {
    float x;
    float y;
} float2;

void fft(const float * input, float2 * output, int n);

int main() {
    int TASK_SIZE = 0;

    while (TASK_SIZE <= MAX_TASK_SIZE) {
        clock_t start, end;
        start = clock();
        const int n = pow(2, TASK_SIZE);
        float * input_data = (float * ) malloc(n * sizeof(float));
        float2 * output_data = (float2 * ) malloc(n * sizeof(float2));
        for (int i = 0; i < n; i++) {
            input_data[i] = i;
        }

        fft(input_data, output_data, n);
        printf("Input:\n");
        for (int i = 0; i < n; i++) {
        	printf("%.0f\n",input_data[i]);
        }
        printf("\nOutput:\n");
        for (int i = 0; i < n; i++) {
        	printf("%.3f\t\t%.3fj\n",output_data[i].x,output_data[i].y);
        }

        end = clock();
        printf("\n\n%d:\tTotal runtime:\t%lf\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
        TASK_SIZE++;
        free(output_data);
        free(input_data);
    }

    return 0;
}

void fft(const float * input, float2 * output, int n) {
    for (int i = 0; i < n; i++) {
        float2 temp_output = {0.0f,0.0f};

        for (int j = 0; j < n; j++) {
            float angle = -2.0f * M_PI * i * j / n;
            float2 twiddle = {cos(angle),sin(angle)};
            float2 value = {input[j],0.0f};
            temp_output.x += value.x * twiddle.x - value.y * twiddle.y;
            temp_output.y += value.x * twiddle.y + value.y * twiddle.x;
        }

        output[i] = temp_output;
    }
}