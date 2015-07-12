# makefile for macosx

flags = -Wall -DDEBUG # -O3

% : %.cpp Net.h
	g++ $< -o $@ ${flags}

all : Test Simple Node listener talker

test : Test
	./Test

node : Node
	./Node

simple : Simple
	./Simple
	
talker : talker
	./talker
	
listener : listener
	./listener

clean:
	rm -f Test Node Simple
