#pragma once
#include <cstdlib>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include "Background.h"
#include "BarBackground.h"
#include "BeatHandler.h"
#include "Character.h"
#include "checkML.h"
#include "EmptyObject.h"
#include "GameObject.h"
#include "GameState.h"
#include "Level.h"
#include "Note.h"
#include "ParticleEngine.h"
#include "PauseMenu.h"
#include "PlayerPack.h"
#include "Squares.h"
#include "SongBar.h"
#include "Timer.h"

//Clase de estado principal
class PlayState : public GameState //main game class, where most of the gameplay will take place
{
protected:

	string levelName;
	bool effect = true;

	int tPlayers;
	int nlevel;

	bool isSingleplayer;	//Level settings one or two players
	bool difficultyMode;	//and hard or easy mdoe

	Timer* timer;	//We use this timer for the notes handler
	Timer* extraTimer;	//This timer is used for pauses

	bool firstNote = true;
	bool songIsOver = false; 
	bool isPaused = false;

	Character* perico = nullptr;	//Main character
	Character* enemy = nullptr;	//Enemy character
	Level* level = nullptr;
	Background* crown = nullptr;

	BarBackground* songBarBG;

	bool beatSignal = false;	//used to signal animations to advance
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

	int songEndWaitTime = 0;

	int volume = 60;

	bool isLost();
	void deleteAll();
	void generateArrows();
	void generateButtons();
	void songOver();

public:
	BeatHandler* bh;
	PlayState(GameManager* g, int lvl, bool oneP, bool diff, int prevMaxScoreE_ = 0, int prevMaxScoreH_ = 0);
	void newGame();
	void newGame2P();
	virtual ~PlayState();
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
	Background* bg;
	PauseMenu* pauseMenu;
	PlayerPack* player1;
	PlayerPack* player2 = nullptr;
	SongBar* songBar; //indicates time left, shaped like a note
	Vector2D leftNotesVector;
	Vector2D rightNotesVector;
	Vector2D leftNotesVector2;
	Vector2D rightNotesVector2;
	GameManager* getGameManager() { return manager; }
	ParticleEngine* particles;	//We use particles when you hit a combo or earn a star

	EmptyObject* Lost;
	EmptyObject* youLost;

	double msDiff = 0.0;  //difference between the time of a beat and the time when a note is created, in ms


	void activateBeatSignal() { beatSignal = true; }
	Character* getPerico() { return perico; }

	int getMaxScore() { return maxScore; }
	int getMaxNoteValue() { return maxNoteValue; }
	int getBPM() { return level->bpm; }
	virtual bool pause();
	virtual void resume(unsigned int timePaused);
	bool changeControls();

	virtual void restart();
	virtual void exit();

	void updateOptionsFile() { manager->updateOptionsFile(); }

private:
	int bgT;
	int enemyT;
	int prevMaxScoreE_;
	int prevMaxScoreH_;

};