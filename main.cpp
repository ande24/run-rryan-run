#include "Game.h"

int main() {
	//Initialize game
	Game game;

	//Game loop
	while ( game.isRunning() ) {
		game.update();	
		game.render();
	}

	return 0;
}