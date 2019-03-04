#pragma once
#include "GameObject.h"
#include "Timer.h"
class PlayState;
class ScoreIcons : public GameObject
{
private:
	Timer* timer;
	PlayState* play;
	bool tipo;
public:
	ScoreIcons();
	ScoreIcons(SDLGame* game, double width, double height, Vector2D pos, PlayState* play, bool tipo);
	~ScoreIcons();
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; }
};

