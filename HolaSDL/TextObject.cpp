#include "TextObject.h"


TextObject::TextObject(SDLGame * manager, Font* font, Vector2D pos) : GameObject(manager)
{
	textFont = font;

	text = new Texture(game_->getRenderer(), "", *textFont, SDL_Color{ (255), (255), (255), (255) });;

	animation.frameHeight = text->getHeight();
	animation.frameWidth = text->getWidth();
	animation.columns = 1;
	animation.rows = 1;
	animation.totalFrames = 1;

	setHeight(text->getHeight());
	setWidth(text->getWidth());
	setPosition(pos);
}

TextObject::~TextObject()
{
	delete text;
}

void TextObject::render(Uint32 time, bool beatSync)
{
	if(active_)
		text->render(getRect(), &getFrameRect(), alpha_);
}

//Puts a text like a texture
void TextObject::setText(string txt, SDL_Color color, Uint32 size)
{
	text->loadFromText(game_->getRenderer(), txt, *textFont, color, size);

	animation.frameHeight = text->getHeight();
	animation.frameWidth = text->getWidth();
	setHeight(text->getHeight());
	setWidth(text->getWidth());
}
