#include "EndState.h"

EndState::EndState(GameManager * g, int actualScore, int maxScore, int percentage): GameState(g)
{
	int scoreLimit = (percentage * maxScore)/ 100;
	Button* cont = new Button(g, 100, 100, Vector2D(400, 100), backToMenu, true);
	Character* perico = new Character(g, 80, 150, Vector2D(400, 150), Resources::PericoDab);
	stage.push_back(cont);
	if (actualScore >= scoreLimit) {
		perico->forceAnimationChange(Resources::PericoDance1);
	}
	else {
		perico->forceAnimationChange(Resources::PericoDab);
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
