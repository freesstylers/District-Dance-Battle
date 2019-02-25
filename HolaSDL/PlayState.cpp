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

	timer = Timer::Instance();
	punto = new Point(manager, 80, 80, Vector2D(360, 465));
	lip = new LevelInputManager(this);
	perico = new Perico(manager, 33, 33, Vector2D(100, 50));

	cin >> level;

	ifstream file("resources/levels/" + level + ".txt");

	file >> bpm;
	file >> probqte;

	bh = new BeatHandeler(bpm);
	qteman = new QTEManager(manager, probqte);

	velFlechas = asignaVel(bh->getBeatTime());


	int aux;
	Flechas* flecha;
	for (int i = 0; i < 25; i++) {
		file >> aux;
		switch (aux) {
		case 1:
			flecha = new Flechas(SDLK_LEFT, manager, 50, 50, posFlechaInicial, velFlechas);
			break;
		case 2:
			flecha = new Flechas(SDLK_RIGHT, manager, 50, 50, posFlechaInicial, velFlechas);
			break;
		case 3:
			flecha = new Flechas(SDLK_UP, manager, 50, 50, posFlechaInicial, velFlechas);
			break;
		case 4:
			flecha = new Flechas(SDLK_DOWN, manager, 50, 50, posFlechaInicial, velFlechas);
			break;
		}
		flechasNivel_.push_back(flecha);
	}
	file.close();


	stage.push_back(punto);
	stage.push_back(perico);



	/////////////////////////

	//exit_ = false;
	manager->getServiceLocator()->getAudios()->playChannel(Resources::Pruebas, -1);
	manager->getServiceLocator()->getAudios()->setChannelVolume(70);
}


PlayState::~PlayState()
{
}

void PlayState::update(Uint32 time)
{
	GameState::update(time);

	for (Flechas* o : flechasPantalla_)
	{
		o->update(time);
	}
	qteman->update(time);
	if (!flechasPantalla_.empty() && flechasPantalla_.front()->getPosition().getY() > 550)
	{

		flechasPantalla_.pop_front();
		cout << "fuera" << endl;

	}
	timer->Update();
	if (timer->DeltaTime() < (bh->getBeatTime() / 1000) + 0.010 && timer->DeltaTime() > (bh->getBeatTime() / 1000) - 0.010)
	{
		generate();
		timer->Reset();
	}
}

bool PlayState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
		manager->stop();
	}
	// Pressing f to toggle fullscreen.
	else if (e.key.keysym.sym == SDLK_f)
	{
		int flags = SDL_GetWindowFlags(manager->getWindow());
		if (flags & SDL_WINDOW_FULLSCREEN) {
			SDL_SetWindowFullscreen(manager->getWindow(), 0);
		}
		else {
			SDL_SetWindowFullscreen(manager->getWindow(), SDL_WINDOW_FULLSCREEN);
		}
	}
	else
	{
		lip->handleInput(time, e);
		qteman->handleInput(time, e);

		GameState::handleEvent(time, e);
		return false;
	}
}

void PlayState::render(Uint32 time)
{
	GameState::render(time);

	qteman->render(time);

	for (Flechas* o : flechasPantalla_)
	{
		o->render(time);
	}
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

void PlayState::generate()
{
	if (!flechasNivel_.empty()) {
		if (flechasNivel_.back() != nullptr) {
			flechasPantalla_.push_back(flechasNivel_.back());
			flechasNivel_.pop_back();
		}
		else flechasNivel_.pop_back();
	}
}

Vector2D PlayState::asignaVel(double time)
{
	double distance = posFlechaInicial.getY() - (punto->getPosition().getY());
	double velocity = distance / bh->getBeatTime();
	return Vector2D(0, -velocity * 4);
}
