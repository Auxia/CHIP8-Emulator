#include "chip8.h"
#include <stdio.h>
#include <string.h>

uint8_t memory[MEMORY_SIZE];
uint8_t V[16];
uint16_t I;
uint16_t PC;
uint16_t stack[STACK_SIZE];
uint8_t SP;
uint8_t delay_timer;
uint8_t sound_timer;

void init_cpu(void) {
  memset(memory, 0, sizeof(memory));
  memset(V, 0, sizeof(V));
  I = 0;
  PC = 0x200;
  memset(stack, 0, sizeof(stack));
  SP = 0;
  delay_timer = 0;
  sound_timer = 0;
}

uint8_t read_memory(uint16_t address) {
  if (address < MEMORY_SIZE) {
    return memory[address];
  } else {
    fprintf(stderr, "Error: Memory read OOB at 0x%X\n", address);
    return 0xFF;
  }
}

void write_memory(uint16_t address, uint8_t value) {
  if (address < MEMORY_SIZE) {
    memory[address] = value;
  } else {
    fprintf(stderr, "Error: Memory write OOB at 0x%X\n", address);
  }
}
