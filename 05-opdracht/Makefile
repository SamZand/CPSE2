SFML_PATH := C:/TI_SOFTWARE/sfml-2.5.1
SFML_LIB := -L $(SFML_PATH)/lib
SFML_INC := -I $(SFML_PATH)/include

CXXFLAGS := -std=c++17 -fexceptions
CXX := g++ 


SFML_STL := -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
EXEC := main.exe

rm := del

.PHONY := all build clean

SOURCES := $(wildcard *.cpp)

all: build
	./$(EXEC) $(ARGS)

build:
	$(CXX) $(CXXFLAGS) $(SOURCES) $(SFML_INC) $(SFML_LIB) $(SFML_STL) -o $(EXEC)

clean:
	$(rm) $(EXEC) *.o