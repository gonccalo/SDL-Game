#include "PauseState.h"
#include "Game.h"
#include "StateParser.h"

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
	StateParser stateParser;
	stateParser.parseState("data.xml", s_pauseID, &m_gameObjects, &m_textureIDs);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);
	setCallbacks(m_callbacks);
	return true;

	/*
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
	*/
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for (int i = 0; i < m_textureIDs.size(); i++) {
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
	}
	return true;	
}

void PauseState::setCallbacks(const std::vector<Callback> &callbacks) {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}