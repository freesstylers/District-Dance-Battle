#include "PlayState2P.h"
#include "GameManager.h"

PlayState2P::PlayState2P(GameManager* g) :PlayState(g) //Asigna game y llama a inicializaci�n
{
	newGame();
}

void PlayState2P::newGame()
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
	lip = new LevelInputManager(static_cast<PlayState*>(this),0);
	perico = new Perico(manager, 200, 400, Vector2D(70, 130), Resources::PericoIdle);
	leftNoteBar = new Squares(manager, pointSize + 10, 575, Vector2D(leftNotesVector.getX() - 19, leftNotesVector.getY()));
	rightNoteBar = new Squares(manager, pointSize + 10, 575, Vector2D(rightNotesVector.getX() - 19, rightNotesVector.getY()));

	bh = new BeatHandeler(nivel->bpm);

	/*barraPuntos = new BarraPuntos(manager, 20, 20, Vector2D(20, 100), nivel->numNotas, 100);
	spriteBarra = new FondoBarra(manager, 20, 20, Vector2D(20, 25), nivel->songLength / (manager->getWindowWidth() - 40 + 50), Resources::Bar);*/
	indicador = new BarrasHUD(manager, 50, 50, Vector2D(20, 10), Vector2D(nivel->songLength / (manager->getWindowWidth() - 40 + 50), 0), spriteBarra); //0.3 va a depender de la duracion de la cancion

	qteman = new QTEManager(manager, nivel->probqte);

	effectVaporWave = new EmptyObject(manager, Vector2D(0, 0), Resources::EffectVaporWave, manager->getWindowWidth(), manager->getWindowHeight());

	stage.push_back(bg);
	stage.push_back(leftNoteBar);
	stage.push_back(rightNoteBar);
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


PlayState2P::~PlayState2P()
{
}

void PlayState2P::update(Uint32 time)
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
	if (timer->DeltaTime() < (bh->getBeatTime() / 1000) + 0.010 && timer->DeltaTime() > (bh->getBeatTime() / 1000) - 0.010)
	{
		generateFlechas();
		generateBotones();
		timer->Reset();

		beatSignal = true;
	}
	else if (timer->DeltaTime() < (bh->getBeatTime() / animationFramesPerBeat / 1000) + 0.010 && timer->DeltaTime() > (bh->getBeatTime() / animationFramesPerBeat / 1000) - 0.010)
	{
		//aqu� se divide el beatTime lo necesario para animar las frames especificadas entre cada beat

		beatSignal = true;
	}
}

bool PlayState2P::handleEvent(Uint32 time, SDL_Event e)
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

void PlayState2P::render(Uint32 time, bool beatSync)
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
	if (!effect)
		effectVaporWave->render(time, beatSync);
	beatSignal = false;
}

void PlayState2P::DeleteAll()
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

void PlayState2P::generateFlechas()
{
	if (!flechasNivel_.empty()) {
		if (flechasNivel_.back() != nullptr) {
			flechasPantalla_.push_back(flechasNivel_.back());
		}
		flechasNivel_.pop_back();
	}
}

void PlayState2P::generateBotones()
{
	if (!botonesNivel_.empty()) {
		if (botonesNivel_.back() != nullptr) {
			botonesPantalla_.push_back(botonesNivel_.back());
		}
		botonesNivel_.pop_back();
	}
}