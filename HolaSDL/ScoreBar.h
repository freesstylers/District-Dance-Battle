#pragma once
#include "GameObject.h"
class ScoreBar : public GameObject
{
private:
	Texture* texture;
	int maxScore_;
	int maxHeight_;

	double currentHeight = 0;
	double originalHeight = 0;
public:
	ScoreBar(SDLGame* game, double width, double height, Vector2D pos, int maxScore, int maxHeight);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time) {};
	void updateBar(int punt);
	virtual ~ScoreBar();
	virtual void updateResolution(double wScale, double hScale);
};

