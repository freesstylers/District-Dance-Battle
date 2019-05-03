#include "PlayerPack.h"
#include "PlayState.h"

PlayerPack::PlayerPack()
{
}

PlayerPack::PlayerPack(SDLGame* manager, PlayState* ps, int leftNotesPos, int rightNotesPos, int pointSize, int squareWidth, int player,bool OneP): GameObject(manager), playstate_(ps)
{
	for (int i = 0; i < 4; i++)
	{
		califications[i] = 0;
	}
	lip = new LevelInputManager(playstate_, this, player);
	leftNotesVector = Vector2D(leftNotesPos - 50 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 50 / 2, 70);

	leftPoint = new Point(manager, pointSize, pointSize, Vector2D(leftNotesPos - pointSize / 2, 565), lip->getController(), true);
	rightPoint = new Point(manager, pointSize, pointSize, Vector2D(rightNotesPos - pointSize / 2, 565), lip->getController(), false);
	leftNoteBar = new Squares(manager, squareWidth, 565 + 0.6 * pointSize, Vector2D(leftNotesPos + 1 - squareWidth / 2, leftNotesVector.getY()));
	rightNoteBar = new Squares(manager, squareWidth, 565 + 0.6 * pointSize, Vector2D(rightNotesPos + 1 - squareWidth / 2, rightNotesVector.getY()));
	if (!OneP && player == 0)
	{
		leftNoteBar->forceAnimationChange(Resources::Recuadro1P);
		rightNoteBar->forceAnimationChange(Resources::Recuadro1P);
	}
	else if (!OneP && player == 1)
	{
		leftNoteBar->forceAnimationChange(Resources::Recuadro2P);
		rightNoteBar->forceAnimationChange(Resources::Recuadro2P);
	}
	feedbackLeft = new FeedbackPool(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(leftNotesPos - (pointSize * 2 *0.8), 565 + pointSize / 2));
	feedbackRight = new FeedbackPool(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(rightNotesPos + (pointSize * 0.8), 565 + pointSize / 2));
	hitLeft = new HitNotePool(manager, pointSize - 10, pointSize - 10);
	hitRight = new HitNotePool(manager, pointSize - 10, pointSize - 10);
	noteYLimit = leftPoint->getPosition().getY() + leftPoint->getHeight();
	if (player == 0)
	{
		scoreBar = new ScoreBar(manager, 80, 0, Vector2D(6, 500 + pointSize), playstate_->getMaxScore(), manager->getDefaultWindowHeight() - (500 + pointSize));
	}
	else
	{
		scoreBar = new ScoreBar(manager, 80, 0, Vector2D(manager->getDefaultWindowWidth() - 86, 500 + pointSize), playstate_->getMaxScore(), manager->getDefaultWindowHeight() - (500 + pointSize));
	}

	comboTextX = rightNoteBar->getPosition().getX() - ((rightNoteBar->getPosition().getX() - (leftNoteBar->getPosition().getX() + squareWidth)) / 2);

	comboPosition = Vector2D(comboTextX, 465);	//the position of the Combo Text is anchored to the middle of the object's x coordinate

	comboTxt = new ComboText(manager, manager->getServiceLocator()->getFonts()->getFont(Resources::FIPPS20), comboPosition);

	combo = 0;
}
void PlayerPack::render(Uint32 time, bool beatSync)
{
	leftNoteBar->render(time,beatSync);
	rightNoteBar->render(time,beatSync);
	leftPoint->render(time);
	rightPoint->render(time);
	comboTxt->render(time);
	scoreBar->render(time);
	feedbackLeft->render(time, false);
	feedbackLeft->updateResolution(game_->getWidthScale(), game_->getHeightScale());
	feedbackRight->render(time, false);
	feedbackRight->updateResolution(game_->getWidthScale(), game_->getHeightScale());
	hitLeft->render(time, false);
	hitRight->render(time, false);

	for (Note* o : screenArrows_)
	{
		o->render(time, beatSync);
	}
	for (Note* o : screenButtons_)
	{
		o->render(time, beatSync);
	}
}

