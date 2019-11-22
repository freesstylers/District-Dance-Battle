#include "PlayState.h"
#include "GameManager.h"

PlayState::PlayState(GameManager* g, int lvl, bool oneP, bool diff, int prevMaxScoreE, int prevMaxScoreH) : GameState(g) //Asigna game y llama a inicializaci�n
{
	nlevel = lvl;
	volume = g->getMusicVolume();
	Lost = new EmptyObject(manager, Vector2D(0, 0), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::Lost);
	Lost->setActive(false);

	youLost = new EmptyObject(manager, Vector2D(0, -manager->getDefaultWindowHeight()), manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Resources::YouLost);
	youLost->setActive(false);

	switch (lvl)
	{
	case 0:
		levelName = "tutorial";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::PericoRoom);
		bgT = Resources::PericoRoom;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::PericoEspejo);
		enemyT = Resources::PericoRoom;
		break;
	case 1:
		levelName = "vaporwave";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::testBG);
		bgT = Resources::testBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::RobotIdle);
		enemyT = Resources::RobotIdle;
		break;
	case 2:
		levelName = "reggeaton";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::CiuBG);
		bgT = Resources::CiuBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::PapitoIdle);
		enemyT = Resources::PapitoIdle;
		break;
	case 3:
		levelName = "hiphop";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::BackgroundHipHop);
		bgT = Resources::BackgroundHipHop;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		break;
	case 4:
		levelName = "rock";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::FondoRock);
		bgT = Resources::FondoRock;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::ZombieIdle);
		enemyT = Resources::ZombieIdle;
		break;
	case 5:
		levelName = "hardbass";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::FondoHardbass);
		bgT = Resources::FondoHardbass;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::AlienIdle);
		enemyT = Resources::AlienIdle;
		break;
	case 6:
		levelName = "allstar";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::ShrekIdle);
		enemyT = Resources::ShrekIdle;
		break;
	case 7:
		levelName = "megalovania";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::SansIdle);
		enemyT = Resources::SansIdle;
		break;
	case 8:
		levelName = "RunningInThe90s";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::AlienIdle2);
		enemyT = Resources::AlienIdle;
		break;
	case 10:
		levelName = "NeverGonnaGiveYouUp";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::RobotDance);
		enemyT = Resources::RobotDance;
		break;
	case 11:
		levelName = "asereje";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		break;
	case 12:
		levelName = "MegalovaniaHonk";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::GooseDance);
		enemyT = Resources::GooseDance;
		break;
	case 13:
		levelName = "DotA";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::PapitoIdle);
		enemyT = Resources::PapitoIdle;
		break;
	case 14:
		levelName = "Doraemon";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::ShrekIdle);
		enemyT = Resources::ShrekIdle;
		break;
	case 15:
		levelName = "Tripoloski";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::AlienIdle2);
		enemyT = Resources::AlienIdle;
		break;
	case 16:
		levelName = "doom";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::ZombieIdle);
		enemyT = Resources::ZombieIdle;
		break;
	case 17:
		levelName = "Avengers";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::PapitoIdle);
		enemyT = Resources::PapitoIdle;
		break;
	case 18:
		levelName = "Dracukeo";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::SansIdle);
		enemyT = Resources::SansIdle;
		break;
	case 19:
		levelName = "Rasputin";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::AlienIdle2);
		enemyT = Resources::AlienIdle;
		break;
	case 20:
		levelName = "fiestaPagana";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::ZombieIdle);
		enemyT = Resources::ZombieIdle;
		break;
	case 21:
		levelName = "despacito";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::RobotIdle);
		enemyT = Resources::RobotIdle;
		break;
	case 22:
		levelName = "KDA";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::ExtraBG);
		bgT = Resources::ExtraBG;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::EminemciaIdle);
		enemyT = Resources::EminemciaIdle;
		break;
	default:
		levelName = "CL";
		bg = new Background(manager, manager->getDefaultWindowWidth(), manager->getDefaultWindowHeight(), Vector2D(0, 0), Resources::FondoHardbass);
		bgT = Resources::FondoHardbass;
		enemy = new Character(manager, 60 * 5, 120 * 5, Vector2D(manager->getDefaultWindowWidth() - 400, initialNoteHeight + 50), Resources::AlienIdle2);
		enemyT = Resources::AlienIdle;
		break;
	}

	difficultyMode = diff;
	if (oneP) {
		newGame();
	}
	else {
		newGame2P();
	}

	pauseMenu = new PauseMenu(g, this, manager->getP1Controller());
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

	if (levelName == "Tripoloski")
		level->RandomLevel();
	else
		level->init(difficultyMode);
	timer = new Timer();
	timer->Reset();


	maxNoteValue = maxScore  / level->noteAmount;


	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), Resources::YellowBar);
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31),  manager->getDefaultWindowWidth() - (41 * 3), songBarBG, level->songLength); //41 la posicion inicial
	

	perico = new Character(manager, 60 * 5, 120 * 5, Vector2D(100, initialNoteHeight + 50), Resources::PericoIdle);
	
	extraTimer = new Timer();

	bh = new BeatHandler(level->bpm);

	stage.push_back(bg);
	stage.push_back(perico);
	stage.push_back(enemy);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	stage.push_back(player1);
	stage.push_back(particles);
	stage.push_back(Lost);
	stage.push_back(youLost);


	level->playSong();
}

