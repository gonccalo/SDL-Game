#include "GameOverState.h"
#include "Game.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update(){
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/over.png", "gameovertext", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png", "mainbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/play.png", "restartbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 19, 97, "gameovertext"), 2);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 400, 100, "mainbutton"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 400, 100, "restartbutton"), s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	return true;
}

bool GameOverState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

	m_gameObjects.~vector();
	std::cout << "a sair do menu";
	return true;
}

void GameOverState::s_gameOverToMain() {
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay() {
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}