#include"Game.h"
#include <iostream>
#include <SDL_image.h>


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

	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;
	
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	m_destinationRectangle.x = 0;//m_sourceRectangle.x = 0;
	m_destinationRectangle.y = 0;//m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	std::cout << "init got succ\n";
	m_bRunning = true;
	return true;
}

void Game::render(){
	SDL_RenderClear(m_pRenderer); //clear the renderer to the draw color

	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);

	SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::update(){
	int animationFrame = int(((SDL_GetTicks() / 100) % 6));
	m_sourceRectangle.x = 128 * animationFrame;
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