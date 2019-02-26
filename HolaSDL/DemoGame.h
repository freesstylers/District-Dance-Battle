#pragma once

#include <vector>
#include <list>
#include "SDLGame.h"
#include "GameObject.h"
#include "Timer.h"
#include "Flechas.h"
#include "Point.h"
#include "BeatHandeler.h"

#include "BarrasHUD.h"
#include "FondoBarra.h"
#include "BarraPuntos.h"
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
	void generate();

	const static int _WINDOW_WIDTH_ = 800;
	const static int _WINDOW_HEIGHT_ = 600;
	bool exit_;
	std::list<GameObject*> actors_;
	std::list<Flechas*> flechasPantalla_;
	std::list<Flechas*> flechasNivel_;
	Timer* timer;
	Point* punto;
	BeatHandeler* bh;
	Vector2D posFlechaInicial =  Vector2D(700, 350);
	Vector2D velFlechas;
	BarrasHUD* indicador;
	FondoBarra* spritebarra;
	BarraPuntos* barraPuntos;
	double duracion = 120.0;
};
