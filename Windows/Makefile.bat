cd C:\dev\platformer\Windows
g++ main.cpp System/GameWindow.cpp -IC:\MinGW_dev_lib\include\SDL2 -LC:\MinGW_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o linuxPlatformerWindows
