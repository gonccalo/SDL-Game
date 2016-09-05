#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "StateParser.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]))) {
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

bool PlayState::onEnter() {
	StateParser stateParser;
	stateParser.parseState("data.xml", s_playID, &m_gameObjects, &m_textureIDs);
	std::cout << "a entrar no jogo";
	return true;

	/*
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "heli", TheGame::Instance()->getRenderer())) {
		return false;
	}
	Player* pPlayer = new Player();
	pPlayer->load(new LoaderParams(500, 100, 128, 82, "animate"));
	m_gameObjects.push_back(pPlayer);

	Enemy* pEnemy = new Enemy();
	pEnemy->load(new LoaderParams(100, 100, 90, 90, "heli"));
	m_gameObjects.push_back(pEnemy);
	std::cout << "a entrar no jogo";
	return true;
	*/
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for (int i = 0; i < m_textureIDs.size(); i++) {
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
	}
	std::cout << "a sair do jogo";
	return true;
}