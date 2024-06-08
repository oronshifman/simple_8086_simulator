#ifndef __SIM86_MEMORY_H__
#define __SIM86_MEMORY_H__

#include <stdint.h>

#define NUM_REGS 8

#define NUM_SETTERS 2
#define NUM_GETTERS 2

enum reg_types
{
    BYTE,
    WORD,

    REG_TYPES
};

enum befor_after_exec
{
    BEFOR_EXEC,
    AFTER_EXEC
};

typedef struct reg_mem
{
    uint8_t memory[REG_TYPES * NUM_REGS];
} reg_mem_t;

reg_mem_t *MemoryCreate(void);
void MemoryDestroy(reg_mem_t *reg_mem);
void MemorySetWordRegValue(reg_mem_t *reg_mem, uint8_t reg, uint16_t value);
void MemorySetByteRegValue(reg_mem_t *reg_mem, uint8_t reg, uint16_t value);
uint16_t MemoryGetWordRegValue(reg_mem_t *reg_mem, uint8_t reg);
uint16_t MemoryGetByteRegValue(reg_mem_t *reg_mem, uint8_t reg);
void MemoryPrintAllReg(reg_mem_t *reg_mem);
void MemoryPrintSingleReg(reg_mem_t *reg_mem, uint8_t size, uint8_t reg, enum befor_after_exec when);
uint8_t MemorySetZF(reg_mem_t *reg_mem);
uint8_t MemoryGetZF(reg_mem_t *reg_mem);
uint8_t MemorySetSF(reg_mem_t *reg_mem);
uint8_t MemoryGetSF(reg_mem_t *reg_mem);

#endif /* __SIM86_MEMORY_H__ */ 

// compile only memory_test
// gcc -I. sim86_memory_test.c sim86_memory.c -o test -g

/*
MY_ENCODE  SPEC_ENCODE
ax = 0     (000) 
al = 0     (000) 
ah = 1     (100)
   
bx = 2     (011) 
bl = 2     (011) 
bh = 3     (111)
   
cx = 4     (001) 
cl = 4     (001) 
ch = 5     (101)
   
dx = 6     (010) 
dl = 6     (010) 
dh = 7     (110)
   
sp = 8     (100)
bp = 10    (101)
si = 12    (110)
di = 14    (111)
*/