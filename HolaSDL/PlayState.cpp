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

	cin >> level;

	timer = Timer::Instance();
	punto = new Point(manager, 80, 80, Vector2D(300, 465));
	puntobot = new Point(manager, 80, 80, Vector2D(500, 465));
	lip = new LevelInputManager(this);
	perico = new Perico(manager, 33, 33, Vector2D(100, 50));
	nivel = new Level(this, level);

	bh = new BeatHandeler(nivel->bpm);
	qteman = new QTEManager(this, nivel->probqte);

	stage.push_back(punto);
	stage.push_back(puntobot);
	stage.push_back(perico);


	/////////////////////////

	//exit_ = false;
	playSong(nivel->song);
	
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
	for (Flechas* o : botonesPantalla_)
	{
		o->update(time);
	}
	qteman->update(time);
	if (!flechasPantalla_.empty() && flechasPantalla_.front()->getPosition().getY() > 550)
	{

		flechasPantalla_.pop_front();
		cout << "fuera" << endl;

	}
	if (!botonesPantalla_.empty() && botonesPantalla_.front()->getPosition().getY() > 550)
	{

		botonesPantalla_.pop_front();
		cout << "fuera" << endl;

	}
	timer->Update();
	if (timer->DeltaTime() < (bh->getBeatTime() / 1000) + 0.010 && timer->DeltaTime() > (bh->getBeatTime() / 1000) - 0.010)
	{
		generateFlechas();
		generateBotones();
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

	for (Flechas* o : botonesPantalla_)
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

void PlayState::generateFlechas()
{
	if (!flechasNivel_.empty()) {
		if (flechasNivel_.back() != nullptr) {
			flechasPantalla_.push_back(flechasNivel_.back());
			flechasNivel_.pop_back();
		}
		else flechasNivel_.pop_back();
	}
}

void PlayState::generateBotones()
{
	if (!botonesNivel_.empty()) {
		if (botonesNivel_.back() != nullptr) {
			botonesPantalla_.push_back(botonesNivel_.back());
			botonesNivel_.pop_back();
		}
		else botonesNivel_.pop_back();
	}
}

Vector2D PlayState::asignaVel(double time)
{
	double distance = posFlechaInicial.getY() - (punto->getPosition().getY());
	double velocity = distance / bh->getBeatTime();
	return Vector2D(0, -velocity * 4);
}

void PlayState::playSong(int song) {
	manager->getServiceLocator()->getAudios()->playChannel(song, -1);
	manager->getServiceLocator()->getAudios()->setChannelVolume(70);
}