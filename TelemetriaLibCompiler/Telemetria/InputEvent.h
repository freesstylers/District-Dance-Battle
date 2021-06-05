#pragma once
#include "Event.h"

class InputEvent :
	public Event
{


public:

	enum InputButton { rUp, rDown, rLeft, rRight, lUp, lDown, lLeft, lRight, bomb };
	
	const char* inputButton_str [9] =  {"rUp", "rDown", "rLeft", "rRight", "lUp", "lDown", "lLeft", "lRight", "bomb"};

	InputEvent(string timeStamp);

	void setNLevel(int nLevel);
	
	void setPlayerButton(InputButton playerButton);

	void setLevelButton(InputButton levelButton);

	void setDistance(float distance);

	void setNumNote(int numNote);

	virtual string toJson();

	virtual string toXML();

	virtual string toCSV();


protected:

	int nLevel_ = -1; //Número de nivel

	InputButton playerButton_; //input del jugador
	InputButton levelButton_; //Botón que debería de ser pulsado

	float distance_; //Distancia de la nota hasta el pulsador
	int numNote_; //Numero de nota dentro de la cancion

};

