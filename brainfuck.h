#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <stdint.h>
#include <stddef.h>

// Interpreter state
struct BFState {
  // The array and the size of the array.
  size_t array_len;
  uint8_t* array;

  // Pointer to the current position in the array
  // array <= cur < (array+array_len)
  uint8_t* cur;
};

int brainfuck(struct BFState* state, const char* program);

#endif