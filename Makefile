# Compiler
CC := g++

# Flags
CFLAGS := `sdl2-config --libs` -lSDL2_image -lm -Wall

# Source file
ENGS := $(shell ls engine/temp/*.o)

# Output directory
EXEC := out/out
TEMPDIR := temp/
INCDIR := include/

default: $(ENGS)
	$(CC) $(CFLAGS) -I$(INCDIR) $(ENGS) src/main.cpp -o $(EXEC)

$(TEMPDIR)%.o: src/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean: 
	rm -rf $(TEMPDIR)*.o 