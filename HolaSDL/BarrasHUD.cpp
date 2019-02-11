#include "BarrasHUD.h"

BarrasHUD::BarrasHUD(SDLGame* game)
{
	//sprite de la barra
	//texture = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::);

}


BarrasHUD::~BarrasHUD()
{

}

int BarrasHUD::Avanza(int &valorBarra)
{
	return valorBarra; 
}
bool BarrasHUD::bolAvanza(int &valueBarra)
{
	valueBarra++;
	if (valueBarra == 150)
	{
		findeNivel == true;
	}
	return findeNivel;
}
void BarrasHUD::render(Uint32 time) {
	//texture->render();
}
