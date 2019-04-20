#include "GameManager.h"

using namespace std;

int main(int ac, char** av) {
	
	//DemoGame g;
	//g.start();
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	GameManager g;
	g.start();
	return 0;
}
