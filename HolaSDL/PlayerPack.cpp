#include "PlayerPack.h"
#include "PlayState.h"

PlayerPack::PlayerPack()
{
}

PlayerPack::PlayerPack(SDLGame* manager, PlayState* ps, int leftNotesPos, int rightNotesPos, int pointSize, int squareWidth): GameObject(manager), playstate_(ps)
{

	leftNotesVector = Vector2D(leftNotesPos - 50 / 2, 70);
	rightNotesVector = Vector2D(rightNotesPos - 50 / 2, 70);

	leftPoint = new Point(manager, pointSize, pointSize, Vector2D(leftNotesPos - pointSize / 2, 465));
	rightPoint = new Point(manager, pointSize, pointSize, Vector2D(rightNotesPos - pointSize / 2, 465));
	leftNoteBar = new Squares(manager, squareWidth, 465 + 0.6 * pointSize, Vector2D(leftNotesPos + 1 - squareWidth / 2, leftNotesVector.getY()));
	rightNoteBar = new Squares(manager, squareWidth, 465 + 0.6 * pointSize, Vector2D(rightNotesPos + 1 - squareWidth / 2, rightNotesVector.getY()));
}
void PlayerPack::render(Uint32 time, bool beatSync)
{
	leftNoteBar->render(time);
	rightNoteBar->render(time);
	leftPoint->render(time);
	rightPoint->render(time);
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
		for (Note* o : screenArrows_)
		{
			if (o != nullptr) {
				o->update(time);
				x = selectScreenArrows.front();
			}
			
		}
		for (Note* o : screenButtons_)
		{
			if (o != nullptr)
			{
				o->update(time);
				y = selectScreenButtons.front();
			}
		}
		if (!screenArrows_.empty() && screenArrows_.front()->getPosition().getY() > 550)
		{
			Note* aux = screenArrows_.front();
			if (x == 5) {
				playstate_->feedbackLeft->addFeedback(Resources::FeedbackPerfect);
				playstate_->scoreBar->updateBar(1);
				playstate_->updateScore(1);
			}
			delete aux;
			selectScreenArrows.pop_front();
			screenArrows_.pop_front();
			cout << "fuera" << endl;

			game_->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0);
		}
		if (!screenButtons_.empty() && screenButtons_.front()->getPosition().getY() > 550)
		{
			Note* aux = screenButtons_.front();
			if (y == 5) {
				playstate_->feedbackRight->addFeedback(Resources::FeedbackPerfect);
				playstate_->scoreBar->updateBar(1);
				playstate_->updateScore(1);
			}

			selectScreenButtons.pop_front();
			delete aux;
			screenButtons_.pop_front();
			cout << "fuera" << endl;

			game_->getServiceLocator()->getAudios()->playChannel(Resources::Error, 0);
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
	rightNoteBar->handleInput(time, event);
	return false;
}
PlayerPack::~PlayerPack()
{
	delete leftNoteBar;
	delete rightNoteBar;
	delete leftPoint;
	delete rightPoint;
	for (Note* o : screenArrows_)
	{
		delete o;
	}
	for (Note* o : screenButtons_)
	{
		delete o;
	}
}
