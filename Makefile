# Compiler
CC := g++

# Flags
CFLAGS := `sdl2-config --libs` -lSDL2_image -lm

# Source file
SRCS := main.cpp

# Exec name
EXEC := out


all: main.o renderer.o game.o texturemanager.o sprite.o object.o
	$(CC) $(CFLAGS) -o $(EXEC) renderer.o main.o game.o texturemanager.o sprite.o object.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -rf *.o 
