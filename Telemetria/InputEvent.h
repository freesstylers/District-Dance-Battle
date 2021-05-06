#pragma once
#include "Event.h"

class InputEvent :
	public Event
{

enum InputButton { rUp, rDown, rLeft, rRight, lUp, lDown, lLeft, lRight };

public:
	InputEvent(float timeStamp);

	void setNLevel(int nLevel_);
	
	void setPlayerButton(int playerButton_);

	void setLevelButton(InputButton levelButton_);

	void setDistance(float distance_);

	void setDistance(int numNote_);

	virtual string toJson();


protected:

	int nLevel = -1; //Número de nivel

	InputButton playerButton; //input del jugador
	InputButton levelButton; //Botón que debería de ser pulsado

	float distance; //Distancia de la nota hasta el pulsador
	int numNote; //Numero de nota dentro de la cancion

};

