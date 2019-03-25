#pragma once
#include "GameState.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "GameObject.h"
#include "Timer.h"
#include "Note.h"
#include "Point.h"
#include "BeatHandeler.h"
#include "LevelInputManager.h"
#include "Character.h"
#include "SongBar.h"
#include "BarBackground.h"
#include "MiniGame.h"
#include "MinigameVaporwave.h"
#include "ScoreBar.h"
#include "Feedback.h"
#include "FeedbackPool.h"
#include "EmptyObject.h"
#include "Squares.h"
#include "Level.h"
#include "Background.h"
#include "TimerNoSingleton.h"

class PlayState : public GameState //main game class, where most of the gameplay will take place
{
protected:

	string levelName;
	bool effect = true;

	Timer* timer;
	LevelInputManager* lip;
	int probqte;
	bool miniActive = false;
	TimerNoSingleton* minigameController;
	TimerNoSingleton* animationTimer;


	bool firstNote = true;



	Vector2D noteVel;
	MiniGame* minigame;
	Character* perico;
	Character* robot;
	EmptyObject* effectVaporWave;
	Level* level;

	SongBar* songBar; //indicates time left, shaped like a note
	BarBackground* songBarBG;

	bool beatSignal = false;	//used to signal animations to advance
	bool animationMiniGame = false;
	int animationFramesPerBeat = 2;	//determines how many animation frames to advance each beat

	int pointSize = 80;	//size of the point 
	int noteBarWidth = pointSize + 33;
	int noteSize = 50;	//size of the notes
	int pointOffset = 70;	//offset between the note bars and the center of the screen
	int initialNoteHeight = 70;	//height at which new notes will be generated

	int maxScore = 400;
	int currentScore = 0;
	int maxNoteValue = 0;

public:
	BeatHandeler* bh;
	ScoreBar* scoreBar;
	PlayState(GameManager* g);
	void newGame();
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	void playSong(int song);
	void showError();
	void errorLeft();
	void errorRight();
	Vector2D setVel(double time);
	std::list<Note*> levelArrows_;
	std::list<Note*> levelButtons_;
	std::list<Note*> screenArrows_; 
	std::list<Note*> screenButtons_;
	std::list<int> selectArrows_;
	std::list<int>selectButtons_;
	Point* leftPoint; 
	Point* rightPoint;
	FeedbackPool* feedbackLeft;
	FeedbackPool* feedbackRight;
	Squares* leftNoteBar;
	Squares* rightNoteBar;
	Background* bg;
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	MiniGame* getMinigame() { return minigame; }
	GameManager* getGameManager() { return manager; }

	double msDiff = 0.0;  //difference between the time of a beat and the time when a note is created, in ms

	void updateScore(int accuracy) { currentScore += maxNoteValue * (1 / accuracy); }
	void activateBeatSignal() { beatSignal = true; }

protected:
	void deleteAll();
	int getScore();
	void generateArrows();
	void generateButtons();

	void songOver();
private:

};