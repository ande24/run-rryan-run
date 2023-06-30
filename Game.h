#pragma once	//Game.h will only be included once during compilation

//Include SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

class Game {	//Class that acts as the game engine
	private:
		//Variables
			RenderWindow* window; 
			VideoMode videoMode;  
			Event event;	
			bool isFullscreen;

		//Private functions
		void initVariables();
		void initWindow();

	public: 
		//Constructors / Destructors
		Game();
		~Game();

		//Accessors
		const bool isRunning();

		//Functions
		void update();
		void render();
};

