#OBJS specifies which files to compile as part of the project 
#OBJS = main.cpp System/GameWindow.cpp System/EventHandler.cpp
OBJS = openGL.cpp
#OBJS = GUI.cpp

#CC specifies which compiler we're using 
CC = g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
# -Wall produces warning messages
# -g for gdb debugging
# -pg for profiling (timing the execution) of methods
# -MM prints header files used
# -pg
# -I for include directory paths
# -c means 'compile only' producing -o files with no linking
# -Dname=value puts a #define name value at the top of your file
COMPILER_FLAGS = -Wall -g -pg -I/home/scott/Development/AntTweakBar/include/

#LINKER_FLAGS specifies the libraries we're linking against 
# -l<library-name> is a library that we're linking against, as in lSDL2 for the SDL2 library
#		-lm might be for the math functions
# -L for library folder paths
# -g is for debugging with gdb (and for me ddd)
# -pg for profiling (timing the execution) of methods
LINKER_FLAGS = -lSDL2 -lGL -lGLU -lGLEW -L/home/scott/Development/AntTweakBar/lib/ -lAntTweakBar -g -pg

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = linuxPlatformer 

#This is the target that compiles our executable 
all : $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
