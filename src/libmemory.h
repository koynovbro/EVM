#ifndef LIBMEMORY_H
#define LIBMEMORY_H

#define BUFFER_OVERFLOW 0
#define ZERO_DIVISION 1
#define MEMORY_NOT_EXIST 2
#define INGORE_TICK 3
#define BAD_COMMAND 4 

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit(void);
int sc_regSet(int register,int value);
int sc_regGet(int register, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode (int value, int * command, int * operand);

#endif  // LIBMEMORY_H
