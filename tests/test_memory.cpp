#include "chip8.h"
#include <gtest/gtest.h>

TEST(TestInitialization, MemoryAndRegistersZeroed) {
  init_cpu();
  for (int i = 0; i < MEMORY_SIZE; ++i) {
    EXPECT_EQ(memory[i], 0);
  }
  for (int i = 0; i < 16; ++i) {
    EXPECT_EQ(V[i], 0);
  }
  EXPECT_EQ(I, 0);
  EXPECT_EQ(PC, 0x200);
  EXPECT_EQ(SP, 0);
  EXPECT_EQ(delay_timer, 0);
  EXPECT_EQ(sound_timer, 0);
}

TEST(TestMemoryReadWrite, InBounds) {
  write_memory(0x300, 0xAB);
  EXPECT_EQ(read_memory(0x300), 0xAB);
}

TEST(TestMemoryReadWrite, OutOfBounds) {
  // Should log error and return 0xFF
  EXPECT_EQ(read_memory(MEMORY_SIZE + 1), 0xFF);
  // Write should not crash
  write_memory(MEMORY_SIZE + 1, 0x12);
}
