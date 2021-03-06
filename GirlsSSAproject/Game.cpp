# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Game.h"

void Game::init() {
	part = L"novel";
}

void Game::update() {
	if (part == L"action") {
		actoin.update(part);
	}
	if (part == L"novel" || part == L"novel_on_action") {
		novel.update(part);
	}
	if (part == L"finish") {
		changeScene(L"Title");
	}

	if (actoin.player.hp <= 0) {
		SoundAsset(L"bgm").stop();
		changeScene(L"GameOver");
	}
}

void Game::draw() const {
	if (part == L"action" || part == L"novel_on_action") {
		actoin.draw();
	}
	if (part == L"novel" || part == L"novel_on_action") {
		novel.draw();
	}
	//Println(novel.talk_log.size(), (novel.talk_log.end() - 1)->scene, (novel.talk_log.end() - 1)->talker);

}
