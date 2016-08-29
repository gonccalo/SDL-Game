#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "PauseState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "heli", TheGame::Instance()->getRenderer())) {
		return false;
	}
	m_gameObjects.push_back(new MousePointer(new LoaderParams(0, 0, 90, 90, "heli")));
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	std::cout << "a entrar no jogo";
	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("animate");
	TheTextureManager::Instance()->clearFromTextureMap("heli");
	std::cout << "a sair do jogo";
	return true;
}