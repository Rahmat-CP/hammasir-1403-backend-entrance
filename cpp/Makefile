# Makefile for compiling the delivery system project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = Point.cpp Parcel.cpp Configuration.cpp Checker.cpp BikeDelivery.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = delivery_system

# Default rule
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