void PlayState::newGame2P()
{


	int leftNotesPos = manager->getDefaultWindowWidth() / 3 - pointOffset2P;
	int rightNotesPos = manager->getDefaultWindowWidth() / 3 + pointOffset2P;

	leftNotesVector = Vector2D(leftNotesPos - 70 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 70 / 2, 70);

	leftNotesVector2 = Vector2D(leftNotesPos - 70 / 2 + 400, 70);
	rightNotesVector2 = Vector2D(rightNotesPos - 70 / 2 + 400, 70);

	player1 = new PlayerPack(manager,this, leftNotesPos, rightNotesPos, pointSize, noteBarWidth, 0, false);
	player2 = new PlayerPack(manager,this, leftNotesPos + 400, rightNotesPos + 400, pointSize, noteBarWidth,1,false);
	crown = new Background(manager, 128, 128, Vector2D(0, 0), Resources::Crown);
	crown->setActive(false);
	level = new Level(this, manager, levelName, noteSize);

	if (levelName == "Tripoloski")
		level->RandomLevel();
	else
		level->init(difficultyMode);

	timer = new Timer();
	timer->Reset();

	maxNoteValue = maxScore / level->noteAmount;

	songBarBG = new BarBackground(manager, 1, 14, Vector2D(50, 35), Resources::YellowBar);
	songBar = new SongBar(manager, 18, 22, Vector2D(41, 31), manager->getDefaultWindowWidth() - (41 * 3), songBarBG, level->songLength); //41 la posicion inicial

	perico = new Character(manager, 60 * 4, 120 * 4, Vector2D(110, initialNoteHeight + 100), Resources::PericoIdle);
	enemy->setPosition(Vector2D(manager->getDefaultWindowWidth() - 350, initialNoteHeight + 100));
	enemy->setWidth(60 * 4);
	enemy->setHeight(120 * 4);


	extraTimer = new Timer();

	bh = new BeatHandler(level->bpm);

	stage.push_back(bg);
	stage.push_back(perico);
	stage.push_back(enemy);
	stage.push_back(songBarBG);
	stage.push_back(songBar);
	stage.push_back(player1);
	stage.push_back(player2);
	stage.push_back(crown);
	stage.push_back(Lost);
	stage.push_back(youLost);

	level->playSong();
}

PlayState::~PlayState()
{
	delete timer;
	delete extraTimer;
	delete level;
	delete bh;

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
				crown->setActive(true);
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
		//When the arrows and the buttons stop, the game finish
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
			if (timer->DeltaTime() > (bh->getBeatTime() / 1000.0) - msDiff && !isLost())
			{
				msDiff += timer->DeltaTime() - (bh->getBeatTime() / 1000.0);
				generateArrows();
				generateButtons();
				timer->Reset();

				beatSignal = true;
			}
			else if (isLost())
			{
				Lost->setActive(true);
				youLost->setActive(true);
				if (volume > 0)
				{
					volume -= 1;
					manager->getServiceLocator()->getAudios()->setChannelVolume(volume, 0);
				}
				else {
					manager->getServiceLocator()->getAudios()->haltChannel(0);
					manager->getServiceLocator()->getAudios()->setChannelVolume(manager->getMusicVolume(), 0);
				}

				if (youLost->getPosition().getY() < 0)
					youLost->setPosition(youLost->getPosition() + Vector2D(0, 4));
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
		extraTimer->setOffset(timePaused);

		player1->lip->blockPause(SDL_GetTicks());

		if(player2 != nullptr)
			player2->lip->blockPause(SDL_GetTicks());
	}
}

