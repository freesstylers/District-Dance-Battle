#include "PlayState.h"
#include "GameManager.h"

PlayState::PlayState(GameManager* g) :GameState(g) //Asigna game y llama a inicialización
{
	newGame();
}

void PlayState::newGame() 
{
	/*
	Inicializar:

	Barra de puntuacion
	Barra de la cancion
	Perico
	Enemigo
	Fondo
	Cancion
	Flechas
	Pulsador/Logica de botones
	*/



	ifstream file("resources/levels/prueba.txt");
	int aux;
	Flechas* flecha;
	for (int i = 0; i < 25; i++) {
		file >> aux;
		switch (aux) {
		case 1:
			flecha = new Flechas(SDLK_LEFT, manager->getGame(), 50, 50, Vector2D(700, 350), Vector2D(-5, 0));
			break;
		case 2:
			flecha = new Flechas(SDLK_RIGHT, manager->getGame(), 50, 50, Vector2D(700, 350), Vector2D(-5, 0));
			break;
		case 3:
			flecha = new Flechas(SDLK_UP, manager->getGame(), 50, 50, Vector2D(700, 350), Vector2D(-5, 0));
			break;
		case 4:
			flecha = new Flechas(SDLK_DOWN, manager->getGame(), 50, 50, Vector2D(700, 350), Vector2D(-5, 0));
			break;
		}
		flechasNivel_.push_back(flecha);
	}
	file.close();

	timer = Timer::Instance();
	punto = new Point(manager->getGame(), 80, 80, Vector2D(100, 330));
	bh = new BeatHandeler(112);
	bh->getBeatTime();

	stage.push_back(punto);

	/////////////////////////

	//exit_ = false;
	manager->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Pruebas, -1);
	manager->getGame()->getServiceLocator()->getAudios()->setChannelVolume(70);
	while (!manager->checkExit()) {
		Uint32 startTime = SDL_GetTicks();
		//handleEvent(SDL_Event e); ESTO HAY QUE MIRARLO
		update(startTime);
		render(startTime);

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}


PlayState::~PlayState()
{
}

void PlayState::update(Uint32 time)
{
	//GameState::update();
}

bool PlayState::handleEvent(SDL_Event e)
{
	/*if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
		cout << "Menu de pausa" << endl;
		app->getMachine()->pushState(new PauseState(app));
		return true;
	}
	else {

		if (e.type == SDL_QUIT) {
			game->exit();
			return true;
		}

		if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
			paddle->handleEvents(e);
			return true;
		}
	}
	*/
	return false;
}

void PlayState::DeleteAll()
{
	for (GameObject* o : stage) 
	{
		delete o;
	}

	for (Flechas* o : flechasPantalla_)
	{
		delete o;
	}

	for (Flechas* o : flechasNivel_) //Por si se cierra el nivel antes de que acabe
	{
		delete o;
	}
}

int PlayState::getPoints()
{
	return currentPoints;
}

void PlayState::changePoints(int data)
{
	currentPoints = currentPoints + data;
}

/*GameManager* PlayState::getGameManager()
{
	return gameManager;
}*/
