// This file contains the 'main' function. Program execution begins and ends
// there.
//

#include "Chip8State.h"
#include "chip8.h"
#include "chip8_IO.cpp"
#include <SDL2/SDL.h>
#include <chrono>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
    std::exit(EXIT_FAILURE);
  }

  int videoScale = std::stoi(argv[1]);
  int cycleDelay = std::stoi(argv[2]);
  char const *romFilename = argv[3];

  chip8_IO platform("CHIP-8 Emulator", VIDEO_WIDTH * videoScale,
                    VIDEO_HEIGHT * videoScale, VIDEO_WIDTH, VIDEO_HEIGHT);

  Chip8 chip8;
  chip8.LoadROM(romFilename);

  int videoPitch = sizeof(chip8.video[0]) * VIDEO_WIDTH;

  auto lastCycleTime = std::chrono::high_resolution_clock::now();
  bool quit = false;
  bool SaveState = false;
  bool LoadState = false;
  bool LoadWithoutSave = true;
  Chip8State savedState;
  while (!quit) {
    quit = platform.ProcessInput(chip8.keypad, &SaveState, &LoadState);

    // Handle saving state
    if (SaveState) {
      savedState = Chip8State(chip8);
      // Save the savedState object to a file
      SaveState = false; // Reset the flag
      LoadWithoutSave = false;
    }

    // Handle loading state
    if (LoadState) {
      // Load the state from a file into savedState if it exists
      if (!LoadWithoutSave) {
        chip8.LoadState(savedState);
        LoadState = false; // Reset the flag
      }
    }

    auto currentTime = std::chrono::high_resolution_clock::now();
    float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(
                   currentTime - lastCycleTime)
                   .count();

    if (dt > cycleDelay) {
      lastCycleTime = currentTime;

      chip8.Cycle();

      platform.Update(chip8.video, videoPitch);
    }
  }

  return 0;
}