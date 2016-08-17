#include "Game.h"

int main(int argc, char* args[])
{

	if (Game::Instance()->init("jogos", 100, 100, 640, 480, false)) {
		while (Game::Instance()->running()) {
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();
			SDL_Delay(10);
		}
	}
	else {
		return -1;
	}
	Game::Instance()->clean();
	return 0;
}