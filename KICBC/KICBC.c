#include <stdio.h>
#include <stdlib.h>

#include "KICBC-lib.h"
#include "KICBC-opts.h"
#include "KICBC-hware.h"




#define SENTINEL -99999
//#define DEBUG  // By defining DEBUG, some codes will be active for some extra featrues.



int main() {

    atexit(halt);
    printHeader();


    int operationCode = 00; // Operation Code: Indicate the operation currently being performed --i.e the left two digits of instruction word which in IR.
    int operand = 00; // OPerand: indicate memory location on which the current instruction operates.


    // Reading instructions from user by using sentinel-controlled loop

    while (1)
    {
        printf("%02d ? ", instructionPointer);
        int instructionBuff = 0;
        scanf("%d", &instructionBuff);


#ifdef DEBUG
        if (instructionBuff == -11111) {
            dumpMemory();
            exit(EXIT_SUCCESS);
        }
#endif

        



        if (instructionBuff != SENTINEL) {
            *(&memory + instructionPointer) = instructionBuff;
            instructionPointer++;
        }else {
            break;
        }
    }


    resetIPLoc();

    //Performing read instructions from user
    int doNotAdd2InstructorPointer = 0;
    while (1) {

        if (instructionPointer >= MEMSIZE) { //Exit the program if instractionPointer reach to memory size.
            break;
        }

        

        instractionRegister = *(&memory + instructionPointer); //the instraction assigned to instraction register to perform.
        operationCode = instractionRegister / 100; // got the operation and assigned to operationCode variable.
        operand = instractionRegister % 100; // got the memory location where will performed operation and assigned to operand variable.

        //All operation bellow are described at KICBC-lib.h
        switch (operationCode)
        {
        case READ:
            read(operand);
            break;

        case WRITE:
            write(operand);
            break;
        
        case LOAD:
            load(operand);
            break;
        case STORE:
            store(operand);
            break;
        case ADD:
            add(operand);
            break;
        case SUBTRACT:
            substract(operand);
            break;
        case MULTIPLY:
            multiply(operand);
            break;
        case DIVIDE:
            divide(operand);
            break;
        case BRANCH:
            branch(operand);
            doNotAdd2InstructorPointer = 1;
            break;
        case BRANCHNEG:
            branchNeg(operand);
            doNotAdd2InstructorPointer = 1;
            break;
        case BRANCHZERO:
            branchZero(operand);
            doNotAdd2InstructorPointer = 1;
            break;

        case HALT:
            dumpMemory(memory);
            exit(EXIT_SUCCESS);
            break;
        }
        if (doNotAdd2InstructorPointer == 1)
            doNotAdd2InstructorPointer = 0;
        else
            instructionPointer++;
        
    }


}















