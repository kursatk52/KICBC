#include <stdio.h>
#include "KICBC-lib.h"



//Input/Output operations
#define READ 10 //Read from terminal to memory location
#define WRITE 11 //Write from memory to terminal

//Load/Store operations
#define LOAD 20 //Load from memory to accumulator (ar)
#define STORE 21 //Store from accumulator(ar) to memory location 

//Arithmetic operations
#define ADD 30 //Add a word from memory location to accumulator
#define SUBTRACT 31 //Substract a word from memory location to accumulator
#define DIVIDE 32 //Divide a word from memory location to accumulator
#define MULTIPLY 33 //Multiply a word from memory location to accumulator

//Transfer-control operations
#define BRANCH 40 // Branch to specific memory location
#define BRANCHNEG 41 // Branch to specific memory location if the accumulator is negative
#define BRANCHZERO 42 // Branch to specific memory location if the accumulator is zero
#define HALT 43 // Halt --i.e the program has complated its task


#define SENTINEL -99999
#define MEMSIZE 100




int main() {

    printHeader();

    int memory[MEMSIZE] = { 0 }; //Adresses between 0 to 99


    int accumulatorRegister = 0000; //Accumulator Register
    int instractionRegister = 0000; //Instraction Register that holds instraction which being performed.
    int memoryTracker = 00; //Memory Tracker --i.e Track of memory location that contains the next instruction will being performed.
    int operationCode = 00; // Operation Code: Indicate the operation currently being performed --i.e the left two digits of instruction word.
    int operand = 00; // OPerand: indicate memory location on which the current instruction operates.

    // Reading instructions from user by using sentinel-controlled loop
    int memoryLoc = 0;

    while (1)
    {
        printf("%02d ? ", memoryLoc);
        int instructionBuff = 0;
        scanf("%d", &instructionBuff);

        if (instructionBuff != SENTINEL) {
            memory[memoryLoc] = instructionBuff;
            memoryLoc++;
        }
        else {
            break;
        }
    }

    //Performing read instructions from user
    while (1) {

        if (memoryTracker > MEMSIZE) {
            break;
        }

        instractionRegister = memory[memoryTracker];
        operationCode = instractionRegister / 100;
        operand = instractionRegister % 100;

        switch (operationCode)
        {
        case READ:
            read(memory, operand);
            break;

        case WRITE:
            write(memory,operand);
            break;
        
        case LOAD:
            load(memory, operand, &accumulatorRegister);
            break;
        case STORE:
            store(memory, operand, &accumulatorRegister);
            break;
        case ADD:
            add(memory,operand,&accumulatorRegister);
            break;
        case SUBTRACT:
            substract(memory, operand, &accumulatorRegister);
            break;
        case MULTIPLY:
            multiply(memory, operand, &accumulatorRegister);
            break;
        case DIVIDE:
            divide(memory, operand, &accumulatorRegister);
            break;
        case BRANCH:
            branch(&memoryTracker,operand,&accumulatorRegister);
            break;
        case BRANCHNEG:
            branchNeg(&memoryTracker,operand,&accumulatorRegister);
            break;
        case BRANCHZERO:
            branchZero(&memoryTracker, operand, &accumulatorRegister);
            break;

        case HALT:
            halt();
            puts("");
            dumpMemory(memory);
            break;
        }


        memoryTracker++;
    }


}















