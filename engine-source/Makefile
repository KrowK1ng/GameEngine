# Compiler
CC := g++

# Flags
CFLAGS := `sdl2-config --libs` -lSDL2_image -lm -Wall

# Source file
SRCS := $(shell ls ../engine-source/*.cpp )
TEMP := $(subst engine-source/,engine/temp/,$(SRCS))
OBJS := $(subst .cpp,.o,$(TEMP))
#OBJS := $(subst .cpp,.o,$(SRCS))
#OUTO := ../engine/game-engine.o

# Output directory
OUTDIR := ../engine/temp/

default: $(OBJS)

$(OUTO): $(OBJS)
	$(CC) $(CFLAGS) -c $(OBJS) -o $@

$(OUTDIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OUTDIR)*.o 

port:
	rm -rf ../include/*.h && cp *.h ../include && ./include.sh
