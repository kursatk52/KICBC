#include <stdio.h>
#include <stdlib.h>
#include "KICBC-opts.h"
#include "KICBC-hware.h"

// NOT Finished

// print welcome messages
int printHeader() {
    printf("***              Welcome to KICBC              ***\n");
    printf("*** [K]ICBS a [C]OMPUTER [B]ASED on [C]-lang   ***\n");
    printf("**************************************************\n");
    printf("*** Please enter your program one instraction  ***\n");
    printf("*** (or data word) at a time. I will type the  ***\n");
    printf("*** location number and a  question mark (?).  ***\n");
    printf("*** You then type the word for that location.  ***\n");
    printf("*** Type the sentinel -99999 to stop entering  ***\n");
    printf("***                your program.               ***\n");
}

// Print message and exits program.
int halt() {
    printf("\n*** KICBC execution terminated :( ***\n\n");
    return 0;
}


// Takes the input from user and changes the value of memory location where at index.
int read(int index) {
    scanf("%d",(&memory+index));
    return 0;
}

// Read from the value of memory location where at index and output to screen.
int write(int index) {
    printf("%d",*(&memory+index));
    return 0;
}

// Loads value to acumulattor from memory at index
int load(int index) {
    accumulatorRegister = *(&memory + index);
    return 0;
}

// Takes value from acumulattor and stores the memory at index
int store(int index) {
    *(&memory + index) = accumulatorRegister;
    return 0;
}


// Add index to value what in acumulattor register.
int add(int index) {
    accumulatorRegister += *(&memory + index);
    return 0;
}

// Substract index from value what in acumulattor register.
int substract(int index) {
    accumulatorRegister -= *(&memory + index);
    return 0;
}

// Performs dividing operation value what in acumulattor register over index;
int divide(int index) {
    accumulatorRegister /= *(&memory + index);
    return 0;
}

// Multiply index with value what in acumulattor register.
int multiply(int index) {
    accumulatorRegister *= *(&memory + index);
    return 0;
}

// Changes the point of instructionPointer register's location --i.a between from 0 to 99
int branch(int location) {
    instructionPointer = location;
    return 0;
}

// Changes the point of instructionPointer register's location if value what in acumulattor register is less than zero --i.a between from 0 to 99
int branchNeg(int location) {
    if (accumulatorRegister < 0)
        instractionRegister = location;
    return 0;
}

// Changes the point of instructionPointer register's location if value what in acumulattor register is equal to zero --i.a between from 0 to 99
int branchZero(int location) {
    if (accumulatorRegister == 0)
        instructionPointer = location;
    return 0;
}



// Dumps all memory and show to user.
int dumpMemory() {
    puts("");
    for (int i = 0; i < MEMSIZE; i++) {
        if (i % 20 == 0)
            puts("");
        printf("%04d ", *(&memory+i));
    }
    puts("");
    return 0;

}


// set to 00 that ýnstructionPointer Register.
int resetIPLoc() {
    instructionPointer = 00;
    return 0;
}
