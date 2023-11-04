# CHIP8 Emulator

A simple CHIP8 emulator written in C++ with SDL2.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building the Emulator](#building-the-emulator)
- [Usage](#usage)
- [Keyboard Controls](#keyboard-controls)
- [Save State](#save-state)
- [Logging](#logging)
- [License](#license)

## Introduction

This is a CHIP8 emulator, a simple virtual machine designed for games and applications. It emulates the CHIP8 platform and allows you to run CHIP8 ROMs.

## Getting Started

## Prerequisites

To build and run the emulator, you need to have SDL2 installed on your system. If you don't have SDL2 installed, you can download and install it from [libsdl.org](https://www.libsdl.org/download-2.0.php).

## Building the Emulator

1. Clone this repository to your local machine or download it as a ZIP file.

2. Navigate to the project directory using your terminal.

3. Use the provided Makefile to build the emulator using the make command


## Usage
To run a CHIP8 ROM, use the following command, replacing <ROM> with the path to your CHIP8 ROM file:

```shell
./chip8 <Scale> <Delay> <ROM>
```

Scale: Scaling factor for the emulator window (e.g., 5 for 5x scale).

Delay: Cycle delay in milliseconds (e.g., 2 for 2 ms).

ROM: Path to the CHIP8 ROM file you want to run.

## Keyboard Controls
The emulator supports the following keyboard controls:

Keyboard Keys: 1, 2, 3, 4, 5, 6, 7, 8, 9, E, Q, R, V, F

Save state: K

Load state: L

## Save State
The CHIP8 emulator supports saving and loading emulator states. To use this feature, follow these steps:

While the emulator is running, you can press the 'S' key to save the current state.

To load a previously saved state, press the 'L' key.

## Logging
The emulator includes logging functionality for debugging. It outputs information about the executed CHIP8 instructions to the console.
To enable or disable logging, modify the DEBUG_OUTPUT definition in the source code (under chip8.cpp).

## License
This project is licensed under the MIT License. See the LICENSE file for details.

Feel free to contribute or report issues. Happy CHIP8 gaming!




