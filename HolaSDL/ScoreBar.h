#pragma once
#include "GameObject.h"
#include "EmptyObject.h"
#include "ParticleEngine.h"
#include "checkML.h"

//ScoreBar
class ScoreBar : public GameObject
{
private:
	EmptyObject* stars;
	ParticleEngine* particleEffect;
	double maxScore_;
	double maxHeight_;	//the ABSOLUTE maximum height the scorebar can reach

	double currentHeight = 0;	//the current height of the scorebar
	double originalY_ = 0;	//the original y position of the scorebar
	int currentStar = 0;
public:
	ScoreBar(SDLGame* game, double width, double height, Vector2D pos, double maxScore, double maxY);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time) { particleEffect->update(time); };
	virtual void render(Uint32 time, bool beatSync = false);
	void updateBar(double punt);
	virtual ~ScoreBar();
};

