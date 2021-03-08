# Compiler
CC := g++

# Flags
CFLAGS := `sdl2-config --libs` -lSDL2_image -lm -Wall

# Source file
ENGS := $(shell ls engine/temp/*.o)
OBJS := $(shell scripts/get-objects.sh)
#OBJS_OBJS := $(shell cat $(OBJS) | sed "s/.cpp$/.o$/g;s/^src\/^temp\//")

# Output directory
EXEC := out/out
TEMPDIR := temp/
INCDIR := include/

default: $(ENGS) $(OBJS)
	$(CC) $(CFLAGS) -I$(INCDIR) $(ENGS) $(OBJS) src/main.cpp include/objects/object_manager.cpp -o $(EXEC)

$(TEMPDIR)%.o: src/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean: 
	rm -rf $(TEMPDIR)*
