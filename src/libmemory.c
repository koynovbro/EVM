#include "libmemory.h"

#include <stdio.h>
#include <stdlib.h>

int arr[100] = {0};
int acc = 0;

int instructionCounter = 0;
int operation = 0;
int flags[5] = {0}; // P 0 M T E
int cell;
 

int sc_memoryInit(){
	for(int i = 0; i<100; i++){
		arr[i] = 0;
	}
	return 0;
}

int sc_memorySet(int address, int value){
	if(address < 0 || address >=100) {
		flags[MEMORY_NOT_EXITS] = 1;
		return 1;	
	}
	arr[address] = value;
	return 0;
}

int sc_memoryGet(int address, int* value){
	if(address < 0 || address >=100) {
		flags[MEMORY_NOT_EXITS] = 1;
		return 1;
	}
	*value = arr[address];
	return 0;
}

int sc_memorySave(char* filename){
	FILE *fptr;
	
	fptr = fopen(filename,"wb");
	if (fptr == NULL) {
		return 1;   
	}
	fwrite(arr, sizeof(int), 100, fptr);
	fclose(fptr);
}

int sc_memoryLoad(char* filename){
	FILE *fptr;
	
	fptr = fopen(filename,"rb");
	if (fptr == NULL) {
		return 1;   
	}
	fread(arr, sizeof(int), 100, fptr);
	fclose(fptr);
}
int sc_regInit(void){
	for(int i = 0; i < 5; i++){
		flags[i] = 0;
	}
	return 0;
}
int sc_regSet(int reg,int value){
	if(flags[reg] >= 5 || flags[reg] < 0){
		return 1;
	}
	if(value <=0 || value >=1){
		return 1;
	}
	flags[reg] = value;
	return 0;
}

int sc_regGet(int reg, int* value){
	if(flags[reg] >= 5 || flags[reg] < 0){
		return 1;
	}
	flags[reg] = value;
	return 0;
}
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode (int value, int * command, int * operand);


