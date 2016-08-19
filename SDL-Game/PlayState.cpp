#include "PlayState.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {

}

void PlayState::render() {

}

bool PlayState::onEnter() {
	std::cout << "a entrar no jogo";
	return true;
}

bool PlayState::onExit() {
	std::cout << "a sair do jogo";
	return true;
}