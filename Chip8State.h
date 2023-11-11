#pragma once
#include "chip8.h"
class Chip8;

class Chip8State {
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

  // Default constructor
  Chip8State() = default;
  // Constructor that takes a Chip8 instance and saves its state
  Chip8State(const Chip8 &chip8);
};