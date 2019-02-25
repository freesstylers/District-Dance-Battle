#include "Cuadro.h"



Cuadro::Cuadro()
{
}
Cuadro::Cuadro(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Cuadro);

	frames_ = 2;
	cols_ = 1;
	rows_ = 2;

	// the width/height of a frame
	frameWidth_ = texture->getWidth() / cols_;
	frameHeight_ = texture->getHeight() / rows_;

	// we start at frame 0
	currFrame_ = 0;

	// we update a frame every 100ms (change dynamically)
	lastTimeUpdated_ = 0;
	freq_ = 200;
}

void Cuadro::update(Uint32 time)
{
	// we update the frame every lastTimeUpdated
	if (time - lastTimeUpdated_ >= freq_) {
		currFrame_ = (currFrame_ + 1) % frames_;
		lastTimeUpdated_ = time;
	}
}
void Cuadro::render(Uint32 time)
{
	// compute the frame coordinates
	int row = currFrame_ / cols_;
	int col = currFrame_ % cols_;

	// the excat position of the frame in th etexture
	SDL_Rect clip = { col * frameWidth_, row * frameHeight_, frameWidth_,
			frameHeight_ };

	// where to render it
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(),
		getHeight());

	// render the frame
	texture->render(dest, &clip);
}
Cuadro::~Cuadro()
{
}
