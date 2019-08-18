PROG = pingpong
CC = gcc

FLAGS = -lSDL2

include common.mk

$(PROG): $(OBJS)
	$(info Building ping pong...)
	$(CC) -o $@ $(OBJS) $(FLAGS)
