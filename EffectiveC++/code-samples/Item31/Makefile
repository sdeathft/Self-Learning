CC=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -pedantic -g
TARGET=main

all: $(TARGET)

$(TARGET): main.cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET)