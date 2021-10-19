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


#define MEMSIZE 100