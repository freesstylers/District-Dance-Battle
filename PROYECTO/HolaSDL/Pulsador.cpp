#include "Pulsador.h"



Pulsador::Pulsador()
{
}


Pulsador::~Pulsador()
{
}

void Pulsador::handleInput(Uint32 time, const SDL_Event& event) {	// ¿handleinput en flechas?


}

int Pulsador::checkAccuracy(double xPosition) {
	//comprueba la precisión de la nota en la posición incluida como parámetro, devuelve un valor int que determina la precisión
	//0 bad, 1 good, 2 perfect? Y playstate calcula la puntuación a partir de este valor según la canción

	//esta función es llamada por la flecha desde su handleInput
}

void Pulsador::update(Uint32 time) {


}

void Pulsador::render(Uint32 time) {


}
