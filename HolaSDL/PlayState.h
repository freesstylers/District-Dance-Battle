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
#include "Character.h"
#include "SongBar.h"
#include "BarBackground.h"
#include "MiniGame.h"
#include "MinigameVaporwave.h"
#include "MinigameHipHop.h"
#include "EmptyObject.h"
#include "EffectVaporwave.h"
#include "Squares.h"
#include "Level.h"
#include "Background.h"
#include "TimerNoSingleton.h"
#include "PlayerPack.h"
#include "RedEffect.h"
#include "ParticleEngine.h"
#include "PauseMenu.h"

class PlayState : public GameState //main game class, where most of the gameplay will take place
{
protected:

	string levelName;
	bool effect = true;

	int tPlayers;
	int nlevel;
	bool isSingleplayer;
	bool difficultyMode;

	Timer* timer;
	int probqte;
	bool miniActive = false;
	TimerNoSingleton* minigameController;
	TimerNoSingleton* animationTimer;


	bool firstNote = true;
	bool songIsOver = false;
	bool isPaused = false;

	RedEffect* rf;

	Vector2D noteVel;
	MiniGame* minigame;
	EmptyObject* fourButtons;
	Character* perico;
	Character* enemy;
	EffectVaporwave* effectVaporWave;
	Level* level;
	Background* crown;

	BarBackground* songBarBG;

	bool beatSignal = false;	//used to signal animations to advance
	bool animationMiniGame = false;
	int animationFramesPerBeat = 2;	//determines how many animation frames to advance each beat

	int pointSize2P = 80;	//size of the point 
	int noteBarWidth2P = pointSize + 33;
	int noteSize2P = 50;	//size of the notes
	int pointOffset2P = 70;	//offset between the note bars and the center of the screen
	int initialNoteHeight2P = 70;	//height at which new notes will be generated
	
	int pointSize = 100;	//tama�o del pulsador/punto
	int noteBarWidth = pointSize + 33;
	int noteSize = 70;	//tama�o de nota 
	int pointOffset = 90;	//offset entre las barras de notas y el centro de la pantalla
	int initialNoteHeight = 70;	//altura a la cual se generan las notas en pantalla

	int maxScore = 1000000;
	
	double maxNoteValue = 0;
	double maxMinigameValue = 0;
	

	int minigameAmount = 3;

	int combo;

	double minigameScoreTotal = 0.10;

	int songEndWaitTime = 0;

public:
	BeatHandler* bh;
	PlayState(GameManager* g, int lvl, bool oneP, bool diff, int prevMaxScoreE_ = 0, int prevMaxScoreH_ = 0);
	void newGame();
	void newGame2P();
	~PlayState();
	virtual void update(Uint32 time);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatSync = false);
	void playSong(int song);
	void showError();
	void changeRedeffect();
	Vector2D setVel(double time);
	std::list<Note*> levelArrows_;
	std::list<Note*> levelButtons_;
	std::list<Note*> levelArrows2_;
	std::list<Note*> levelButtons2_;
	Background* bg;
	PauseMenu* pauseMenu;
	PlayerPack* player1;
	PlayerPack* player2;
	SongBar* songBar; //indicates time left, shaped like a note
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	Vector2D leftNotesVector2;
	Vector2D rightNotesVector2;
	MiniGame* getMinigame() { return minigame; }
	GameManager* getGameManager() { return manager; }
	ParticleEngine* particles;

	double msDiff = 0.0;  //difference between the time of a beat and the time when a note is created, in ms


	void updateScoreMinigame(int accuracy);
	void activateBeatSignal() { beatSignal = true; }
	bool getMiniActive() { return miniActive; }
	Character* getPerico() { return perico; }

	int getMaxScore() { return maxScore; }
	int getMaxNoteValue() { return maxNoteValue; }
	int getBPM() { return level->bpm; }
	bool pause();
	void resume(unsigned int timePaused);

	void restart();
	void exit();

	


protected:
	void deleteAll();
	
	void generateArrows();
	void generateButtons();

	void songOver();

	virtual void updateResolution();
private:
	int bgT;
	int enemyT;
	int prevMaxScoreE_;
	int prevMaxScoreH_;

};