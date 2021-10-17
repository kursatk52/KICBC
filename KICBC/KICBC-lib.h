#include <stdio.h>



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


int halt() {
    printf("\n*** KICBC execution terminated :( ***");
    return 0;
}

int read(int  *mem, int index) {
    scanf("%d", (mem+index));
    return 0;
}

int write(int *mem, int index) {
    printf("%d",*(mem + index));
    return 0;
}


int load(int *mem, int index, int *acum) {
    *acum = *(mem + index);
    return 0;
}

int store(int *mem, int index, int *acum) {
    *(mem + index) = *acum;
    return 0;
}

int add(int *mem,int index,int *acum) {
    *acum += *(mem + index);
    return 0;
}
int substract(int* mem, int index, int* acum) {
    *acum -= *(mem + index);
    return 0;
}
int divide(int* mem, int index, int* acum) {
    *acum /= *(mem + index);
    return 0;
}
int multiply(int* mem, int index, int* acum) {
    *acum *= *(mem + index);
    return 0;
}

int branch(int* memTracker, int location) {
    *memTracker = location;
    return 0;
}

int branchNeg(int* memTracker,int location,int* accum) {
    if (*accum < 0)
        *memTracker = location;
    return 0;
}

int branchZero(int* memTracker, int location, int* accum) {
    if (*accum == 0)
        *memTracker = location;
    return 0;
}



// Dumps all memory and show to user.
int dumpMemory(const int mem[]) {
    for (int i = 0; i < 100; i++) {
        if (i % 20 == 0)
            puts("");
        printf("%04d ", mem[i]);
    }
    puts("");
    return 0;

}