//Change the controls to PS4 controls or XBOX controls
bool PlayState::changeControls()
{
	int P1Controller = manager->getP1Controller();
	int P2Controller = manager->getP2Controller();

	/*if (P1Controller < 2)
	{
		manager->setP1Controller((P1Controller + 1));
		P1Controller = manager->getP1Controller();
	}
	else
	{
		manager->setP1Controller(0);
		P1Controller = manager->getP1Controller();
	}*/


	for (Note* o : levelArrows_) {
		if (o != nullptr)
			o->changeController(P1Controller);
	}

	for (Note* o : levelButtons_) {
		if (o != nullptr)
			o->changeController(P1Controller);
	}

	for (Note* o : levelArrows2_) {
		if (o != nullptr)
			o->changeController(P2Controller);
	}

	for (Note* o : levelButtons2_) {
		if (o != nullptr)
			o->changeController(P2Controller);
	}


	player1->changeController(P1Controller);

	if (player2 != nullptr)
		player2->changeController(P2Controller);

	return true;
}


bool PlayState::handleEvent(Uint32 time, SDL_Event e)
{

	if (e.key.keysym.sym == SDLK_F1) {
		songOver();
	}
	else if (e.key.keysym.sym == SDLK_F2) {
		player1->currentScore = maxScore;
		player1->addCombo(300);
		songOver();
	}
	else if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_F9) {
		manager->stop();
		return true;
	}
	else if (isLost() && (e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym == SDLK_RETURN || SDL_GameControllerGetButton(player1->lip->getController(), SDL_CONTROLLER_BUTTON_A)) && youLost->getPosition().getY() >= 0)
	{
		songOver();
	}
	else
	{
		if (!isPaused) {
			if (!isLost())
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

//Take out a note from the vector
void PlayState::generateArrows()
{
	if (!levelArrows_.empty()) {
		if (levelArrows_.front() != nullptr) {

			player1->screenArrows_.push_back(levelArrows_.front());
		}
		levelArrows_.pop_front();
	}

	if (player2 != nullptr && !levelArrows2_.empty()) {
		if (levelArrows2_.front() != nullptr)
		{
			player2->screenArrows_.push_back(levelArrows2_.front());
		}
		levelArrows2_.pop_front();
	}
}

void PlayState::generateButtons()
{
	if (!levelButtons_.empty()) {
		if (levelButtons_.front() != nullptr) {

			player1->screenButtons_.push_back(levelButtons_.front());
		}
		levelButtons_.pop_front();
	}

	if (player2 != nullptr && !levelButtons2_.empty()) {
		if (levelButtons2_.front() != nullptr)
		{
			player2->screenButtons_.push_back(levelButtons2_.front());
		}
		levelButtons2_.pop_front();
	}
}

void PlayState::songOver()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	if (isSingleplayer)
		manager->getMachine()->pushState(new EndState(manager, prevMaxScoreE_, prevMaxScoreH_, player1->getCalifications(), player1->currentScore, maxScore, 70, player1->getMaxCombo(), nlevel, isSingleplayer, difficultyMode));
	else
		manager->getMachine()->pushState(new EndState(manager, prevMaxScoreE_, prevMaxScoreH_, player1->getCalifications(), player1->currentScore, maxScore, 70, player1->getMaxCombo(), nlevel, isSingleplayer, difficultyMode, player2->currentScore, player2->getCalifications(), player2->getMaxCombo()));
}

void PlayState::restart()
{
	manager->getServiceLocator()->getAudios()->haltChannel(0);
	manager->getMachine()->pushState(new PlayState(manager, nlevel, isSingleplayer, difficultyMode, prevMaxScoreE_, prevMaxScoreH_));
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
}


void PlayState::showError()
{
	bg->cleanAnimationQueue();
	bg->forceAnimationChange(bgT+1);
	bg->queueAnimationChange(bgT);
	manager->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0, 1);
}

bool PlayState::isLost()
{
	if (player1->lip->numFailed > 10 && isSingleplayer)
	{
		return true;
	}
	else
		return false;
}
