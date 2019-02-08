#pragma once

#include <vector>

#include "SDLGame.h"
#include "GameObject.h"

class DemoGame: public SDLGame {

public:
	DemoGame();
	virtual ~DemoGame();

	// from SDLGame
	void start();
	void stop();

private:
	void initGame();
	void closeGame();
	void handleInput(Uint32 time);
	void update(Uint32 time);
	void render(Uint32 time);

	const static int _WINDOW_WIDTH_ = 800;
	const static int _WINDOW_HEIGHT_ = 600;
	bool exit_;
	std::vector<GameObject*> actors_;

};
