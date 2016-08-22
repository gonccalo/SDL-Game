#include "MenuState.h"
#include <iostream>
#include "Game.h"
#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/button.png", "playbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 150, 48, "playbutton"), s_menuToPlay);
	m_gameObjects.push_back(button1);
	std::cout << "a entrar no menu";
	return true;
}

bool MenuState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	std::cout << "a sair do menu";
	return true;
}

void MenuState::s_menuToPlay() {
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}