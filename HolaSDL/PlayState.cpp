#include "PlayState.h"
#include "GameManager.h"

PlayState::PlayState(GameManager* g, int lvl, bool oneP, bool diff, int prevMaxScoreE, int prevMaxScoreH) : GameState(g) //Asigna game y llama a inicializaci�n
{
	nlevel = lvl;

	g->getServiceLocator()->getAudios()->setChannelVolume(60, 1);
	

	switch (lvl)
	{
	case 1:
		levelName = "prueba";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::EffectVaporWave);
		minigame = new MinigameVaporwave(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::testBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::RobotIdle);
		enemyT = Resources::RobotIdle;
		break;
	case 2:
		levelName = "hiphop";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::BackgroundHipHop);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		break;
	case 3:
		levelName = "papito";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::HipHopEffect);
		minigame = nullptr;//new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::CiuBG);
		bgT = Resources::CiuBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::PapitoIdle);
		enemyT = Resources::PapitoIdle;
		minigameAmount = 0;
		break;
	case 4:
		levelName = "africa";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::RobotDance);
		enemyT = Resources::RobotDance;
		minigameAmount = 0;
		break;
	case 6:
		levelName = "allstar";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::ShrekIdle);
		enemyT = Resources::ShrekIdle;
		minigameAmount = 0;
		break;
	case 5:
		levelName = "asereje";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		minigameAmount = 0;
		break;
	case 7:
		levelName = "megalovania";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::SansIdle);
		enemyT = Resources::SansIdle;
		minigameAmount = 0;
		break;
	case 8:
		levelName = "RunningInThe90s";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::HipHopEffect);
		minigame = new MinigameHipHop(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::SansIdle);
		enemyT = Resources::SansIdle;
		minigameAmount = 0;
		break;
	case 9:
		levelName = "tutorial";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::EffectVaporWave);
		minigame = new MinigameVaporwave(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::PericoRoom);
		bgT = Resources::PericoRoom;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::PericoEspejo);
		enemyT = Resources::PericoRoom;
		minigameAmount = 0;
		break;
	case 10:
		levelName = "rock";
		effectVaporWave = new EffectVaporwave(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::EffectVaporWave);
		minigame = new MinigameVaporwave(manager, this);
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::PericoRoom);
		bgT = Resources::PericoRoom;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 300, initialNoteHeight + 50), Resources::ZombieIdle);
		enemyT = Resources::ZombieIdle;
		minigameAmount = 0;
		break;
	default:
		break;
	}

	difficultyMode = diff;

	if (oneP) {
		newGame();
	}
	else {
		newGame2P();
	}

	pauseMenu = new PauseMenu(g, this, manager->getController());
	stage.push_back(pauseMenu);
	
	pauseMenu->setActive(false);

	isSingleplayer = oneP;
	prevMaxScoreE_ = prevMaxScoreE;
	prevMaxScoreH_ = prevMaxScoreH;

}

void PlayState::newGame()
{
	
	particles = new ParticleEngine(40, Vector2D(70, 70), manager);
	int leftNotesPos = manager->getDefaultWindowWidth() / 2 - pointOffset;
	int rightNotesPos = manager->getDefaultWindowWidth() / 2 + pointOffset;

	leftNotesVector = Vector2D(leftNotesPos - noteSize / 2, initialNoteHeight);
	rightNotesVector = Vector2D(rightNotesPos - noteSize / 2, initialNoteHeight);

	leftNotesVector2 = Vector2D(leftNotesPos - 50 / 2 + 200, 70);
	rightNotesVector2 = Vector2D(rightNotesPos - 50 / 2 + 200, 70);
	player1 = new PlayerPack(manager,this, leftNotesPos, rightNotesPos, pointSize, noteBarWidth,0,true);
	
	level = new Level(this, manager, levelName,noteSize);
	level->init(difficultyMode);
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


	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), Resources::YellowBar);
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31),  manager->getDefaultWindowWidth() - (41 * 3), songBarBG, level->songLength); //41 la posicion inicial
	

	perico = new Character(manager, 60 * 5, 120 * 5, Vector2D(100, initialNoteHeight + 50), Resources::PericoIdle);
	
	fourButtons = new EmptyObject(manager, Vector2D(10, manager->getDefaultWindowHeight() - 101), 75, 81, Resources::fourButtons);
	
	//manager->getDefaultWindowWidth() - 91, 81
	
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
	stage.push_back(fourButtons);


	level->playSong();

	combo = 0;

	updateResolution();
}

void PlayState::newGame2P()
{


	int leftNotesPos = manager->getDefaultWindowWidth() / 3 - pointOffset2P;
	int rightNotesPos = manager->getDefaultWindowWidth() / 3 + pointOffset2P;

	leftNotesVector = Vector2D(leftNotesPos - 70 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 70 / 2, 70);

	leftNotesVector2 = Vector2D(leftNotesPos - 70 / 2 + 400, 70);
	rightNotesVector2 = Vector2D(rightNotesPos - 70 / 2 + 400, 70);

	player1 = new PlayerPack(manager,this, leftNotesPos, rightNotesPos, pointSize, noteBarWidth,0,false);
	player2 = new PlayerPack(manager,this, leftNotesPos + 400, rightNotesPos + 400, pointSize, noteBarWidth,1,false);
	crown = new Background(manager, 128, 128, Vector2D(0, 0), Resources::Crown);
	level = new Level(this, manager, levelName,noteSize);
	level->init(difficultyMode);
	timer = Timer::Instance();
	timer->Reset();
	maxNoteValue = maxScore / level->noteAmount;

	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), Resources::YellowBar);
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31), manager->getDefaultWindowWidth() - (41 * 3), songBarBG, level->songLength); //41 la posicion inicial

	perico = new Character(manager, 60 * 4, 120 * 4, Vector2D(110, initialNoteHeight + 100), Resources::PericoIdle);


	minigameController = new TimerNoSingleton();

	bh = new BeatHandler(level->bpm);
	fourButtons = new EmptyObject(manager, Vector2D(10, manager->getDefaultWindowHeight() - 101), 75, 81, Resources::fourButtons);
	EmptyObject* fourButtons2 = new EmptyObject(manager, Vector2D(manager->getDefaultWindowWidth() - 85, manager->getDefaultWindowHeight() - 101), 75, 81, Resources::fourButtons);

	stage.push_back(bg);
	stage.push_back(perico);
	stage.push_back(enemy);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	stage.push_back(player1);
	stage.push_back(player2);
	stage.push_back(fourButtons);
	stage.push_back(fourButtons2);

	level->playSong();

	combo = 0;

	updateResolution();
}

