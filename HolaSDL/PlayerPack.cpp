#include "PlayerPack.h"
#include "PlayState.h"

PlayerPack::PlayerPack()
{
}

PlayerPack::PlayerPack(SDLGame* manager, PlayState* ps, int leftNotesPos, int rightNotesPos, int pointSize, int squareWidth, int player): GameObject(manager), playstate_(ps)
{
	lip = new LevelInputManager(playstate_, this, player);
	leftNotesVector = Vector2D(leftNotesPos - 50 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 50 / 2, 70);

	leftPoint = new Point(manager, pointSize, pointSize, Vector2D(leftNotesPos - pointSize / 2, 465), lip->getController(), true);
	rightPoint = new Point(manager, pointSize, pointSize, Vector2D(rightNotesPos - pointSize / 2, 465), lip->getController(), false);
	leftNoteBar = new Squares(manager, squareWidth, 465 + 0.6 * pointSize, Vector2D(leftNotesPos + 1 - squareWidth / 2, leftNotesVector.getY()));
	rightNoteBar = new Squares(manager, squareWidth, 465 + 0.6 * pointSize, Vector2D(rightNotesPos + 1 - squareWidth / 2, rightNotesVector.getY()));
	feedbackLeft = new FeedbackPool(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(leftNotesPos - (pointSize * 0.8) - (pointSize * 0.8), 465 + pointSize / 2));
	feedbackRight = new FeedbackPool(manager, pointSize * 0.8, pointSize * 0.8, Vector2D(rightNotesPos + (pointSize * 0.8), 465 + pointSize / 2));
	hitLeft = new HitNotePool(manager, 70, 70);
	hitRight = new HitNotePool(manager, 70, 70);
	noteYLimit = leftPoint->getPosition().getY() + leftPoint->getHeight();

	comboTextX = rightNoteBar->getPosition().getX() - ((rightNoteBar->getPosition().getX() - (leftNoteBar->getPosition().getX() + squareWidth)) / 2);

	comboPosition = Vector2D(comboTextX, 465);	//the position of the Combo Text is anchored to the middle of the object's x coordinate

	comboTxt = new ComboText(manager, manager->getServiceLocator()->getFonts()->getFont(Resources::PIXEL20), comboPosition);

	combo = 0;
}
void PlayerPack::render(Uint32 time, bool beatSync)
{
	leftNoteBar->render(time);
	rightNoteBar->render(time);
	leftPoint->render(time);
	rightPoint->render(time);
	comboTxt->render(time);
	feedbackLeft->render(time, false);
	feedbackRight->render(time, false);
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
				playstate_->updateScoreNote(1);
				addCombo(1);
			}
			else
			{
				game_->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0);
				resetCombo();
			}
			delete aux;
			screenArrows_.pop_front();
			cout << "fuera" << endl;
			errorLeft();

		}
		if (!screenButtons_.empty() && screenButtons_.front()->getPosition().getY() > noteYLimit)
		{
			Note* aux = screenButtons_.front();
			SDL_GameControllerButton y = aux->getKey();
			if (y == SDL_CONTROLLER_BUTTON_INVALID) {
				feedbackRight->addFeedback(Resources::FeedbackPerfect);
				playstate_->updateScoreNote(1);
				addCombo(1);
			}
			else
			{
				game_->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0);
				resetCombo();
			}
			delete aux;
			screenButtons_.pop_front();
			cout << "fuera" << endl;
			errorRight();
		}
	}
}

bool PlayerPack::handleInput(Uint32 time, const SDL_Event& event)
{
	lip->handleInput(time, event);
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

	return false;
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
	Vector2D noteVel = playstate_->setVel(60000 / playstate_->getBPM());

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
