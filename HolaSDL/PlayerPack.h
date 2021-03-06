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
#include "checkML.h"

//Controls everything related to the player during the levels, Note control, Score, Feedback (individual, in Multiplayer, each Player has its own)

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
	int* califications = new int[4];

	int noteYLimit;
	int comboTextX;

	int combo = 0;
	int maxCombo = 0;
	void updateCombo();
	int controllerMode;
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
	void updateScoreNote(int accuracy);
	void addCombo(int i);
	int getCombo() { return combo; }
	int getMaxCombo() { return maxCombo; }
	void resetCombo();
	int* getCalifications();
	void addCalifications(int letter);
	void setComboActive(bool active) { comboTxt->setActive(active); if (active) updateCombo(); }
	void changeController(int controller);

	LevelInputManager* lip;
};

