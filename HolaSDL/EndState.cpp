#include "EndState.h"

EndState::EndState(GameManager * g, int actualScore, int maxScore, int percentage): GameState(g)
{
	int scoreLimit =(percentage * maxScore)/ 100;
	Button* cont = new Button(g, 100, 100, Vector2D(400, 100),backToMenu, 1);
	Perico* perico = new Perico(g, 80, 150, Vector2D(400, 150));
	stage.push_back(cont);
	if (actualScore >= scoreLimit) {
		//perico->changeAnimation(Resources::PericoBaile1);
	}
	else {
		//perico->changeAnimation(Resources::PericoBaile2);
	}

	stage.push_back(perico);
}

EndState::~EndState()
{
}

void EndState::backToMenu(GameManager * gameManager)
{
	gameManager->getMachine()->pushState(new PlayState(gameManager, "level"));
}
