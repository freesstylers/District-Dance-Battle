#include "PlayState.h"
#include "GameManager.h"

PlayState::PlayState(GameManager* g) :GameState(g) //Asigna game y llama a inicializaci�n
{
	newGame();
}

void PlayState::newGame()
{

	levelName = "prueba";

	int leftNotesPos = manager->getWindowWidth() / 2 - pointOffset;
	int rightNotesPos = manager->getWindowWidth() / 2 + pointOffset;

	leftNotesVector = Vector2D(leftNotesPos - 50 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 50 / 2, 70);

	feedbackLeft = new Feedback(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(leftNotesPos - (pointSize * 0.8) - (pointSize * 0.8), 465 + pointSize / 2));
	feedbackRight = new Feedback(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(rightNotesPos + (pointSize * 0.8), 465 + pointSize / 2));
	bg = new Background(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(0, 0));
	player1 = new PlayerPack(manager, leftNotesPos, rightNotesPos, pointSize, noteBarWidth);
	level = new Level(this, manager, levelName);
	level->init();
	timer = Timer::Instance();
	lip = new LevelInputManager(this, player1, 0);
	maxNoteValue = maxScore / level->noteAmount;

	scoreBar = new ScoreBar(manager, 20, 1, Vector2D(50, 465 + pointSize), level->noteAmount, maxScore);

	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), (((manager->getWindowWidth() - 50) / level->songLength) / 70.5), Resources::YellowBar); //70.5 es la constante para ajustar la velocidad de la barra al tiempo de la cancion
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31), Vector2D((((manager->getWindowWidth() / level->songLength)) / 70.5), 0), songBarBG);

	perico = new Character(manager, 60 * 3.5, 120 * 3.5, Vector2D(75, initialNoteHeight + 30 + 70), Resources::PericoIdle);
	robot = new Character(manager, 60 * 3.5, 120 * 3.5, Vector2D(manager->getWindowWidth() - 270, initialNoteHeight - 29 + 70), Resources::RobotIdle);
	
	minigame = new MiniGame(manager, this);
	minigameController = new TimerNoSingleton();

	bh = new BeatHandeler(level->bpm);

	effectVaporWave = new EmptyObject(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::EffectVaporWave);

	stage.push_back(bg);
	stage.push_back(player1);
	stage.push_back(perico);
	stage.push_back(robot);
	stage.push_back(scoreBar);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	stage.push_back(feedbackLeft);
	stage.push_back(feedbackRight);



	level->playSong();

	/////////////////////////
}


PlayState::~PlayState()
{
	deleteAll();
	delete lip;
	delete bh;
	delete effectVaporWave;
	delete level;
	delete minigame;
	delete minigameController;
}

void PlayState::update(Uint32 time)
{
	GameState::update(time);
	if (!miniActive && minigameController->DeltaTime() < level->songLength/3) 
	{
		minigameController->Update();
		if (levelArrows_.empty() && levelButtons_.empty()) {
			songOver();
		}
		else {
			timer->Update();
			if (timer->DeltaTime() > (bh->getBeatTime() / 1000.0) - msDiff)
			{
				msDiff += timer->DeltaTime() - (bh->getBeatTime() / 1000.0);
				generateArrows();
				generateButtons();
				timer->Reset();

				beatSignal = true;
			}
		}
	}
	else {
		miniActive=true;
		if (!animationMiniGame)
		{
			lip->setMinigameActive(true);
			robot->queueAnimationChange(Resources::RobotDance);
			perico->queueAnimationChange(Resources::PericoDance1);
			animationMiniGame = true;
		}
		minigame->update(time);
		lip->update();
		if (minigame->getFailed()) {
			lip->setMinigameActive(false);
			miniActive = false;
			msDiff = 0;
			timer->Reset();
			minigame->deleteList();
			minigame->createList();
			minigameController->Reset();
			robot->queueAnimationChange(Resources::RobotIdle);
			perico->queueAnimationChange(Resources::PericoIdle);
			animationMiniGame = false;
		}
	}
	if (timer->DeltaTime() > ((bh->getBeatTime() / 1000.0) / (animationFramesPerBeat / 1000)) - msDiff)
		{
		//aqu� se divide el beatTime lo necesario para animar las frames especificadas entre cada beat

		beatSignal = true;
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
			GameState::handleEvent(time, e);
		
		return false;
	}
}

void PlayState::render(Uint32 time, bool beatSync)
{

	GameState::render(time, beatSignal);
	if (miniActive) {
		minigame->render(time);
		effectVaporWave->render(time, beatSync);
	}

	beatSignal = false;
}

void PlayState::deleteAll()
{
	for (Note* o : levelArrows_) //Por si se cierra el levelName antes de que acabe
	{
		delete o;
	}
}

int PlayState::getScore()
{
	return currentScore;
}

//Al generar las flechas y los botones, los mueve en proporcion al tiempo perdido por cada vuelta
void PlayState::generateArrows()
{
	if (!levelArrows_.empty()) {
		if (levelArrows_.front() != nullptr) {
			player1->screenArrows_.push_back(levelArrows_.front());
			player1->screenArrows_.back()->setPosition(player1->screenArrows_.back()->getPosition() + player1->screenArrows_.back()->getVelocity()*msDiff);
		}
		levelArrows_.pop_front();
	}
}

void PlayState::generateButtons()
{
	if (!levelButtons_.empty()) {
		if (levelButtons_.front() != nullptr) {
			player1->screenButtons_.push_back(levelButtons_.front());
			player1->screenButtons_.back()->setPosition(player1->screenButtons_.back()->getPosition() + player1->screenButtons_.back()->getVelocity()*msDiff);
		}
		levelButtons_.pop_front();
	}
}

void PlayState::songOver()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->pushState(new EndState(manager, currentScore, maxScore, 70));
}

Vector2D PlayState::setVel(double time)
{
	double distance = player1->getLeftPoint()->getPosition().getY() + player1->getLeftPoint()->getHeight()/2 - initialNoteHeight - 25.0; //El 25 es la mitad de la altura de la note/boton
	double velocity = distance / (time / 1000.0);
	return Vector2D(0, velocity / 8.0);
}

void PlayState::playSong(int song) {
	manager->getServiceLocator()->getAudios()->playChannel(song, 0);
	manager->getServiceLocator()->getAudios()->setChannelVolume(70);
}

void PlayState::showError()
{
	bg->cleanAnimationQueue();

	bg->forceAnimationChange(Resources::PixelatedTextBG);
	bg->queueAnimationChange(Resources::testBG);
	manager->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0);
}