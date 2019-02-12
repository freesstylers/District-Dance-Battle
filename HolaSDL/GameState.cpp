#include "GameState.h"

GameState::GameState(Game* g)
{
	app = g;
}


GameState::~GameState()
{
	for (GameObject* o : stage)
		delete o;
}

void GameState::update()
{
	for (auto o = stage.begin(); o != stage.end();)
	{
		auto next = o;
		++next;
		//(*o)->update();
		o = next;
	}

}

void GameState::render()
{
	//for (GameObject* o : stage)
		//o->render();
}

bool GameState::handleEvent(SDL_Event e)
{
	bool handled = false;
	auto it = stage.begin();
	while (!handled && it != stage.end()) {
		/*if ((*it)->handleEvent(e))
			handled = true;
		else
			++it;*/
	}
	return handled;
}
