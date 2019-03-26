#include "PlayState2P.h"
#include "GameManager.h"

PlayState2P::PlayState2P(GameManager* g) :PlayState(g)
{
	newGame();
}

void PlayState2P::newGame()
{
	/*
	Inicializar:
	Barra de puntuacion
	Barra de la cancion
	Character
	Enemigo
	Fondo
	Cancion
	Note
	Pulsador/Logica de botones
	*/

	levelName = "prueba";

	int leftNotesPos = manager->getDefaultWindowWidth() / 2 - pointOffset;
	int rightNotesPos = manager->getDefaultWindowWidth() / 2 + pointOffset;
	leftNotesVector = Vector2D(leftNotesPos - noteSize / 2, initialNoteHeight);
	rightNotesVector = Vector2D(rightNotesPos - noteSize / 2, initialNoteHeight);

	leftPoint = new Point(manager, pointSize, pointSize, Vector2D(leftNotesPos - pointSize / 2, 465));
	rightPoint = new Point(manager, pointSize, pointSize, Vector2D(rightNotesPos - pointSize / 2, 465));
	feedbackLeft = new FeedbackPool(manager, pointSize, pointSize, Vector2D(leftNotesPos - pointSize / 2 - 100, 465));
	feedbackRight = new FeedbackPool(manager, pointSize, pointSize, Vector2D(rightNotesPos - pointSize / 2 + 100, 465));
	bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0));
	level = new Level(this, manager, levelName);
	level->init();
	timer = Timer::Instance();
	lip = new LevelInputManager(static_cast<PlayState*>(this),0);
	perico = new Character(manager, 200, 400, Vector2D(70, 130), Resources::PericoIdle);
	leftNoteBar = new Squares(manager, pointSize + 10, 575, Vector2D(leftNotesVector.getX() - 19, leftNotesVector.getY()));
	rightNoteBar = new Squares(manager, pointSize + 10, 575, Vector2D(rightNotesVector.getX() - 19, rightNotesVector.getY()));

	bh = new BeatHandeler(level->bpm);

	/*scoreBar = new ScoreBar(manager, 20, 20, Vector2D(20, 100), levelName->noteAmount, 100);
	songBarBG = new BarBackground(manager, 20, 20, Vector2D(20, 25), levelName->songLength / (manager->getDefaultWindowWidth() - 40 + 50), Resources::Bar);*/
	songBar = new SongBar(manager, 50, 50, Vector2D(20, 10), Vector2D(level->songLength / (manager->getDefaultWindowWidth() - 40 + 50), 0), songBarBG); //0.3 va a depender de la duracion de la cancion


	effectVaporWave = new EmptyObject(manager, Vector2D(0, 0), Resources::EffectVaporWave, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight());

	stage.push_back(bg);
	stage.push_back(leftNoteBar);
	stage.push_back(rightNoteBar);
	stage.push_back(leftPoint);
	stage.push_back(rightPoint);
	stage.push_back(perico);
	stage.push_back(scoreBar);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	stage.push_back(feedbackLeft);
	stage.push_back(feedbackRight);



	level->playSong();

	/////////////////////////

	//exit_ = false;

}


PlayState2P::~PlayState2P()
{
}

void PlayState2P::update(Uint32 time)
{
	GameState::update(time);

	for (Note* o : screenArrows_)
	{
		o->update(time);
	}
	for (Note* o : screenButtons_)
	{
		o->update(time);
	}
	//qteman->update(time);
	if (!screenArrows_.empty() && screenArrows_.front()->getPosition().getY() > 550)
	{
		Note* aux = screenArrows_.front();

		screenArrows_.pop_front();
		cout << "fuera" << endl;
		feedbackLeft->queueAnimationChange(Resources::FeedbackBad);
		delete aux;
	}
	if (!screenButtons_.empty() && screenButtons_.front()->getPosition().getY() > 550)
	{
		Note* aux = screenButtons_.front();

		screenButtons_.pop_front();
		cout << "fuera" << endl;

		feedbackRight->queueAnimationChange(Resources::FeedbackBad);
		delete aux;
	}
	timer->Update();
	if (timer->DeltaTime() < (bh->getBeatTime() / 1000) + 0.010 && timer->DeltaTime() > (bh->getBeatTime() / 1000) - 0.010)
	{
		generateArrows();
		generateButtons();
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

		GameState::handleEvent(time, e);
		return false;
	}
}

void PlayState2P::render(Uint32 time, bool beatSync)
{

	GameState::render(time, beatSignal);

	for (Note* o : screenArrows_)
	{
		o->render(time, beatSignal);
	}
	for (Note* o : screenButtons_)
	{
		o->render(time, beatSignal);
	}
	if (!effect)
		effectVaporWave->render(time, beatSync);
	beatSignal = false;
}

void PlayState2P::deleteAll()
{
	for (GameObject* o : stage)
	{
		delete o;
	}

	for (Note* o : screenArrows_)
	{
		delete o;
	}

	for (Note* o : levelArrows_) //Por si se cierra el levelName antes de que acabe
	{
		delete o;
	}
}

void PlayState2P::generateArrows()
{
	if (!levelArrows_.empty()) {
		if (levelArrows_.back() != nullptr) {
			screenArrows_.push_back(levelArrows_.back());
		}
		levelArrows_.pop_back();
	}
}

void PlayState2P::generateButtons()
{
	if (!levelButtons_.empty()) {
		if (levelButtons_.back() != nullptr) {
			screenButtons_.push_back(levelButtons_.back());
		}
		levelButtons_.pop_back();
	}
}