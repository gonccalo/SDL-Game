#pragma once
#ifndef __Game__
#define __Game__
#include <iostream>
#include <vector>
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "PlayState.h"

class Game{
public:
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	int getGameWidth() const { return m_width; }
	int getGameHeight() const { return m_height; }

private:
	Game();
	static Game* s_pInstance;
	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_width;
	int m_height;
	std::vector<GameObject*> m_gameObjects;
	GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;
#endif