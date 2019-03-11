#include "EndState.h"

EndState::EndState(GameManager * g, int actualScore, int maxScore, int percentage): GameState(g)
{
	int scoreLimit = (percentage * maxScore)/ 100;
	Button* cont = new Button(g, 100, 100, Vector2D(400, 100),backToMenu);
	Perico* perico = new Perico(g, 80, 150, Vector2D(400, 150), Resources::PericoDab);
	stage.push_back(cont);
	if (actualScore >= scoreLimit) {
		perico->queueAnimationChange(Resources::PericoBaile1, false);
	}
	else {
		perico->queueAnimationChange(Resources::PericoDab, false);
	}

	stage.push_back(perico);
}

EndState::~EndState()
{
}

void EndState::backToMenu(GameManager * gameManager)
{
	gameManager->getMachine()->popState();
}
