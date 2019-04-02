#include "PlayState.h"
#include "GameManager.h"

PlayState::PlayState(GameManager* g,int lvl) :GameState(g) //Asigna game y llama a inicializaci�n
{
	newGame(lvl);
}

void PlayState::newGame(int lvl)
{
	switch (lvl)
	{
	case 0:
		levelName = "prueba";
		effectVaporWave = new EmptyObject(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::EffectVaporWave);
		minigame = new MinigameVaporwave(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		robot = new Character(manager, 60 * 3.5, 120 * 3.5, Vector2D(manager->getDefaultWindowWidth() - 270, initialNoteHeight + 70), Resources::RobotIdle);
		break;
	default:
		break;
	}
	

	int leftNotesPos = manager->getDefaultWindowWidth() / 2 - pointOffset;
	int rightNotesPos = manager->getDefaultWindowWidth() / 2 + pointOffset;

	leftNotesVector = Vector2D(leftNotesPos - noteSize / 2, initialNoteHeight);
	rightNotesVector = Vector2D(rightNotesPos - noteSize / 2, initialNoteHeight);

	leftNotesVector2 = Vector2D(leftNotesPos - 50 / 2 + 200, 70);
	rightNotesVector2 = Vector2D(rightNotesPos - 50 / 2 + 200, 70);
	player1 = new PlayerPack(manager,this, leftNotesPos, rightNotesPos, pointSize, noteBarWidth);
	feedbackLeft = new FeedbackPool(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(leftNotesPos - (pointSize * 0.8) - (pointSize * 0.8), 465 + pointSize / 2));
	feedbackRight = new FeedbackPool(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(rightNotesPos + (pointSize * 0.8), 465 + pointSize / 2));
	
	level = new Level(this, manager, levelName);
	level->init();
	player2 = nullptr;
	timer = Timer::Instance();
	lip = new LevelInputManager(this, player1, 0);
	maxNoteValue = maxScore / level->noteAmount;

	scoreBar = new ScoreBar(manager, 20, 1, Vector2D(50, 465 + pointSize), level->noteAmount, maxScore);

	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), (((manager->getDefaultWindowWidth() - 50) / level->songLength) / 70.5), Resources::YellowBar); //70.5 es la constante para ajustar la velocidad de la barra al tiempo de la cancion
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31), Vector2D((((manager->getDefaultWindowWidth() / level->songLength)) / 70.5), 0), songBarBG);

	perico = new Character(manager, 60 * 3.5, 120 * 3.5, Vector2D(75, initialNoteHeight + 70), Resources::PericoIdle);
	
	
	
	minigameController = new TimerNoSingleton();

	bh = new BeatHandler(level->bpm);

	


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

	//exit_ = false;

	updateResolution();
}

void PlayState::newGame2P(int lvl)
{
	levelName = "prueba";

	int leftNotesPos = manager->getWindowWidth() / 3 - pointOffset2P;
	int rightNotesPos = manager->getWindowWidth() / 3 + pointOffset2P;

	leftNotesVector = Vector2D(leftNotesPos - 50 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 50 / 2, 70);

	leftNotesVector2 = Vector2D(leftNotesPos - 50 / 2 + 200, 70);
	rightNotesVector2 = Vector2D(rightNotesPos - 50 / 2 + 200, 70);

	bg = new Background(manager, manager->getWindowWidth(), manager->getWindowHeight(), Vector2D(0, 0),Resources::testBG);
	player1 = new PlayerPack(manager,this, leftNotesPos, rightNotesPos, pointSize2P, noteBarWidth*0.75);
	player2 = new PlayerPack(manager,this, leftNotesPos + 200, rightNotesPos + 200, pointSize2P, noteBarWidth*0.75);
	level = new Level(this, manager, levelName);
	level->init();
	timer = Timer::Instance();
	lip = new LevelInputManager(this, player1, 0);
	if (player2 != nullptr)
		lip2 = new LevelInputManager(this, player2, 1);
	maxNoteValue = maxScore / level->noteAmount;

	scoreBar = new ScoreBar(manager, 20, 1, Vector2D(50, 465 + pointSize), level->noteAmount, maxScore);

	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), (((manager->getWindowWidth() - 50) / level->songLength) / 70.5), Resources::YellowBar); //70.5 es la constante para ajustar la velocidad de la barra al tiempo de la cancion
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31), Vector2D((((manager->getWindowWidth() / level->songLength)) / 70.5), 0), songBarBG);

	perico = new Character(manager, 60 * 3.5, 120 * 3.5, Vector2D(75, initialNoteHeight + 30 + 70), Resources::PericoIdle);
	robot = new Character(manager, 60 * 3.5, 120 * 3.5, Vector2D(manager->getWindowWidth() - 270, initialNoteHeight - 29 + 70), Resources::RobotIdle);

	minigame = new MinigameVaporwave(manager, this);
	minigameController = new TimerNoSingleton();

	bh = new BeatHandler(level->bpm);

	effectVaporWave = new EmptyObject(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::EffectVaporWave);

	stage.push_back(bg);
	stage.push_back(player1);
	stage.push_back(player2);
	stage.push_back(perico);
	stage.push_back(robot);
	stage.push_back(scoreBar);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	//stage.push_back(feedbackLeft);
	//stage.push_back(feedbackRight);



	level->playSong();

	updateResolution();
}

