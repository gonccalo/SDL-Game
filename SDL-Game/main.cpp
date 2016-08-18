#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	Uint32 frameStart, frameTime;
	if (TheGame::Instance()->init("jogos", 100, 100, 640, 480, false)) {
		while (TheGame::Instance()->running()) {
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameStart < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else {
		return -1;
	}
	TheGame::Instance()->clean();
	return 0;
}