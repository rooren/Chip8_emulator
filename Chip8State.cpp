#include "Chip8State.h"

// Constructor that takes a Chip8 instance and saves its state
Chip8State::Chip8State(const Chip8 &chip8) {
  // Copy the state from the Chip8 instance to the Chip8State instance
  memcpy(registers, chip8.registers, sizeof(registers));
  memcpy(memory, chip8.memory, sizeof(memory));
  index = chip8.index;
  pc = chip8.pc;
  memcpy(stack, chip8.stack, sizeof(stack));
  sp = chip8.sp;
  delayTimer = chip8.delayTimer;
  soundTimer = chip8.soundTimer;
  memcpy(keypad, chip8.keypad, sizeof(keypad));
  memcpy(video, chip8.video, sizeof(video));
  opcode = chip8.opcode;
}

// void Chip8State::SaveState(const char* filename, const Chip8State& state) {
//     std::ofstream file(filename, std::ios::binary);
//     file.write(reinterpret_cast<char*>(&state), sizeof(Chip8State));
// }

// void Chip8State::LoadState(const char* filename, Chip8State& state) {
//     std::ifstream file(filename, std::ios::binary);
//     if (file) {
//         file.read(reinterpret_cast<char*>(&state), sizeof(Chip8State));
//     }
// }