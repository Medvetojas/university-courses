/*
 * Project made by: Szilárd Kristóf Babik
 * Date: 2022.02.28.
 *
 * Project description:
 * The program is designed to run faster on CPUs without (or turned off) hyperthreading, contrary to the logical belief.
 * By default, the program uses 5 threads to write the same string 180000 times, to 5 files - one file for each thread.
 * The threads compete for writing to the HDD. It is shared among all threads.
 * In hyperthreading mode, there are more "processors" competing for writing but only one can do it at a time.
 * Due to these conflicts, the program slows down.
 * Without hyperthreading, there are less "processors", less conflicts, and the program runs faster.
 * At the end, the goal would be to prove that hyperthreading is not always preferable.
 *
 *
 * About hyperthreading: https://en.wikipedia.org/wiki/Hyper-threading
 *
 * Test PC:
 *   - AMD Ryzen 5 5600X
 *   - Physical Cores: 6
 *   - Logical Cores: 12 (with hyperthreading)
 *   - Samsung NVMe SSD 1 TB
 *
 * Execution times:
 *   - With hyperthreading:
 *      - 67.27s
 *      - 67.96s
 *      - 65.44s
 *
 *   - Without hyperthreading:
 *      - 61.63s
 *      - 61.94s
 *      - 59.55s
 *
 * On slower CPUs, I would expect even larger differences in execution times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


#define TOTAL_WRITTEN_LINES 900000 //increase this to increase workload = more time needed to finish
#define NUM_OF_THREADS 5 //increase this to increase number of threads = less time needed to finish

pthread_barrier_t barrier;

void *writeDummy(int id) {
    printf("Thread %d started\n", id);
    int counter = 0;
    char file[] = "fileN.txt";
    FILE *f;
    file[4] = id + '0';
    clock_t start_thread, end_thread;
    pthread_barrier_wait(&barrier); //wait for all threads to be ready
    start_thread = clock();
    while (counter < TOTAL_WRITTEN_LINES / NUM_OF_THREADS) {
        f = fopen(file, "w");
        fprintf(f, "Writing text to the file");
        fclose(f);
        counter++;
    }
    end_thread = clock();
    double elapsed_thread = (double) (end_thread - start_thread) / CLOCKS_PER_SEC;
    printf("Thread %u: %f seconds elapsed.\n", id, elapsed_thread);
    pthread_barrier_wait(&barrier);
    pthread_exit(NULL);
}


int main() {
    clock_t start, end;
    srand(time(NULL));

    pthread_t threads[NUM_OF_THREADS];
    pthread_barrier_init(&barrier, NULL, NUM_OF_THREADS + 1); //+1 is for the main thread

    start = clock();
    int i;

    for (i = 0; i < NUM_OF_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, (void *(*)(void *)) &writeDummy, i + 2) != 0) {
            printf("Failed to create thread, exiting program...\n");
            return 1;
        }
    }

    pthread_barrier_wait(&barrier);

    pthread_barrier_wait(&barrier);

    end = clock();

    double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nTotal time of execution = %f seconds\n\n", elapsed);

    pthread_barrier_destroy(&barrier);

    return 0;
}