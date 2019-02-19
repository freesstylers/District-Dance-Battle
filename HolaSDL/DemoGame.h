#pragma once

#include <vector>
#include <list>
#include "SDLGame.h"
#include "GameObject.h"
#include "Timer.h"
#include "Flechas.h"
#include "Point.h"
#include "BeatHandeler.h"
#include "LevelInputManager.h"
#include "QTEManager.h"

class DemoGame: public SDLGame {

public:
	DemoGame();
	virtual ~DemoGame();

	// from SDLGame
	void start();
	void stop();

	std::list<Flechas*> flechasPantalla_;
	Point* punto;

private:
	void initGame();
	void closeGame();
	void handleInput(Uint32 time);
	void update(Uint32 time);
	void render(Uint32 time);
	void generate();
	Vector2D asignaVel(double time);

	const static int _WINDOW_WIDTH_ = 800;
	const static int _WINDOW_HEIGHT_ = 600;
	bool exit_;
	std::list<GameObject*> actors_;
	std::list<Flechas*> flechasNivel_;
	Timer* timer;
	LevelInputManager* lip;
	QTEManager* qteman;
	BeatHandeler* bh;
	Vector2D posFlechaInicial =  Vector2D(700, 350);
	Vector2D velFlechas;
};
