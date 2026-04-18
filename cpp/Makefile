# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = program

# Object files
OBJS = main.o massam1.o massam2.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

massam1.o: massam1.cpp massam.h
	$(CXX) $(CXXFLAGS) -c massam1.cpp

massam2.o: massam2.cpp massam.h
	$(CXX) $(CXXFLAGS) -c massam2.cpp

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(TARGET) $(OBJS)
