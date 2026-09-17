# Brainfuck Interpreter (C)

A C implementation of a Brainfuck interpreter, written as part of the 
Computer Architecture course at TUM.

## What it does

Brainfuck is a minimal, Turing-complete language with only 8 
instructions, operating on a byte array and a movable pointer into it. 
This interpreter parses and executes a Brainfuck program against a given 
interpreter state, implementing:

- Pointer movement (`>` / `<`) with bounds checking: the pointer must 
  stay within the allocated array, and moving out of bounds is treated 
  as a runtime error
- Byte increment/decrement at the current pointer position (`+` / `-`)
- I/O (`.` / `,`) via `putchar` / `getchar`
- Loops (`[` / `]`), implemented by scanning forward/backward through 
  the program to find the matching bracket by tracking nesting depth

The core function signature:

```c
int brainfuck(struct BFState* state, const char* program);
```

It returns `0` on successful execution of the full program, or `-1` if 
a runtime error occurs (e.g. the pointer would move outside the array).

## How to build and run

```bash
make
./brainfuck
```

## What I learned

This was a good exercise in low-level state management in C - tracking 
a program counter and a data pointer simultaneously, handling bounds 
checking correctly, and implementing bracket matching without recursion 
by counting nesting depth while scanning the program string.
