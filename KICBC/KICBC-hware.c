#include"KICBC-opts.h"


int memory[MEMSIZE] = { 0 }; //Random-Access Memory of KICBC whose adresses between 0 to 99




//Registers
int accumulatorRegister = 0000; //Accumulator Register aka AR that is used for arithmetic operations.
int instractionRegister = 0000; //Instraction Register aka IR that holds instractions that being performed.
int instructionPointer = 00; //Instraction Pointer aka IP --i.e Track of memory location that contains the next instruction will be performed in.

