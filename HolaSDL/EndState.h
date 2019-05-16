#pragma once
#include "PlayState.h"
#include "GameManager.h"
#include "checkML.h"

//State used to display the end screen after a song, with the player's performance

class EndState :
	public GameState
{
public:
	
	EndState(GameManager* g, int prevMaxScoreE, int prevMaxScoreH, int* califs1, int actualScore, int maxScore, int percentage, int lvl, bool isSingleplayer, bool hardMode, int actualScore2 = 0, int* califs2 = nullptr);
	virtual ~EndState();
	void backToMenu(GameManager* gameManager);
	void backToMenuWin(GameManager* gameManager);
	void backToMenuLose(GameManager* gameManager);
	virtual bool handleEvent(Uint32 time, SDL_Event e);
	virtual void render(Uint32 time, bool beatHandler);
	void saveScore(int actualScore, int prevMaxScore);
	bool passed;

private:
	TextObject* points;
	TextObject* points2;
	TextObject* tooltip;
	TextObject* highScoreText;
	TextObject* highScore;
	TextObject* Wow1;
	TextObject* Good1;
	TextObject* Ok1;
	TextObject* Bad1;
	TextObject* Wow2 = nullptr;
	TextObject* Good2 = nullptr;
	TextObject* Ok2 = nullptr;
	TextObject* Bad2 = nullptr;

	EmptyObject* EndBG = nullptr;
	EmptyObject* Wow;
	EmptyObject* Good;
	EmptyObject* Ok;
	EmptyObject* Bad;
	EmptyObject* letter;
	EmptyObject* letter2 = nullptr;

	Character* perico;
	Character* perico2 = nullptr;


	string types[6] = { "Tutorial", "VaporWave", "HipHop", "??????" , "A" , "A" };
	int index = 0;
	int min = 0;
	int max = 1;
	int level;
	int punt;

	GameManager* gameManager;
	SDL_GameController* controller = NULL;
	void nextButton();
	void backButton();
	string puntos = "Puntuacion: ";
	string val = "Valoracion: ";
	
	string makeScoreBetter(int score);

	int prevScoreE_;
	bool hardMode_;
};

