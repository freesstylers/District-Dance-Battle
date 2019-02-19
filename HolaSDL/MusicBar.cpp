#include "MusicBar.h"



MusicBar::MusicBar()
{
	texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Point); //cambiar texturas
}


MusicBar::~MusicBar()
{
}

void MusicBar::handleInput(Uint32 time, const SDL_Event& event) {
	

}

void MusicBar::update(Uint32 time) {//queremos hacer que avance en fucion de la longitud de la cancion
							
	//double avance = longitudBarra / tnivel;
	//Vector2D(avance, 0);
}

void MusicBar::render(Uint32 time) {
	texture->render(getRect());

}