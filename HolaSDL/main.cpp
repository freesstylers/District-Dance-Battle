#include "GameManager.h"
#include <clocale>
#include "checkML.h"

using namespace std;

int main(int ac, char** av) {
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	setlocale(LC_ALL, "");*/

	GameManager g;
	g.start();
	return 0;
}
