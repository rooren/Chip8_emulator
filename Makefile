CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -lSDL2

# List of source files
SOURCES = chip8.cpp ConsoleApplication1.cpp

# Derive the object files from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
TARGET = chip8

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJECTS)
