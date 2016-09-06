#include "GameOverState.h"
#include "Game.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "StateParser.h"

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
	StateParser stateParser;
	stateParser.parseState("data.xml", s_gameOverID, &m_gameObjects, &m_textureIDs);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);
	setCallbacks(m_callbacks);

	return true;
	/*
	if (!TheTextureManager::Instance()->load("assets/over.png", "gameovertext", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png", "mainbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/play.png", "restartbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 97, 19, "gameovertext"), 2);

	GameObject* button1 = new MenuButton();
	button1->load(new LoaderParams(200, 200, 400, 100, "mainbutton"));
	dynamic_cast<MenuButton*>(button1)->setCallback(s_gameOverToMain);

	GameObject* button2 = new MenuButton();
	button2->load(new LoaderParams(200, 300, 400, 100, "restartbutton"));
	dynamic_cast<MenuButton*>(button2)->setCallback(s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	return true;
	*/
}

bool GameOverState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for (int i = 0; i < m_textureIDs.size(); i++) {
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
	}
	//m_gameObjects.~vector();
	std::cout << "a sair do menu";
	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback> &callbacks) {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void GameOverState::s_gameOverToMain() {
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay() {
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}