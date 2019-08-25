PROG = pingpong
CC = gcc

FLAGS = -lSDL2_mixer -lSDL2_ttf -lSDL2 -lm

include common.mk

$(PROG): $(OBJS)
	$(info Building ping pong...)
	$(CC) -o $@ $(OBJS) $(FLAGS)
