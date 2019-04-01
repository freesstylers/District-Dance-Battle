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
#include "MinigameVaporwave.h"
#include "MinigameHipHop.h"
#include "ScoreBar.h"
#include "Feedback.h"
#include "FeedbackPool.h"
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
	LevelInputManager* lip2;
	int probqte;
	bool miniActive = false;
	TimerNoSingleton* minigameController;
	TimerNoSingleton* animationTimer;


	bool firstNote = true;



	Vector2D noteVel;
	MinigameVaporwave* minigame;
	Character* perico;
	Character* robot;
	EmptyObject* effectVaporWave;
	Level* level;

	SongBar* songBar; //indicates time left, shaped like a note
	BarBackground* songBarBG;

	bool beatSignal = false;	//used to signal animations to advance
	bool animationMiniGame = false;
	int animationFramesPerBeat = 2;	//determines how many animation frames to advance each beat

	int pointSize2P = 50;	//size of the point 
	int noteBarWidth2P = pointSize + 13;
	int noteSize2P = 30;	//size of the notes
	int pointOffset2P = 50;	//offset between the note bars and the center of the screen
	int initialNoteHeight2P = 70;	//height at which new notes will be generated
	
	int pointSize = 80;	//tama�o del pulsador/punto
	int noteBarWidth = pointSize + 33;
	int noteSize = 50;	//tama�o de nota 
	int pointOffset = 70;	//offset entre las barras de notas y el centro de la pantalla
	int initialNoteHeight = 70;	//altura a la cual se generan las notas en pantalla

	int maxScore = 400;
	
	int maxNoteValue = 0;

public:
	BeatHandler* bh;
	ScoreBar* scoreBar;
	PlayState(GameManager* g,int lvl);
	void newGame(int lvl);
	void newGame2P(int lvl);
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
	std::list<Note*> levelArrows2_;
	std::list<Note*> levelButtons2_;
	std::list<int>selectArrows_;
	std::list<int>selectButtons_;
	std::list<int>selectArrows2_;
	std::list<int>selectButtons2_;
	FeedbackPool* feedbackLeft;
	FeedbackPool* feedbackRight;
	Background* bg;
	PlayerPack* player1;
	PlayerPack* player2;
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	Vector2D leftNotesVector2;
	Vector2D rightNotesVector2;
	MinigameVaporwave* getMinigame() { return minigame; }
	GameManager* getGameManager() { return manager; }

	double msDiff = 0.0;  //difference between the time of a beat and the time when a note is created, in ms
	int currentScore = 0;
	void updateScore(int accuracy) { currentScore += maxNoteValue * (1 / accuracy); }
	void activateBeatSignal() { beatSignal = true; }
	bool getMiniActive() { return miniActive; }

	int getScore();
	int getBPM() { return level->bpm; }


protected:
	void deleteAll();
	
	void generateArrows();
	void generateButtons();
	void generateSelectArrows();
	void generateSelectButtons();

	void songOver();

	virtual void updateResolution();
private:

};