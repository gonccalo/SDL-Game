#include"Game.h"
#include <iostream>


Game::Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) { //window init success
			std::cout << "window creation succ\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {  //rederer init success
				std::cout << "rederer creation succ\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}
			else {
				std::cout << "renderer creation fail\n";
				return false;
			}
		}
		else {
			std::cout << "window creation fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer)) {
		return false;
	}
	//m_sourceRectangle.w = 128;
	//m_sourceRectangle.h = 82;
	
	std::cout << "init got succ\n";
	m_bRunning = true;
	return true;
}

void Game::render(){
	SDL_RenderClear(m_pRenderer); //clear the renderer to the draw color

	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::update(){
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents(){
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

Game::~Game()
{
}