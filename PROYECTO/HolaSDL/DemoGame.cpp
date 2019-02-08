#include "DemoGame.h"
#include "Bird.h"
#include "BulletsShooter.h"
#include "Egg.h"
#include "EggsShooter.h"
#include "Fighter.h"

using namespace std;

DemoGame::DemoGame() :
		SDLGame("Demo", _WINDOW_WIDTH_, _WINDOW_HEIGHT_) {
	initGame();
	exit_ = false;
}

DemoGame::~DemoGame() {
	closeGame();
}

void DemoGame::initGame() {

	EggsShooter* es = new EggsShooter(this);
	BulletsShooter* bs = new BulletsShooter(this);

	GameObject* bird = new Bird(this,es);
	bird->setWidth(75);
	bird->setHeight(75);
	bird->setPosition(Vector2D(10, 10));
	bird->setVelocity(Vector2D(2, 0));

	GameObject* fighter = new Fighter(this,bs);
	fighter->setWidth(75);
	fighter->setHeight(75);
	fighter->setPosition(Vector2D(getWindowWidth()/2, getWindowHeight()/2));
	fighter->setVelocity(Vector2D(2, 0));

	actors_.push_back(es);
	actors_.push_back(bs);
	actors_.push_back(bird);
	actors_.push_back(fighter);

}

void DemoGame::closeGame() {
	for (GameObject* o : actors_) {
		delete o;
	}
}

void DemoGame::start() {
	exit_ = false;

	while (!exit_) {
		Uint32 startTime = SDL_GetTicks();
		handleInput(startTime);
		update(startTime);
		render(startTime);

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void DemoGame::stop() {
	exit_ = true;
}

void DemoGame::handleInput(Uint32 time) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {

			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				exit_ = true;
				break;
				// Pressing f to toggle fullscreen.
			case SDLK_f:
				int flags = SDL_GetWindowFlags(window_);
				if (flags & SDL_WINDOW_FULLSCREEN) {
					SDL_SetWindowFullscreen(window_, 0);
				} else {
					SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
				}
				break;
			}
		}

		for (GameObject* o : actors_) {
			o->handleInput(time, event);
		}
	}
}

void DemoGame::update(Uint32 time) {
	for (GameObject* o : actors_) {
		o->update(time);
	}
}

void DemoGame::render(Uint32 time) {
	SDL_SetRenderDrawColor(getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(getRenderer());

	for (GameObject* o : actors_) {
		o->render(time);
	}

	SDL_RenderPresent(getRenderer());
}

