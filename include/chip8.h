#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>

// Memory
#define MEMORY_SIZE 4096
extern uint8_t memory[MEMORY_SIZE];

// Registers
extern uint8_t V[16]; // V0-VF
extern uint16_t I;    // Index register
extern uint16_t PC;   // Program counter

// Stack
#define STACK_SIZE 16
extern uint16_t stack[STACK_SIZE];
extern uint8_t SP;

// Timers
extern uint8_t delay_timer;
extern uint8_t sound_timer;

void init_cpu(void);

uint8_t read_memory(uint16_t address);
void write_memory(uint16_t address, uint8_t value);

#endif
