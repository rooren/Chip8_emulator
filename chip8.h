#pragma once
#include <chrono>
#include <cstdint>
#include <cstring>
#include <random>
#include "Chip8State.h"

const unsigned int VIDEO_HEIGHT = 32;
const unsigned int VIDEO_WIDTH = 64;
class Chip8State;
class Chip8 {
public:
  uint8_t registers[16]{};
  uint8_t memory[4096]{};
  uint16_t index{};
  uint16_t pc{};
  uint16_t stack[16]{};
  uint8_t sp{};
  uint8_t delayTimer{};
  uint8_t soundTimer{};
  uint8_t keypad[16]{};
  uint32_t video[64 * 32]{};
  uint16_t opcode;

  std::default_random_engine randGen;
  std::uniform_int_distribution<uint8_t> randByte;
  typedef void (Chip8::*Chip8Func)();
  // function pointer table
  Chip8Func table[0xF + 1];
  Chip8Func table0[0xE + 1];
  Chip8Func table8[0xE + 1];
  Chip8Func tableE[0xE + 1];
  Chip8Func tableF[0x65 + 1];

  void LoadROM(char const *filename);
  void OP_00E0();
  void OP_00EE();
  void OP_1nnn();
  void OP_2nnn();
  void OP_3xkk();
  void LoadState(const Chip8State &state);
  void OP_4xkk();
  void OP_5xy0();
  void OP_6xkk();
  void OP_7xkk();
  void OP_8xy0();
  void OP_8xy1();
  void OP_8xy2();
  void OP_8xy3();
  void OP_8xy4();
  void OP_8xy5();
  void OP_8xy6();
  void OP_8xy7();
  void OP_8xyE();
  void OP_9xy0();
  void OP_Annn();
  void OP_Bnnn();
  void OP_Cxkk();
  void OP_Dxyn();
  void OP_Ex9E();
  void OP_ExA1();
  void OP_Fx07();
  void OP_Fx0A();
  void OP_Fx15();
  void OP_Fx18();
  void OP_Fx1E();
  void OP_Fx29();
  void OP_Fx33();
  void OP_Fx55();
  void OP_Fx65();
  Chip8();
  void Table0();
  void Table8();
  void TableE();
  void TableF();
  void OP_NULL();
  void Cycle();
  void Fetch();
  Chip8Func Decode();
  void Execute(Chip8Func handler);
};

/*
table function pointer :
the first leval is for further tables and when the entire opcode is unique:
Table8 - The first digit repeats but the last digit is unique
Table0 - The first three digits are $00E but the fourth digit is unique:

+-----+     +-------+       +---------+
| 0x0 | --> | Table0 | --> | OP_00E0  |
                                                        +---------+
| 0xE | --> |        | --> | OP_00EE  |
+-----+     +-------+       +---------+
| 0x1 | --> | OP_1nnn|
+-----+     +-------+
| 0x2 | --> | OP_2nnn|
+-----+     +-------+
| 0x3 | --> | OP_3xkk|
+-----+     +-------+
| 0x4 | --> | OP_4xkk|
+-----+     +-------+
| 0x5 | --> | OP_5xy0|
+-----+     +-------+
| 0x6 | --> | OP_6xkk|
+-----+     +-------+
| 0x7 | --> | OP_7xkk|
+-----+     +-------+
| 0x8 | --> | Table8 | --> | OP_8xy0  |
+-----+     |        |      +---------+
                                                                ...
                                                        +---------+
| 0xE | --> |        | --> | OP_8xyE  |
+-----+     +-------+       +---------+
| 0x9 | --> | OP_9xy0|
+-----+     +-------+
| 0xA | --> | OP_Annn|
+-----+     +-------+
| 0xB | --> | OP_Bnnn|
+-----+     +-------+
| 0xC | --> | OP_Cxkk|
+-----+     +-------+
| 0xD | --> | OP_Dxyn|
+-----+     +-------+
| 0xE | --> | TableE| --> | OP_ExA1  |
+-----+     |       |       +---------+
| 0x1 | --> |       | --> | OP_Ex9E  |
+-----+     +-------+       +---------+
| 0xF | --> | TableF| --> | OP_Fx07  |
+-----+     |       |       +---------+
| 0xA | --> |       | --> | OP_Fx0A  |
+-----+     |       |       +---------+
| 0x1 | --> |       | --> | OP_Fx15  |
+-----+     |       |       +---------+
| 0x5 | --> |       | --> | OP_Fx18  |
+-----+     |       |       +---------+
| 0x6 | --> |       | --> | OP_Fx1E  |
+-----+     |       |       +---------+
| 0x2 | --> |       | --> | OP_Fx29  |
+-----+     |       |       +---------+
| 0x3 | --> |       | --> | OP_Fx33  |
+-----+     |       |       +---------+
| 0x5 | --> |       | --> | OP_Fx55  |
+-----+     |       |       +---------+
| 0x6 | --> |       | --> | OP_Fx65  |
+-----+     +-------+       +---------+
*/