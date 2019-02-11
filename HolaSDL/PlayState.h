#pragma once
#include "GameState.h"

//Constantes


class PlayState : public GameState //Clase para las batallas y jugabilidad básica, render lo hereda de GameState, mantiene update y handleEvent independientes
{
protected:
	
	Game* game;
	
public:
	PlayState(Game* g); //Crea estado (tal vez para niveles de dificultad con un int o bool)
	void newGame(); //Inicializa objetos
	void loadSave(); 
	~PlayState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
	void saveGame(int code);
	void DeleteAll(); //Para borrado de objetos, por aquello de no dejar basura
};

