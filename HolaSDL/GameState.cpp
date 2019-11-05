#include "GameState.h"
#include "GameManager.h"

GameState::GameState(GameManager* g)
{
	manager = g;
}


GameState::~GameState()
{
	for (GameObject* o : stage)
		delete o;
}

void GameState::update(Uint32 time)
{
	for (auto o = stage.begin(); o != stage.end();)
	{
		auto next = o;
		++next;
		(*o)->update(time);
		o = next;
	}
}

void GameState::render(Uint32 time, bool beatSync)
{
	for (GameObject* o : stage)
		o->render(time, beatSync);
	SDL_RenderSetLogicalSize(manager->getRenderer(), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight());
}

bool GameState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_F9) {
		manager->stop();
		return true;
	}
	else {
		bool handled = false;
		auto it = stage.begin();
		while (!handled && it != stage.end() && (*it) != nullptr) {
			if ((*it)->handleInput(time, e))
				handled = true;
			else
				++it;
		}
		return handled;
	}
}