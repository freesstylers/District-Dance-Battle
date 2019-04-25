#include "PanelMap.h"
#include "GameManager.h"


PanelMap::PanelMap() : difficulty_(1), name_("") {
	fondo_ = EmptyObject();
	for (int i = 0; i < 3; i++) {
		switches[i] = EmptyObject();
	}
	photo_ = EmptyObject();
}

PanelMap::PanelMap(GameManager* manager, Vector2D panelPos, int photo, int difficulty, string name, int level) : difficulty_(difficulty), name_(name), manager_(manager), lvl_(level) {
	fondo_ = EmptyObject(manager_, panelPos, width, height, Resources::Panel);
	star_ = EmptyObject(manager_, Vector2D((panelPos.getX() + width / 2) + width / 40, panelPos.getY() + 10), width / 11, width / 11, Resources::Star);
	switches[0] = EmptyObject(manager_, Vector2D(((panelPos.getX() + width / 2) - 34/2), (panelPos.getY() + height / 2) + (height / 24)), 34, 30, Resources::NumPlayersSwitch);
	switches[1] = EmptyObject(manager_, Vector2D(((panelPos.getX() + width / 2) - 34/2), (panelPos.getY() + height / 2) + 5 * (height / 24)), 34, 30, Resources::Difficulty);
	switches[2] = EmptyObject(manager_, Vector2D(((panelPos.getX() + width / 2) - width/6), (panelPos.getY() + height / 2) + 9 * (height / 24) - 1), 68, 30, Resources::Dance);
	photo_ = EmptyObject(manager_, Vector2D((panelPos.getX() + ( width / 2)) - ((2*width / 5)/2), 10 + panelPos.getY() + height / 10), (2*width / 5), 3 * height / 11, photo);
	switches[index].scale(2);
}

void PanelMap::render(Uint32 time, bool beatHandler) {
		fondo_.render(time, beatHandler);
		for (int i = 0; i < 3; i++) {
			switches[i].render(time, beatHandler);
		}
		Vector2D aux = star_.getPosition();
		for (int i = 0; i < difficulty_; i++) {
			star_.render(time, beatHandler);
			star_.setPosition(Vector2D(star_.getPosition().getX() + star_.getWidth(), star_.getPosition().getY()));
		}
		star_.setPosition(aux);
		renderLetters(time, beatHandler);
		photo_.render(time, beatHandler);
}

void PanelMap::renderLetters(Uint32 time, bool beatHandler) {
	Texture msg0(manager_->getRenderer(),
		types[lvl_],
		*(manager_->getServiceLocator()->getFonts()->getFont(
			Resources::FIPPS20)), { COLOR(0x00000000) });
	SDL_Rect dest;
	dest.x = fondo_.getPosition().getX() + 5;
	dest.y = fondo_.getPosition().getY() + 10;
	dest.w = (fondo_.getWidth() / 2) - 10;
	dest.h = fondo_.getWidth() / 10;
	msg0.render(manager_->getRenderer(), dest);
	dest.x = fondo_.getPosition().getX() + (fondo_.getWidth()/2) - ((name_.size()*15)/2);
	dest.y = photo_.getPosition().getY() + photo_.getHeight();
	dest.h = (fondo_.getPosition().getY()- dest.y +fondo_.getHeight() / 2);
	Texture msg1(manager_->getRenderer(),
		name_,
		*(manager_->getServiceLocator()->getFonts()->getFont(
			Resources::FIPPS10)), { COLOR(0x00000000) });
	dest.w = name_.size() * 15;
	msg1.render(manager_->getRenderer(), dest);
	dest.y = dest.y + (dest.h + 1);
}

void PanelMap::reset() {
	switches[index].scale(0.5);
	if (!oneP_) {
		oneP_ = true;
		switches[0].changeFrame();
	}
	if (hardMode_) {
		hardMode_ = false;
		switches[1].changeFrame();
	}
	index = 0;
	switches[index].scale(2);
}

void PanelMap::prevSwitch() {
	switches[index].scale(0.5);
	if (index >= 2) { index = 0; }
	else { index++; }
	switches[index].scale(2);
}

void PanelMap::nextSwitch() {
	switches[index].scale(0.5);
	if (index <= 0) { index = 2; }
	else { index--; }
	switches[index].scale(2);
}

void PanelMap::selectButton(SDL_Event e, SDL_GameController* cont) {
	switch (index)
	{
	case 0:
		oneP_ = !oneP_;
		switches[index].changeFrame();
		break;
	case 1:
		if (difActive) {
			hardMode_ = !hardMode_;
			switches[index].changeFrame();
		}
		else
		{
			manager_->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0);
		}
		break;
	case 2:
		//Cuando se pulsa va al play state con el nivel correspondiente

		if (SDL_GameControllerGetButton(cont, SDL_CONTROLLER_BUTTON_A) || e.key.keysym.sym == SDLK_RETURN)
		{
			manager_->getServiceLocator()->getAudios()->haltChannel(0);
			manager_->getMachine()->pushState(new DialogState(manager_, lvl_, 0, oneP_, hardMode_));
		}
		//MenuState::play(lvl_);
		break;
	}
}


PanelMap::~PanelMap()
{

}