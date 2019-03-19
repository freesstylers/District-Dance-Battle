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
#include "BeatHandler.h"
#include "LevelInputManager.h"
#include "Character.h"
#include "SongBar.h"
#include "BarBackground.h"
#include "MiniGame.h"
#include "ScoreBar.h"
#include "Feedback.h"
#include "EmptyObject.h"
#include "Level.h"
#include "Background.h"
#include "TimerNoSingleton.h"
#include "PlayerPack.h"

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

	int pointSize = 50;	//size of the point 
	int noteBarWidth = pointSize + 13;
	int noteSize = 30;	//size of the notes
	int pointOffset = 50;	//offset between the note bars and the center of the screen
	int initialNoteHeight = 70;	//height at which new notes will be generated

	int maxScore = 400;
	int currentScore = 0;
	int maxNoteValue = 0;

public:
	BeatHandler* bh;
	ScoreBar* scoreBar;
	PlayState(GameManager* g);
	void newGame();
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	void playSong(int song);
	void showError();
	Vector2D setVel(double time);
	std::list<Note*> levelArrows_;
	std::list<Note*> levelButtons_;
	std::list<Note*> levelArrows2_;
	std::list<Note*> levelButtons2_;
	Feedback* feedbackLeft;
	Feedback* feedbackRight;
	Background* bg;
	PlayerPack* player1;
	PlayerPack* player2;
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	Vector2D leftNotesVector2;
	Vector2D rightNotesVector2;
	MiniGame* getMinigame() { return minigame; }
	GameManager* getGameManager() { return manager; }

	double msDiff = 0.0;  //difference between the time of a beat and the time when a note is created, in ms

	void updateScore(int accuracy) { currentScore += maxNoteValue * (1 / accuracy); }

protected:
	void deleteAll();
	int getScore();
	void generateArrows();
	void generateButtons();

	void songOver();
private:

};