#include "GameManager.h"
#include <clocale>
#include "checkML.h"

using namespace std;

int main(int ac, char** av) {
	
	setlocale(LC_ALL, "");

	GameManager g;
	g.start();
	return 0;
}
