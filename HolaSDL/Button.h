#pragma once
#include "GameObject.h"
#include "GameManager.h"

class Button : public GameObject {
private:
	typedef void Callback(GameManager* game);
	int type;
	GameManager* gameManager_;
	Callback* callback;


public:

	Button();
	Button(GameManager* game, double width, double height, Vector2D pos, Callback* callback);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual ~Button();

	void checkButton(int x, int y);
};
