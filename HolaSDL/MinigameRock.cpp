#include "MinigameRock.h"
#include "GameManager.h"

MinigameRock::MinigameRock(GameManager * g, PlayState * p) : MiniGame(g, p)
{
	manager = g;
	playS = p;
	fback = new Feedback(g, 150, 150, Vector2D(g->getWindowWidth() / 2 - 150 / 2, g->getWindowHeight() / 2 - 150 / 2));
	timer = new TimerNoSingleton();

	createList();
}

MinigameRock::~MinigameRock()
{
}

void MinigameRock::render(Uint32 time)
{
	for (Note* o : screenButtons_)
	{
		o->render(time);
	}
	fback->render(time);
}

void MinigameRock::update(Uint32 time)
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

void MinigameRock::handleInput(Uint32 time, SDL_Event e)
{
}

void MinigameRock::generateButtons()
{
	if (!levelButtons_.empty()) {
		if (levelButtons_.back() != nullptr) {
			screenButtons_.push_back(levelButtons_.back());
		}
		levelButtons_.pop_back();
	}
}

void MinigameRock::createList()
{
	{
		int newpos;
		int aux;
		failed = false;
		noteAmount = 1;
		maxNotes = noteAmount;
		Note* note;
		for (int i = 0; i < 8; i++) {
			aux = rand() % 8;

			Vector2D pos = Vector2D(400.0, 300.0);
			Vector2D vel = Vector2D(0, 0);

			switch (aux) {
			case 0:
				note = new Note(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, pos, vel);
				break;
			case 1:
				note = new Note(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, pos, vel);
				break;
			case 2:
				note = new Note(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, pos, vel);
				break;
			case 3:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, pos, vel);
				break;
			case 4:
				note = new Note(SDL_CONTROLLER_BUTTON_A, manager, 75, 75, pos, vel);
				break;
			case 5:
				note = new Note(SDL_CONTROLLER_BUTTON_B, manager, 75, 75, pos, vel);
				break;
			case 6:
				note = new Note(SDL_CONTROLLER_BUTTON_X, manager, 75, 75, pos, vel);
				break;
			case 7:
				note = new Note(SDL_CONTROLLER_BUTTON_Y, manager, 75, 75, pos, vel);
				break;
			}
			levelButtons_.push_front(note);
		}
	}
}

void MinigameRock::deleteList()
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
