
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "EscenaPrueba.h"

using namespace std;
using uint = unsigned int;

int main(int argc, char* argv[]){
	EscenaPrueba* scene = new EscenaPrueba();
	try
	{
		scene->run();
	}
	catch (string e)
	{
		cout << e;
	}
	delete scene;
	return 0;
}