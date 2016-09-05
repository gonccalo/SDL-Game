#include "PauseState.h"
#include "Game.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain() {
	TheGame::Instance()->getStateMachine()->popState();//Tirar o estado pausa
	//tirar o estado play
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay() {
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/button.png", "main", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* button1 = new MenuButton();
	button1->load(new LoaderParams(200, 100, 150, 48, "main", 0, 1));
	dynamic_cast<MenuButton*>(button1)->setCallback(s_pauseToMain);

	GameObject* button2 = new MenuButton();
	button2->load(new LoaderParams(200, 300, 150, 48, "main"));
	dynamic_cast<MenuButton*>(button2)->setCallback(s_resumePlay);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	return true;
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("main");
	return true;	
}