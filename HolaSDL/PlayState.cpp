#include "PlayState.h"
#include "GameManager.h"

PlayState::PlayState(GameManager* g, int lvl, bool oneP, bool diff) : GameState(g) //Asigna game y llama a inicializaci�n
{
	nlevel = lvl;

	if (oneP) {
		newGame(lvl);
	}
	else {
		newGame2P(lvl);
	}

	pauseMenu = new PauseMenu(g, this);
	stage.push_back(pauseMenu);
	pauseMenu->setActive(false);

	isSingleplayer = oneP;
	difficultyMode = diff;
}

void PlayState::newGame(int lvl)
{
	switch (lvl)
	{
	case 1:
		levelName = "prueba";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::EffectVaporWave);
		minigame = new MinigameVaporwave(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::testBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::RobotIdle);
		enemyT = Resources::RobotIdle;
		break;
	case 2:
		levelName = "hiphop";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::BackgroundHipHop);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		break;
	case 3:
		levelName = "africa";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::RobotDance);
		enemyT = Resources::RobotDance;
		minigameAmount = 0;
		break;
	case 5:
		levelName = "allstar";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::RobotIdle);
		enemyT = Resources::RobotIdle;
		minigameAmount = 0;
		break;
	case 4:
		levelName = "asereje";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		minigameAmount = 0;
		break;
	case 6:
		levelName = "megalovania";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::RobotIdle);
		enemyT = Resources::RobotIdle;
		minigameAmount = 0;
		break;
	default:
		break;
	}
	
	particles = new ParticleEngine(40, Vector2D(70, 70), manager);
	int leftNotesPos = manager->getDefaultWindowWidth() / 2 - pointOffset;
	int rightNotesPos = manager->getDefaultWindowWidth() / 2 + pointOffset;

	leftNotesVector = Vector2D(leftNotesPos - noteSize / 2, initialNoteHeight);
	rightNotesVector = Vector2D(rightNotesPos - noteSize / 2, initialNoteHeight);

	leftNotesVector2 = Vector2D(leftNotesPos - 50 / 2 + 200, 70);
	rightNotesVector2 = Vector2D(rightNotesPos - 50 / 2 + 200, 70);
	player1 = new PlayerPack(manager,this, leftNotesPos, rightNotesPos, pointSize, noteBarWidth,0,true);
	
	level = new Level(this, manager, levelName,noteSize);
	level->init();
	player2 = nullptr;
	timer = Timer::Instance();
	timer->Reset();

	if (minigameAmount > 0) {
		maxMinigameValue = (maxScore * minigameScoreTotal) / minigameAmount;
		maxNoteValue = (maxScore * (1 - minigameScoreTotal)) / level->noteAmount;
	}

	else {
		maxMinigameValue = 0;
		maxNoteValue = maxScore  / level->noteAmount;
	}


	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), (((manager->getDefaultWindowWidth() - 50) / level->songLength) / 70.5), Resources::YellowBar); //70.5 es la constante para ajustar la velocidad de la barra al tiempo de la cancion
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31), Vector2D((((manager->getDefaultWindowWidth() / level->songLength)) / 70.5), 0), songBarBG);


	perico = new Character(manager, 60 * 5, 120 * 5, Vector2D(100, initialNoteHeight + 50), Resources::PericoIdle);
	
	
	
	minigameController = new TimerNoSingleton();

	//rf = new RedEffect();
	//rf->init();

	bh = new BeatHandler(level->bpm);

	stage.push_back(bg);
	stage.push_back(perico);
	stage.push_back(enemy);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	stage.push_back(player1);
	stage.push_back(particles);


	level->playSong();

	/////////////////////////
	//exit_ = false;

	combo = 0;

	updateResolution();
}

