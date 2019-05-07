#include "TutorialMinigame.h"
#include "GameManager.h"

void TutorialMinigame::pause()
{
	timer->Reset();

}

void TutorialMinigame::resume()
{
	timer->Update();
	float time = timer->DeltaTime() * 1000;
	playS->resume(time);

}

TutorialMinigame::TutorialMinigame(GameManager* g, PlayState* p) : MiniGame(g, p)
{
	manager = g;
	playS = p;
	cuadroTutorial = new EmptyObject(g, Vector2D(g->getDefaultWindowWidth() / 2 - 60, g->getDefaultWindowHeight() / 2 - 30), 64, 64, Resources::MetroOn);
}


TutorialMinigame::~TutorialMinigame()
{
}

void TutorialMinigame::render(Uint32 time) {
  	cuadroTutorial->render(time);
}

void TutorialMinigame::update(Uint32 time) {

}

void TutorialMinigame::handleInput(Uint32 time, SDL_Event e) {
	
	if (e.type == SDL_CONTROLLERBUTTONDOWN)
	{
		if ((e.type == SDL_CONTROLLERBUTTONDOWN && SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && keyup) || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE))
		{
			changeCuadroTutorial();

			setActive(false);
			keyup = false;
		}
		else if (e.type == SDL_CONTROLLERBUTTONUP) keyup = true;
	}
}

void TutorialMinigame::changeCuadroTutorial() {
	
	switch (numDialog)
	{
	case 1:
		cuadroTutorial = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() / 2 - 60, manager->getDefaultWindowHeight() / 2 - 30), 64, 64, Resources::MetroOff);
		break;
	default:
		break;
	}
	numDialog++;
}