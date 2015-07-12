#OBJS specifies which files to compile as part of the project 
OBJS = main.cpp MainGame.cpp Sprite.cpp GLSLProgram.cpp Errors.cpp

#CC specifies which compiler we're using 
CC = g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
# -Wall produces warning messages
# -g for gdb debugging
# -pg for profiling (timing the execution) of methods
# -MM prints header files used
# -pg
# -c means 'compile only' producing -o files with no linking
# -Dname=value puts a #define name value at the top of your file
COMPILER_FLAGS = -IC:\MinGW_dev_lib\include -LC:\MinGW_dev_lib\lib -w #-Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against 
# -l<library-name> is a library that we're linking against, as in lSDL2 for the SDL2 library
#		-lm might be for the math functions
# -g is for debugging with gdb
# -pg for profiling (timing the execution) of methods
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lglew32s -lopengl32 

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = windowsPlatformer 

#This is the target that compiles our executable 
all : $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -DGLEW_STATIC -o $(OBJ_NAME)