void PlayState::newGame2P(int lvl)
{
	switch (lvl)
	{
	case 1:
		levelName = "RunningInThe90s";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::EffectVaporWave);
		minigame = new MinigameVaporwave(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::testBG;
		enemy = new Character(manager, 60 * 4, 120 * 4, Vector2D(manager->getDefaultWindowWidth() - 350, initialNoteHeight + 100), Resources::RobotIdle);
		enemyT = Resources::RobotIdle;
		break;
	case 2:
		levelName = "hiphop";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getWindowWidth(), manager->getWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::BackgroundHipHop);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 4, 120 * 4, Vector2D(manager->getDefaultWindowWidth() - 350, initialNoteHeight + 100), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		break;
	default:
		break;
	}


	int leftNotesPos = manager->getDefaultWindowWidth() / 3 - pointOffset2P;
	int rightNotesPos = manager->getDefaultWindowWidth() / 3 + pointOffset2P;

	leftNotesVector = Vector2D(leftNotesPos - 70 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 70 / 2, 70);

	leftNotesVector2 = Vector2D(leftNotesPos - 70 / 2 + 400, 70);
	rightNotesVector2 = Vector2D(rightNotesPos - 70 / 2 + 400, 70);

	player1 = new PlayerPack(manager,this, leftNotesPos, rightNotesPos, pointSize, noteBarWidth,0,false);
	player2 = new PlayerPack(manager,this, leftNotesPos + 400, rightNotesPos + 400, pointSize, noteBarWidth,1,false);
	level = new Level(this, manager, levelName,noteSize);
	level->init();
	timer = Timer::Instance();
	timer->Reset();
	maxNoteValue = maxScore / level->noteAmount;

	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), (((manager->getWindowWidth() - 50) / level->songLength) / 70.5), Resources::YellowBar); //70.5 es la constante para ajustar la velocidad de la barra al tiempo de la cancion
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31), Vector2D((((manager->getWindowWidth() / level->songLength)) / 70.5), 0), songBarBG);

	perico = new Character(manager, 60 * 4, 120 * 4, Vector2D(110, initialNoteHeight + 100), Resources::PericoIdle);


	minigameController = new TimerNoSingleton();

	bh = new BeatHandler(level->bpm);


	stage.push_back(bg);
	stage.push_back(perico);
	stage.push_back(enemy);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	stage.push_back(player1);
	stage.push_back(player2);

	level->playSong();

	combo = 0;

	updateResolution();
}

PlayState::~PlayState()
{
	deleteAll();
	delete bh;
	delete effectVaporWave;
	delete level;
	delete minigame;
	delete minigameController;
}

void PlayState::update(Uint32 time)
{
	if (!isPaused) {

		GameState::update(time);
		if (!miniActive && (minigameAmount == 0 || (minigameAmount > 0 && minigameController->DeltaTime() < level->songLength / minigameAmount)))
		{
			minigameController->Update();

			if (levelArrows_.empty() && levelButtons_.empty()) {
				if (player1->screenArrows_.empty() && player1->screenButtons_.empty()) {
					if ((player2 == nullptr || (player2->screenArrows_.empty() && player2->screenButtons_.empty())))
					{
						if (songEndWaitTime == 0)
							songEndWaitTime = time;

						else if (time - songEndWaitTime >= 2000)
							songIsOver = true;
						//songOver();
					}
				}
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
			miniActive = true;
			if (!animationMiniGame)
			{
				player1->lip->setMinigameActive(true);
				player1->setComboActive(false);
				enemy->forceAnimationChange((enemyT + 1));
				perico->forceAnimationChange(Resources::PericoDance1);
				animationMiniGame = true;
				minigame->resetMinigame();
			}
			minigame->update(time);
			if (minigame->getEnd()) {
				player1->lip->setMinigameActive(false);
				miniActive = false;
				msDiff = 0;
				timer->Reset();
				minigame->deleteList();
				minigame->createList();
				minigameController->Reset();
				enemy->queueAnimationChange(enemyT);
				perico->queueAnimationChange(Resources::PericoIdle);
				animationMiniGame = false;
				player1->setComboActive(true);

				int aux = minigame->getAccuracy();
				if (aux != 0)
					updateScoreMinigame(aux);
			}
		}
		if (timer->DeltaTime() > ((bh->getBeatTime() / 1000.0) / (animationFramesPerBeat / 1000)) - msDiff)
		{
			//aqu� se divide el beatTime lo necesario para animar las frames especificadas entre cada beat

			beatSignal = true;
		}
		if (songIsOver)
			songOver();
	}
}

bool PlayState::pause()
{
	if (!isPaused)
	{
		manager->getServiceLocator()->getAudios()->pauseChannel(0);
		isPaused = true;
		pauseMenu->setActive(true);
		pauseMenu->activate();
	}

	return isPaused;
}

void PlayState::resume(unsigned int timePaused)
{
	if (isPaused)
	{
		manager->getServiceLocator()->getAudios()->resumeChanne(0);
		isPaused = false;
		pauseMenu->setActive(false);
		timer->setOffset(timePaused);
		minigameController->setOffset(timePaused);
	}
}


bool PlayState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_f)
	{
		int flags = SDL_GetWindowFlags(manager->getWindow());
		if (flags & SDL_WINDOW_FULLSCREEN) {
			SDL_SetWindowFullscreen(manager->getWindow(), 0);
		}
		else {
			SDL_SetWindowFullscreen(manager->getWindow(), SDL_WINDOW_FULLSCREEN);
		}
	}
	else if (e.key.keysym.sym == SDLK_F1)
		songOver();
	else
	{
		if (!isPaused) {
			if (miniActive) {
				player1->lip->setMinigameActive(true);

				minigame->handleInput(time, e);
			}
			else
			{
				GameState::handleEvent(time, e);
			}
		}
		else
			pauseMenu->handleInput(time, e);
	}
	return true;
}

