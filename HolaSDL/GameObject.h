#pragma once

#include "SDLGame.h"
#include "Vector2D.h"
#include <queue>
#include "checkML.h"

//Base class for the game's entities

class GameObject {

private:

public:
	Animation animation;
	GameObject();
	GameObject(SDLGame* game);
	virtual ~GameObject();

	SDLGame* getGame() const;
	void setGame(SDLGame* game);

	bool isActive() const;
	void setActive(bool active);
	bool toggleActive();

	double getWidth() const;
	void setWidth(double width);

	double getHeight() const;
	void setHeight(double height);

	void scale(double s);

	Texture* getAnimation();
	void setTexture(Texture* texture);

	void setAnimation(int texture);

	SDL_Rect getFrameRect();

	const Vector2D& getPosition() const;
	void setPosition(const Vector2D &pos);

	const Vector2D& getVelocity() const;
	void setVelocity(const Vector2D &vel);

	const Vector2D& getAcceleration() const;
	void setAcceleration(const Vector2D &vel);

	double getRotation() const;
	void setRotation(double angle);

	SDL_Rect getRect();

	// abstract methods to be implemented in sub-classes
	virtual bool handleInput(Uint32 time, const SDL_Event& event) = 0;
	virtual void update(Uint32 time) = 0;
	virtual void render(Uint32 time, bool beatSync = false); 
	virtual void init() {}

	virtual void queueAnimationChange(int animationTag);
	virtual void forceAnimationChange(int animationTag);

	virtual void cleanAnimationQueue() { while (!queuedAnimations.empty()) { queuedAnimations.pop(); } }

	void setAlpha(int alpha) { alpha_ = alpha; }
	void changeAlpha(int alphaChange);
	int getAlpha() { return alpha_; };

	void isAnimationSynced(bool is) { isAnimationSyncedToMusic = is; }
	void setAnimationFramerate(int frames) { framesPerSecond = frames; }

protected:
	SDLGame* game_; // pointer to the game

	bool active_;   // indicates if the object is active

	double width_;  // width
	double height_; // height
	int alpha_;

	int lastRender = 0; //saves the last time the object was rendered
	int framesPerSecond = 1; //times the object should be rendered every second

	Vector2D position_; // position (suppose to be left-top corner)
	Vector2D velocity_; // velocity
	Vector2D acceleration_; // acceleration
	double rotation_; // rotation (for the corresponding texture)

	bool isAnimationSyncedToMusic = false;

	virtual void changeAnimation(int animationTag);
	std::queue<int> queuedAnimations;
};