void PlayerPack::update(Uint32 time)
{
	if (!playstate_->getMiniActive())
	{
		leftNoteBar->update(time);
		rightNoteBar->update(time);
		leftPoint->update(time);
		rightNoteBar->update(time);
		scoreBar->update(time);
		feedbackRight->update(time);
		feedbackLeft->update(time);
		for (Note* o : screenArrows_)
		{
			if (o != nullptr) {
				o->update(time);
			}
			
		}
		for (Note* o : screenButtons_)
		{
			if (o != nullptr)
			{
				o->update(time);
			}
		}
		if (!screenArrows_.empty() && screenArrows_.front()->getPosition().getY() > noteYLimit)
		{
			Note* aux = screenArrows_.front();
			SDL_GameControllerButton x = aux->getKey();
			if (x == SDL_CONTROLLER_BUTTON_INVALID) {
				feedbackLeft->addFeedback(Resources::FeedbackPerfect);
				updateScoreNote(1);
				addCombo(1);
			}
			else
			{
				playstate_->showError();
				resetCombo();
				feedbackLeft->addFeedback(Resources::FeedbackBad);
			}
			delete aux;
			screenArrows_.pop_front();
			cout << "fuera" << endl;
			addCalifications(0);
		}
		if (!screenButtons_.empty() && screenButtons_.front()->getPosition().getY() > noteYLimit)
		{
			Note* aux = screenButtons_.front();
			SDL_GameControllerButton y = aux->getKey();
			if (y == SDL_CONTROLLER_BUTTON_INVALID) {
				feedbackRight->addFeedback(Resources::FeedbackPerfect);
				updateScoreNote(1);
				addCombo(1);
			}
			else
			{
				playstate_->showError();
				feedbackRight->addFeedback(Resources::FeedbackBad);
				resetCombo();
			}
			delete aux;
			screenButtons_.pop_front();
			cout << "fuera" << endl;
			addCalifications(0);
			errorRight();
		}
	}
}

bool PlayerPack::handleInput(Uint32 time, const SDL_Event& event)
{
	for (Note* o : screenArrows_)
	{
		o->handleInput(time, event);
	}
	for (Note* o : screenButtons_)
	{
		o->handleInput(time, event);
	}
	leftNoteBar->handleInput(time, event);
	rightNoteBar->handleInput(time, event);
	leftPoint->handleInput(time, event);
	rightPoint->handleInput(time, event);
	rightNoteBar->handleInput(time, event);
	feedbackLeft->handleInput(time, event);
	feedbackRight->handleInput(time, event);

	return lip->handleInput(time, event);;
}

void PlayerPack::updateResolution(double wScale, double hScale)
{
	leftNoteBar->updateResolution(wScale, hScale);
	rightNoteBar->updateResolution(wScale, hScale);
	leftPoint->updateResolution(wScale, hScale);
	rightPoint->updateResolution(wScale, hScale);
	feedbackLeft->updateResolution(wScale, hScale);
	feedbackRight->updateResolution(wScale, hScale);
	hitLeft->updateResolution(wScale, hScale);
	hitRight->updateResolution(wScale, hScale);
	Vector2D noteVel = playstate_->setVel(60000.0 / (double)playstate_->getBPM());

	for (Note* n : screenArrows_){
		n->updateResolution(wScale, hScale);
		n->setVelocity(noteVel);
	}

	for (Note* n : screenButtons_) {
		n->updateResolution(wScale, hScale);
		n->setVelocity(noteVel);
	}

	noteYLimit = leftPoint->getPosition().getY() + leftPoint->getHeight();
}

void PlayerPack::addCombo(int i)
{
	combo += i;

	if (combo == 10 || combo == 25 || combo == 50 || combo % 100 == 0) {
		comboTxt->updateCombo(combo);
		updateCombo();
	}
}

void PlayerPack::resetCombo()
{
	if (combo != 0) {
		combo = 0;
		updateCombo();
	}
}

int* PlayerPack::getCalifications()
{
	return califications;
}

void PlayerPack::addCalifications(int letter)
{
	califications[letter]++;
}

void PlayerPack::updateCombo()
{

	if (combo < 10) {
		playstate_->getPerico()->setAnimation(Resources::PericoIdle);
		comboTxt->toggleHideAnimation(true);
	}

	else
	{
		comboTxt->toggleHideAnimation(false);

		if (combo < 50)
			playstate_->getPerico()->setAnimation(Resources::PericoDab);

		else if (combo < 100)
			playstate_->getPerico()->setAnimation(Resources::PericoDance1);

		else
			playstate_->getPerico()->setAnimation(Resources::PericoMaxPower);
	}
}

PlayerPack::~PlayerPack()
{
	delete leftNoteBar;
	delete rightNoteBar;
	delete leftPoint;
	delete rightPoint;
	delete feedbackRight;
	delete feedbackLeft;
	delete hitRight;
	delete hitLeft;
	delete lip;
	for (Note* o : screenArrows_)
	{
		delete o;
	}
	for (Note* o : screenButtons_)
	{
		delete o;
	}
}

void PlayerPack::errorLeft()
{
	/*leftNoteBar->cleanAnimationQueue();
	leftNoteBar->forceAnimationChange(Resources::SquareMiss);
	leftNoteBar->queueAnimationChange(Resources::Square);*/
}

void PlayerPack::errorRight() {
	/*rightNoteBar->cleanAnimationQueue();
	rightNoteBar->forceAnimationChange(Resources::SquareMiss);
	rightNoteBar->queueAnimationChange(Resources::Square);*/
}
void PlayerPack::updateScoreNote(int accuracy)
{
	if(accuracy == 1)
		currentScore += playstate_->getMaxNoteValue();
	else if(accuracy == 2)
		currentScore += playstate_->getMaxNoteValue() * 0.75;
	else
		currentScore += playstate_->getMaxNoteValue() * 0.5;
	scoreBar->updateBar(currentScore);
}