void PlayState::render(Uint32 time, bool beatSync)
{
	GameState::render(time, beatSignal);
	if (miniActive) {
		minigame->render(time);
		effectVaporWave->render(time, true);
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

void PlayState::updateScoreMinigame(int accuracy)
{
	player1->currentScore += maxMinigameValue * (1 / accuracy);
	player1->updateScoreNote(player1->currentScore);
}

//Al generar las flechas y los botones, los mueve en proporcion al tiempo perdido por cada vuelta
void PlayState::generateArrows()
{
	if (!levelArrows_.empty()) {
		if (levelArrows_.front() != nullptr) {

			player1->screenArrows_.push_back(levelArrows_.front());
			//player1->screenArrows_.back()->setPosition(player1->screenArrows_.back()->getPosition() + player1->screenArrows_.back()->getVelocity()*msDiff);
			
			if (player2 != nullptr && levelArrows2_.front()!=nullptr)
			{

				player2->screenArrows_.push_back(levelArrows2_.front());
				//player2->screenArrows_.back()->setPosition(player2->screenArrows_.back()->getPosition() + player2->screenArrows_.back()->getVelocity()*msDiff);
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
			//player1->screenButtons_.back()->setPosition(player1->screenButtons_.back()->getPosition() + player1->screenButtons_.back()->getVelocity()*msDiff);
			if (player2 != nullptr && levelButtons2_.front() != nullptr)
			{

				player2->screenButtons_.push_back(levelButtons2_.front());
				//player2->screenButtons_.back()->setPosition(player2->screenButtons_.back()->getPosition() + player2->screenButtons_.back()->getVelocity()*msDiff);
			}
		}
		levelButtons_.pop_front();
		levelButtons2_.pop_front();
	}
}

void PlayState::songOver()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->changeState(new EndState(manager, player1->currentScore, maxScore, 70, nlevel));
	//manager->getMachine()->changeState(new MapState(manager));
	//manager->getMachine()->popState();
}

void PlayState::restart()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->changeState(new PlayState(manager, nlevel, isSingleplayer, difficultyMode));
}

void PlayState::exit()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->changeState(new MapState(manager));
}

void PlayState::updateResolution()
{
	/*GameState::updateResolution();

	double wScale = manager->getWidthScale();
	double hScale = manager->getHeightScale();

	minigame->updateResolution(wScale, hScale);
	Vector2D noteVel = setVel(60000 / (level->bpm/1));

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

	initialNoteHeight = initialNoteHeight * hScale;*/
}

Vector2D PlayState::setVel(double time)
{
	double distance = player1->getLeftPoint()->getPosition().getY() + (player1->getLeftPoint()->getHeight()/2) - (initialNoteHeight + (noteSize/2));
	double timeInSecs = (time / 1000.0);
	double velocity = distance / timeInSecs;
	return Vector2D(0, velocity / 8.0);
}

void PlayState::playSong(int song) {
	manager->getServiceLocator()->getAudios()->playChannel(song, 0);
	manager->getServiceLocator()->getAudios()->setChannelVolume(70);
}


void PlayState::showError()
{
	bg->cleanAnimationQueue();
	bg->forceAnimationChange(bgT+1);
	bg->queueAnimationChange(bgT);

	manager->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0);
}

void PlayState::changeRedeffect()
{
	if (rf->isActive() == false) {
		rf->setActive(true);
	}
	else {

	}
}
