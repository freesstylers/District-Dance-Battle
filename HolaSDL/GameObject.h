#pragma once

#include "SDLGame.h"
#include "Vector2D.h"

class GameObject {

public:
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

	SDL_Rect* getFrameRect();

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
	virtual void render(Uint32 time); //De momento no coge animaciones, se extiende en el futuro

protected:
	SDLGame* game_; // pointer to the game

	Animation animation;

	bool active_;   // indicates if the object is active

	double width_;  // width
	double height_; // height

	int lastRender = 0; //saves the last time the object was rendered
	int framesPerSecond = 1; //times the object should be rendered every second

	Vector2D position_; // position (suppose to be left-top corner)
	Vector2D velocity_; // velocity
	Vector2D acceleration_; // acceleration
	double rotation_; // rotation (for the corresponding texture)
};
