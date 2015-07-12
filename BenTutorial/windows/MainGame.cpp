#include "MainGame.h"
#include "Errors.h"

#include <iostream>
#include <string>

//Constructor, just initializes private member variables
MainGame::MainGame()
{
    _window = NULL;
    _screenWidth = 1024;
    _screenHeight = 768;
    _gameState = PLAY;
}

//Destructor
MainGame::~MainGame()
{
	std::cout << "\ncleaning up...\n";
	//Destroy window	
	SDL_DestroyWindow( _window );
	_window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
	std::cout << "DONE\n";
}

//This runs the game
void MainGame::run() {
    initSystems();

    //Initialize our sprite. (temporary)
    _sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

    //This only returns when the game ends
    gameLoop();
}

//Initialize SDL and Opengl and whatever else we need
void MainGame::initSystems() {
    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Open an SDL window
    _window = SDL_CreateWindow("Derp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    if (_window == NULL) {
        fatalError("SDL Window could not be created!");
    }

    //Set up our OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (glContext == NULL) {
        fatalError("SDL_GL context could not be created!");
    }

    //Set up glew (optional but recommended)
    GLenum error = glewInit();
    if (error != GLEW_OK) {
        fatalError("Could not initialize glew!");
    }

    //Tell SDL that we want a double buffered window so we dont get
    //any flickering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Set the background color to blue
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    initShaders();
}

void MainGame::initShaders() {
    _colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
    _colorProgram.addAttribute("vertexPosition");
    _colorProgram.linkShaders();
}

//This is the main game loop for our program
void MainGame::gameLoop() {

    //Will loop until we set _gameState to EXIT
    while (_gameState != EXIT) {
        processInput();
        drawGame();
    }
}

//Processes input with SDL
void MainGame::processInput() {
    SDL_Event evnt;

    //Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) {
    std::string mouseButton;
        switch (evnt.type) {
            case SDL_QUIT:
					_gameState = EXIT;
					break;
            case SDL_MOUSEMOTION:
					std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
					break;
            case SDL_MOUSEBUTTONDOWN:
            	switch (evnt.button.button) {
            		case SDL_BUTTON_LEFT:
            			mouseButton = "left";
            			break;
            		case SDL_BUTTON_MIDDLE:
            			mouseButton = "middle";
            			break;
            		case SDL_BUTTON_RIGHT:
            			mouseButton = "right";
            			break;
            	}
            	std::cout << mouseButton << " mouse button down" << std::endl;
					break;
            case SDL_MOUSEBUTTONUP:
            	switch (evnt.button.button) {
            		case SDL_BUTTON_LEFT:
            			mouseButton = "left";
            			break;
            		case SDL_BUTTON_MIDDLE:
            			mouseButton = "middle";
            			break;
            		case SDL_BUTTON_RIGHT:
            			mouseButton = "right";
            			break;
            	}
            	std::cout << mouseButton << " mouse button up" << std::endl;
					break;
        }
    }
}

//Draws the game using the almighty OpenGL
void MainGame::drawGame() {
    //Set the base depth to 1.0
    glClearDepth(1.0);
    //Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _colorProgram.use();

    //Draw our sprite!
    _sprite.draw();

    _colorProgram.unuse();

    //Swap our buffer and draw everything to the screen!
    SDL_GL_SwapWindow(_window);
}    
