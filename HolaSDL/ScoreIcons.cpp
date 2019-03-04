#include "ScoreIcons.h"
#include "PlayState.h"


ScoreIcons::ScoreIcons()
{
}
ScoreIcons::ScoreIcons(SDLGame* game, double width, double height, Vector2D pos, PlayState* play, bool tipo) :
	GameObject(game), play(play), tipo(tipo)
{
	timer = Timer::Instance();
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Good);

	framesPerSecond = 4;
	isAnimationSyncedToMusic = true;
}

void ScoreIcons::update(Uint32 time)
{
	if (tipo)
	{
		switch (play->getScoreInfo1())
		{
		case 0:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Bad);
			break;
		case 1:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Regular);
			break;
		case 2:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Good);
			break;
		case 3:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Perfect);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (play->getScoreInfo2())
		{
		case 0:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Bad);
			break;
		case 1:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Regular);
			break;
		case 2:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Good);
			break;
		case 3:
			animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::Perfect);
			break;
		default:
			break;
		}
	}
}

ScoreIcons::~ScoreIcons()
{
}
