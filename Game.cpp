#include "Game.h"

//PRIVATE FUNCTIONS
void Game::initVariables() 
{
	this->window = nullptr;		//Initializes pointer to window as a nullptr
}

void Game::initWindow() 
{
	/*
		Initializes the game window

		1. Stores user's desktop resolution in variable "videoMode"
		2. Creates a RenderWindow with title "game" and size videoMode
		3. The window is initialized in fullscreen
	*/

	this->videoMode = VideoMode::getDesktopMode();
	this->window = new RenderWindow(videoMode, "game", Style::Fullscreen);
	this->isFullscreen = true;
}

//============================================================================================

//CONSTRUCTORS
Game::Game()				//Default constructor
{				
	initVariables();
	initWindow();
}

Game::~Game() 
{
	delete this->window;	//Frees the dynamically allocated window
}

//============================================================================================

//ACCESSORS
const bool Game::isRunning()			//Returns an unchangeable bool (true/false)
{			
	return this->window->isOpen();		//Check whether or not game window is open
}

//============================================================================================

//FUNCTIONS
void Game::update() 
{
	/* 
		Polls for events 

		- Pressing the close button closes the window
		- Pressing F11 toggles between fullscreen and default windowed
		
		Add:
		- Events for UI buttons
		- Event for jump (uparrow)
		- Event for drop (downarrow)
	*/

	while ( this->window->pollEvent(this->event) ) 
	{
		switch (this->event.type) 
		{
			case Event::Closed:
				this->window->close();
				break;

			case Event::KeyPressed:
				if ( this->event.key.code == Keyboard::F11) 
				{	
					if (this->isFullscreen) 
					{
						this->window->create(this->videoMode, "game", Style::Default);
						this->isFullscreen = false;
					} 
					else 
					{
						this->window->create(this->videoMode, "game", Style::Fullscreen);
						this->isFullscreen = true;
					}
				}
				break;
		}
	}
}

void Game::render() {
	
	this->window->clear(Color(127, 127, 255, 255));

	//Draw game

	this->window->display();
}
