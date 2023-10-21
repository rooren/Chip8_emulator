#include "chip8.h"
#include <fstream>
#include <iostream>

const unsigned int START_ADDRESS = 0x200;
const unsigned int FONTSET_SIZE = 80;
const unsigned int FONTSET_START_ADDRESS = 0x50;
uint8_t fontset[FONTSET_SIZE] =
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void Chip8::LoadROM(char const* filename)
{
	// Open the file as a stream of binary and move the file pointer to the end
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	try 
	{
		if (file.is_open())
		{
			// Get size of file and allocate a buffer to hold the contents (this can be done due to "ate" flag which moves the file pointer to end of file)
			std::streampos size = file.tellg();
			char* buffer = new char[size];

			// Go back to the beginning of the file and fill the buffer
			file.seekg(0, std::ios::beg);
			file.read(buffer, size);
			file.close();

			// Load the ROM contents into the Chip8's memory, starting at 0x200
			for (long i = 0; i < size; i++)
			{
				//Chip8’s memory from 0x000 to 0x1FF is reserved, 
				memory[START_ADDRESS + i] = buffer[i];
			}

			// Free the buffer
			delete[] buffer;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

Chip8::Chip8()
{

	// Initialize PC - Program Counter
	pc = START_ADDRESS;
	// Load fonts into memory
	for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
	{
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}
}