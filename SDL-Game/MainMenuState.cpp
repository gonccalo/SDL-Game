#include "MainMenuState.h"
#include <iostream>
#include "Game.h"
#include "MenuButton.h"
#include "StateParser.h"

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MainMenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MainMenuState::onEnter() {
	StateParser stateParser;
	stateParser.parseState("data.xml", s_menuID, &m_gameObjects, &m_textureIDs);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);

	setCallbacks(m_callbacks);
	return true;
	
	/*
	if (!TheTextureManager::Instance()->load("assets/play.png", "playbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);
	m_gameObjects.push_back(button1);
	std::cout << "a entrar no menu";
	return true;
	*/
}

bool MainMenuState::onExit() {
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

void MainMenuState::setCallbacks(const std::vector<Callback> &callbacks) {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*> (m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void MainMenuState::s_menuToPlay() {
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}