PlayState::~PlayState()
{
	deleteAll();
	delete lip;
	delete lip2;
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
			robot->forceAnimationChange(Resources::RobotDance);
			perico->forceAnimationChange(Resources::PericoDance1);
			animationMiniGame = true;
			minigame->resetMinigame();
		}
		minigame->update(time);
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

			minigame->handleInput(time, e);
		}
		else
		{
			lip->handleInput(time, e);
			if (lip2 != nullptr)
				lip2->handleInput(time, e);
			GameState::handleEvent(time, e);
		}
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
			
			if (player2 != nullptr && levelArrows2_.front()!=nullptr)
			{
				player2->screenArrows_.push_back(levelArrows2_.front());
				player2->screenArrows_.back()->setPosition(player2->screenArrows_.back()->getPosition() + player2->screenArrows_.back()->getVelocity()*msDiff);
			}
		}
		levelArrows2_.pop_front();
		levelArrows_.pop_front();
	}
}

void PlayState::generateButtons()
{
	if (!levelButtons_.empty()) {
		if (levelButtons_.front() != nullptr) {
			player1->screenButtons_.push_back(levelButtons_.front());
			player1->screenButtons_.back()->setPosition(player1->screenButtons_.back()->getPosition() + player1->screenButtons_.back()->getVelocity()*msDiff);
			if (player2 != nullptr && levelButtons2_.front() != nullptr)
			{
				player2->screenButtons_.push_back(levelButtons2_.front());
				player2->screenButtons_.back()->setPosition(player2->screenButtons_.back()->getPosition() + player2->screenButtons_.back()->getVelocity()*msDiff);
			}
		}
		levelButtons_.pop_front();
		levelButtons2_.pop_front();
	}
}


void PlayState::songOver()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->pushState(new EndState(manager, currentScore, maxScore, 70));
}

void PlayState::updateResolution()
{
	GameState::updateResolution();

	double wScale = manager->getWidthScale();
	double hScale = manager->getHeightScale();

	minigame->updateResolution(wScale, hScale);
	Vector2D noteVel = setVel(60000 / level->bpm);

	for (Note* n : levelArrows_) {
		if (n != nullptr){
			n->updateResolution(wScale, hScale);
			n->setVelocity(noteVel);
		}
	}
	for (Note* n : levelButtons_) {
		if (n != nullptr) {
			n->updateResolution(wScale, hScale);
			n->setVelocity(noteVel);
		}
	}
	for (Note* n : levelArrows2_) {
		if (n != nullptr) {
			n->updateResolution(wScale, hScale);
			n->setVelocity(noteVel);
		}
	}
	for (Note* n : levelButtons2_) {
		if (n != nullptr) {
			n->updateResolution(wScale, hScale);
			n->setVelocity(noteVel);
		}
	}

	initialNoteHeight = initialNoteHeight * hScale;
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
