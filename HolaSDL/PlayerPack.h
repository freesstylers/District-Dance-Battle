#pragma once
#include "Point.h"
#include "Note.h"
#include "Squares.h"
#include "Vector2D.h"
#include <list>
#include "ComboText.h"
#include "FeedbackPool.h"
#include "LevelInputManager.h"
#include "HitNotePool.h"
#include "PlayerPack.h"

class PlayState;
class PlayerPack : public GameObject
{
protected:
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	Point* leftPoint;
	Point* rightPoint;
	Squares* leftNoteBar;
	Squares* rightNoteBar;
	PlayState* playstate_;
	ComboText* comboTxt;
	Vector2D comboPosition;
	
	int noteYLimit;
	int comboTextX;

	int combo;
	void updateCombo();

public:
	double currentScore = 0;
	PlayerPack();
	PlayerPack(SDLGame* manager, PlayState* ps, int leftNotesPos, int rightNotesPos, int pointSize, int squareWidth, int player,bool OneP);
	~PlayerPack();
	virtual void render(Uint32 time, bool beatSync);
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	Point* getLeftPoint() { return leftPoint; }
	Point* getRightPoint() { return rightPoint; }
	Squares* getleftBar() { return leftNoteBar; }
	Squares* getrightBar() { return rightNoteBar; }
	std::list<Note*> screenArrows_;
	std::list<Note*> screenButtons_;
	FeedbackPool* feedbackLeft;
	HitNotePool* hitLeft;
	FeedbackPool* feedbackRight;
	HitNotePool* hitRight;
	ScoreBar* scoreBar;
	void errorLeft();
	void errorRight();
	void updateScoreNote(int accuracy);
	virtual void updateResolution(double wScale, double hScale);
	void addCombo(int i);
	void resetCombo();

	void setComboActive(bool active) { comboTxt->setActive(active); if (active) updateCombo(); }

	LevelInputManager* lip;
};