PlayState::~PlayState()
{
	//timer->Release();
	delete minigameController;
	delete minigame;
	delete effectVaporWave;
	delete level;
	delete bh;
	delete crown;

	for (GameObject* o : stage)
	{
		delete o;
	}

	stage.clear();
	 
}

void PlayState::update(Uint32 time)
{
	if (!isPaused) {

		GameState::update(time);
		if (!isSingleplayer)
		{
			if (player1->currentScore > player2->currentScore && player1->currentScore != 0)
			{
				player1->getleftBar()->forceAnimationChange(Resources::Recuadro1PWin);
				player1->getrightBar()->forceAnimationChange(Resources::Recuadro1PWin);
				player2->getleftBar()->forceAnimationChange(Resources::Recuadro2P);
				player2->getrightBar()->forceAnimationChange(Resources::Recuadro2P);
				crown->setPosition(Vector2D(player1->getleftBar()->getPosition().getX() + player1->getleftBar()->getWidth()/2 + 6, player1->getleftBar()->getPosition().getY() - 60));
			}
			else if (player2->currentScore >= player1->currentScore && player2->currentScore != 0)
			{
				player2->getleftBar()->forceAnimationChange(Resources::Recuadro2PWin);
				player2->getrightBar()->forceAnimationChange(Resources::Recuadro2PWin);
				player1->getleftBar()->forceAnimationChange(Resources::Recuadro1P);
				player1->getrightBar()->forceAnimationChange(Resources::Recuadro1P);
				crown->setPosition(Vector2D(player2->getleftBar()->getPosition().getX() + player2->getleftBar()->getWidth() / 2 + 6, player2->getleftBar()->getPosition().getY() - 60));
			}
		}
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
			//aqui se divide el beatTime lo necesario para animar las frames especificadas entre cada beat

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

bool PlayState::changeControls()
{
	bool isXbox = !manager->getController();
	manager->setController(isXbox);


	for (Note* o : levelArrows_) {
		if (o != nullptr)
			o->changeController(isXbox);
	}

	for (Note* o : levelButtons_) {
		if (o != nullptr)
			o->changeController(isXbox);
	}

	for (Note* o : levelArrows2_) {
		if (o != nullptr)
			o->changeController(isXbox);
	}

	for (Note* o : levelButtons2_) {
		if (o != nullptr)
			o->changeController(isXbox);
	}


	player1->changeController(isXbox);

	if (player2 != nullptr)
		player2->changeController(isXbox);

	return isXbox;
}


bool PlayState::handleEvent(Uint32 time, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_F1)
		songOver();
	else if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
		manager->stop();
		return true;
	}
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
	if (!isSingleplayer && player1->currentScore > 0 && player2->currentScore > 0)
		crown->render(time, beatSignal);
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
	for (Note* o : levelButtons_) //Por si se cierra el levelName antes de que acabe
	{
		delete o;
	}
	for (Note* o : levelArrows2_) //Por si se cierra el levelName antes de que acabe
	{
		delete o;
	}
	for (Note* o : levelButtons2_) //Por si se cierra el levelName antes de que acabe
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
			
			if (player2 != nullptr && levelArrows2_.front()!=nullptr)
			{
				player2->screenArrows_.push_back(levelArrows2_.front());
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
	if (isSingleplayer)
		manager->getMachine()->changeState(new EndState(manager, prevMaxScoreE_, prevMaxScoreH_, player1->getCalifications(), player1->currentScore, maxScore, 70, nlevel, isSingleplayer, difficultyMode));
	else
		manager->getMachine()->changeState(new EndState(manager, prevMaxScoreE_, prevMaxScoreH_, player1->getCalifications(), player1->currentScore, maxScore, 70, nlevel, isSingleplayer, difficultyMode, player2->currentScore, player2->getCalifications()));
	//manager->getMachine()->changeState(new MapState(manager));
	//manager->getMachine()->popState();
}

void PlayState::updateResolution()
{

}

void PlayState::restart()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->changeState(new PlayState(manager, nlevel, isSingleplayer, difficultyMode, prevMaxScoreE_, prevMaxScoreH_));
}

void PlayState::exit()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->changeState(new MapState(manager));
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
	manager->getServiceLocator()->getAudios()->setChannelVolume(70, 0);
}


void PlayState::showError()
{
	bg->cleanAnimationQueue();
	bg->forceAnimationChange(bgT+1);
	bg->queueAnimationChange(bgT);
	manager->getServiceLocator()->getAudios()->setChannelVolume(10,1); //AJUSTE DEL VOLUMEN
	manager->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0, 1);
}

void PlayState::changeRedeffect()
{
	if (rf->isActive() == false) {
		rf->setActive(true);
	}
	else {

	}
}
