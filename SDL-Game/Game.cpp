#include"Game.h"
#include "InputHandler.h"
Game* Game::s_pInstance = 0;

Game::Game() {

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

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
	
	std::cout << "init got succ\n";
	m_bRunning = true;
	return true;
}

void Game::render(){
	SDL_RenderClear(m_pRenderer); //clear the renderer to the draw color

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::update(){
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();	
	}
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents(){
	TheInputHandler::Instance()->update();
}

void Game::quit() {
	m_bRunning = false;
}

void Game::clean() {
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
