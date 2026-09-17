#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "brainfuck.h"


int main() {
    // Define a simple Brainfuck program that increments, prints and decrements a cell
    const char* program = "++++++++++[>+++++++<-]>.";

    // Initialize the Brainfuck interpreter state
    struct BFState state;
    state.array_len = 30000;  // Typically, Brainfuck uses a 30,000 byte array. Theoretically, this is infinite
    state.array = calloc(state.array_len, sizeof(uint8_t));
    
    if (!state.array) {
        perror("Could not allocate Memory");
        return EXIT_FAILURE;
    }

    state.cur = state.array;

    if (state.array == NULL) {
        fprintf(stderr, "Failed to allocate memory for the array.\n");
        return 1;
    }

    // Measure the start time
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Run the Brainfuck program
    int result = brainfuck(&state, program);

    // Measure the end time
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate the elapsed time in nanoseconds
    double elapsed_ns = (end_time.tv_sec - start_time.tv_sec) * 1e9 + (end_time.tv_nsec - start_time.tv_nsec);
    printf("\n---\nExecution time: %.3f ms\n", elapsed_ns / 1e6);

    // Cleanup
    free(state.array);

    return result;
}