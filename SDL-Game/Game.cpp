#include"Game.h"
#include "InputHandler.h"
#include "MenuButton.h"
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
	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());

	std::cout << "init got succ\n";
	m_bRunning = true;
	return true;
}

void Game::render(){
	SDL_RenderClear(m_pRenderer); //clear the renderer to the draw color

	m_pGameStateMachine->render();
	
	SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::update(){
	m_pGameStateMachine->update();
	
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
