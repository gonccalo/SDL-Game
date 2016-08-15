#pragma once
#ifndef __Game__
#define __Game__
#include "SDL.h"
#include "TextureManager.h"

typedef TextureManager TheTextureManager;
class Game
{
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;
};
#endif