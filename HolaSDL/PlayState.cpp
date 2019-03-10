#include "PlayState.h"
#include "GameManager.h"

PlayState::PlayState(GameManager* g) :GameState(g) //Asigna game y llama a inicializaci�n
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

	level = "prueba";

	int leftNotesPos = manager->getWindowWidth() / 2 - pointOffset;
	int rightNotesPos = manager->getWindowWidth() / 2 + pointOffset;

	leftNotesVector = Vector2D(leftNotesPos - noteSize / 2, initialNoteHeight);
	rightNotesVector = Vector2D(rightNotesPos - noteSize / 2, initialNoteHeight);

	leftPoint = new Point(manager, pointSize, pointSize, Vector2D(leftNotesPos - pointSize / 2, 465));
	rightPoint = new Point(manager, pointSize, pointSize, Vector2D(rightNotesPos - pointSize / 2, 465));
	feedbackLeft = new Feedback(manager, pointSize, pointSize, Vector2D(leftNotesPos - pointSize / 2 - 100, 465));
	feedbackRight = new Feedback(manager, pointSize, pointSize, Vector2D(rightNotesPos - pointSize / 2 + 100, 465));
	bg = new Background(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(0, 0));
	nivel = new Level(this, manager, level);
	nivel->init();
	timer = Timer::Instance();
	lip = new LevelInputManager(this,0);

	barraPuntos = new BarraPuntos(manager, 20, 1, Vector2D(20, 500), nivel->numNotas, 2000);
	spriteBarra = new FondoBarra(manager, 20, 20, Vector2D(20, 25), (((manager->getWindowWidth() / nivel->songLength)) / 70.5), Resources::Bar); //70.5 es la constante para ajustar la velocidad de la barra al tiempo de la cancion
	indicador = new BarrasHUD(manager, 50, 50, Vector2D(20, 10), Vector2D((((manager->getWindowWidth() / nivel->songLength)) / 70.5), 0), spriteBarra);

	perico = new Perico(manager, 200, 400, Vector2D(70, 130));
	leftSquare = new Squares(manager, pointSize + 10, 575, Vector2D(leftNotesVector.getX() - 19, leftNotesVector.getY()));
	rightSquare = new Squares(manager, pointSize + 10, 575, Vector2D(rightNotesVector.getX() - 19, rightNotesVector.getY()));
	
	lip->setMinigameActive(true);
	minigame = new MiniGame(manager, this);
	minigameController = new TimerNoSingleton();

	bh = new BeatHandeler(nivel->bpm);

	qteman = new QTEManager(manager, nivel->probqte);

	effectVaporWave = new EmptyObject(manager, Vector2D(0, 0), Resources::EffectVaporWave, manager->getWindowWidth(), manager->getWindowHeight());

	stage.push_back(bg);
	stage.push_back(leftSquare);
	stage.push_back(rightSquare);
	stage.push_back(leftPoint);
	stage.push_back(rightPoint);
	stage.push_back(perico);
	stage.push_back(barraPuntos);
	stage.push_back(spriteBarra);
	stage.push_back(indicador);
	stage.push_back(feedbackLeft);
	stage.push_back(feedbackRight);



	nivel->playSong();

	/////////////////////////

	//exit_ = false;
}


PlayState::~PlayState()
{
	DeleteAll();
	delete lip;
	delete bh;
	delete qteman;
	delete effectVaporWave;
	delete nivel;
}

void PlayState::update(Uint32 time)
{
	GameState::update(time);
	if (!miniActive) 
	{
		for (Flechas* o : flechasPantalla_)
		{
			o->update(time);
		}
		for (Flechas* o : botonesPantalla_)
		{
			o->update(time);
		}
		//qteman->update(time);
		if (!flechasPantalla_.empty() && flechasPantalla_.front()->getPosition().getY() > 550)
		{
			Flechas* aux = flechasPantalla_.front();

			flechasPantalla_.pop_front();
			cout << "fuera" << endl;
			feedbackLeft->queueAnimationChange(Resources::FeedbackBad);
			delete aux;
		}
		if (!botonesPantalla_.empty() && botonesPantalla_.front()->getPosition().getY() > 550)
		{
			Flechas* aux = botonesPantalla_.front();

				botonesPantalla_.pop_front();
				cout << "fuera" << endl;

			feedbackRight->queueAnimationChange(Resources::FeedbackBad);
			delete aux;
		}
		timer->Update();
		if (timer->DeltaTime() > (bh->getBeatTime() / 1000.0) - msDiff)
		{
			msDiff += timer->DeltaTime() - (bh->getBeatTime() / 1000.0);
			generateFlechas();
			generateBotones();
			timer->Reset();

			beatSignal = true;
		}
		else if (timer->DeltaTime() > ((bh->getBeatTime() / 1000.0) / (animationFramesPerBeat / 1000)) - msDiff)
		{
			//aqu� se divide el beatTime lo necesario para animar las frames especificadas entre cada beat

			beatSignal = true;
		}
	}
	else {
		minigame->update(time);
		lip->update();
		if (minigame->getFallado()) {
			lip->setMinigameActive(false);
			miniActive = false;
			msDiff = 0;
			timer->Reset();
		}
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
		if (miniActive) {
			lip->setMinigameActive(true);
		}
		
		
			lip->handleInput(time, e);
			//qteman->handleInput(time, e);
			GameState::handleEvent(time, e);
		
		return false;
	}
}

void PlayState::render(Uint32 time, bool beatSync)
{

	GameState::render(time, beatSignal);

	qteman->render(time, beatSignal);

	for (Flechas* o : flechasPantalla_)
	{
		o->render(time, beatSignal);
	}
	for (Flechas* o : botonesPantalla_)
	{
		o->render(time, beatSignal);
	}
	if (miniActive) {
		minigame->render(time);
		effectVaporWave->render(time, beatSync);
	}

	beatSignal = false;
}

void PlayState::DeleteAll()
{
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

//Al generar las flechas y los botones, los mueve en proporcion al tiempo perdido por cada vuelta
void PlayState::generateFlechas()
{
	if (!flechasNivel_.empty()) {
		if (flechasNivel_.front() != nullptr) {
			flechasPantalla_.push_back(flechasNivel_.front());
			flechasPantalla_.back()->setPosition(flechasPantalla_.back()->getPosition() + flechasPantalla_.back()->getVelocity()*msDiff);
		}
		flechasNivel_.pop_front();
	}
}

void PlayState::generateBotones()
{
	if (!botonesNivel_.empty()) {
		if (botonesNivel_.front() != nullptr) {
			botonesPantalla_.push_back(botonesNivel_.front());
			botonesPantalla_.back()->setPosition(botonesPantalla_.back()->getPosition() + botonesPantalla_.back()->getVelocity()*msDiff);
		}
		botonesNivel_.pop_front();
	}
}

Vector2D PlayState::asignaVel(double time)
{
	double distance = leftPoint->getPosition().getY() - initialNoteHeight + 25.0; //El 25 es la mitad de la altura de la flecha/boton
	double velocity = distance / (time / 1000.0);
	return Vector2D(0, velocity / 4.0);
}

void PlayState::playSong(int song) {
	manager->getServiceLocator()->getAudios()->playChannel(song, 0);
	manager->getServiceLocator()->getAudios()->setChannelVolume(70);
}