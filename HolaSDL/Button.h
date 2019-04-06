#pragma once
#include "GameObject.h"
#include "GameManager.h"

class Button : public GameObject {
private:
	typedef void Callback(GameManager* game);
	int type;
	GameManager* gameManager_;
	Callback* callback;
	bool active_;


public:

	Button();
	Button(GameManager* game, double width, double height, Vector2D pos, Callback* callback, bool active);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual ~Button();

	bool checkButton(int x, int y);

	void callCallback();
};
