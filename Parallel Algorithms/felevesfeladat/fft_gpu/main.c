#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#include <time.h>
#include "kernel_loader.h"
#include <math.h>

#define MAX_TASK_SIZE 3

int main() {
    cl_int err;
    cl_platform_id platform_id;
    cl_device_id device_id;
    cl_context context;
    cl_command_queue queue;
    cl_program program;
    cl_kernel kernel;
    int TASK_SIZE = 0;

    clGetPlatformIDs(1, & platform_id, NULL);
    clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, & device_id, NULL);
    // Create an OpenCL context and command queue
    context = clCreateContext(NULL, 1, & device_id, NULL, NULL, & err);
    queue = clCreateCommandQueue(context, device_id, 0, & err);

    // Create an OpenCL program from the kernel source code
    const char * kernel_code = load_kernel_source("fft.cl", & err);
    if (err != 0) {
        printf("Error creating program: %d\n", err);
        return -1;
    }
    program = clCreateProgramWithSource(context, 1, & kernel_code, NULL, & err);
    if (err != CL_SUCCESS) {
        printf("Error creating program: %d\n", err);
        return -1;
    }

    clBuildProgram(program, 1, & device_id, NULL, NULL, NULL);

    // Create an OpenCL kernel from the program
    kernel = clCreateKernel(program, "fft", & err);
    while (TASK_SIZE <= MAX_TASK_SIZE) {
        clock_t start, end;
        start = clock();
        const int n = pow(2, TASK_SIZE);

        float * input_data = (float * ) malloc(n * sizeof(float));
        cl_float2 * output_data = (cl_float2 * ) malloc(n * sizeof(cl_float2));
        for (int i = 0; i < n; i++) {
            input_data[i] = i;
        }

        cl_mem input_buffer = clCreateBuffer(context, CL_MEM_READ_ONLY, n * sizeof(float), NULL, & err);
        cl_mem output_buffer = clCreateBuffer(context, CL_MEM_READ_ONLY, n * sizeof(cl_float2), NULL, & err);

        err = clEnqueueWriteBuffer(queue, input_buffer, CL_TRUE, 0, n * sizeof(float), input_data, 0, NULL, NULL);

        err = clSetKernelArg(kernel, 0, sizeof(cl_mem), & input_buffer);
        err = clSetKernelArg(kernel, 1, sizeof(cl_mem), & output_buffer);
        err |= clSetKernelArg(kernel, 2, sizeof(int), & n);
        if (err != CL_SUCCESS) {
            fprintf(stderr, "Failed to set kernel arguments. Error code: %d\n", err);
            exit(1);
        }

        size_t global_size[1] = {n};
        err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, global_size, NULL, 0, NULL, NULL);

        if (err != CL_SUCCESS) {
            fprintf(stderr, "Failed to enqueue kernel. Error code: %d\n", err);
            exit(1);
        }

        // Read output image data back to host memory
        err = clEnqueueReadBuffer(queue, output_buffer, CL_TRUE, 0, n * sizeof(cl_float2), output_data, 0, NULL, NULL);
        if (err != CL_SUCCESS) {
            fprintf(stderr, "Failed to read output. Error code: %d\n", err);
        }

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
        clReleaseMemObject(input_buffer);
        clReleaseMemObject(output_buffer);
    }

    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    return 0;
}