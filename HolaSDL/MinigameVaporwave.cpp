#include "MinigameVaporwave.h"
#include "GameManager.h"
#include "PlayState.h"
#include "LevelInputManager.h"

MinigameVaporwave::MinigameVaporwave(GameManager * g, PlayState * p): MiniGame(g, p)
{
	manager = g;
	playS = p;
	fback = new Feedback(g, 150, 150, Vector2D(g->getWindowWidth() / 2 - 150 / 2, g->getWindowHeight() / 2 - 150 / 2));
	timer = new TimerNoSingleton();

	createList();
}

void MinigameVaporwave::generateButtons()
{
	if (!levelButtons_.empty()) {
		if (levelButtons_.back() != nullptr) {
			screenButtons_.push_back(levelButtons_.back());
		}
		levelButtons_.pop_back();
	}
}

void MinigameVaporwave::render(Uint32 time)
{
	for (Note* o : screenButtons_)
	{
		o->render(time);
	}
	fback->render(time);
}

void MinigameVaporwave::update(Uint32 time)
{
	if (!screenButtons_.empty()) {
		for (Note* o : screenButtons_)
		{
			o->update(time);
		}
	}
	Timer::Instance()->Update();
	timer->Update();
	if (timer->DeltaTime() > (playS->bh->getBeatTime() / 1000.0) && noteAmount > 0)
	{
		generateButtons();

		timer->Reset();

		noteAmount--;
	}
	if (Timer::Instance()->DeltaTime() > (playS->bh->getBeatTime() / 1000.0)*(maxNotes + 4)) {
		failed = true;
	}

}

void MinigameVaporwave::createList()
{
	{
		int newpos;
		int aux;
		failed = false;
		noteAmount = 15;
		maxNotes = noteAmount;
		Note* note;
		for (int i = 0; i < 8; i++) {
			aux = rand() % 8;

			switch (aux) {
			case 0:
				note = new Note(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, Vector2D(0, 0), Vector2D(200, 200));
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, Vector2D(0, 0), Vector2D(200, 200));
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, Vector2D(manager->getWindowWidth(), 0), Vector2D(-200, 200));
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, Vector2D(manager->getWindowWidth(), 0), Vector2D(-200, 200));
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, Vector2D(0, manager->getWindowHeight()), Vector2D(200, -200));
				break;
			case 5:
				note = new Note(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, Vector2D(0, manager->getWindowHeight()), Vector2D(200, -200));
				break;
			case 6:
				note = new Note(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, Vector2D(manager->getWindowWidth(), manager->getWindowHeight()), Vector2D(-200, -200));
				break;
			case 7:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, Vector2D(manager->getWindowWidth(), manager->getWindowHeight()), Vector2D(-200, -200));
				break;
			}
			levelButtons_.push_front(note);
		}
	}
}

void MinigameVaporwave::deleteList()
{
	for (auto o = screenButtons_.begin(); o != screenButtons_.end();)
	{
		auto next = o;
		++next;
		delete (*o);
		screenButtons_.remove(*o);
		o = next;
	}
}
