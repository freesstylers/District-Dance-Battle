#include <tuple>
#include "Resources.h"
#include "sdl_includes.h"

vector<Resources::FontInfo> Resources::fonts_ {
	//Forma de usar las fuentes --> { ARIAL16, "resources/fonts/ARIAL.ttf", 16 }
};

vector<Resources::ImageInfo> Resources::images_ {

//Enum, dirección a archivo, ancho de frame, alto de frame, columnas, filas, total de frames//

	{FlechaLeft, "resources/images/FlechaLeft.png", 32, 32, 1, 1, 1},
	{FlechaRight, "resources/images/FlechaRight.png", 32, 32, 1, 1, 1},
	{FlechaUp, "resources/images/FlechaUp.png", 32, 32, 1, 1, 1},
	{FlechaDown, "resources/images/FlechaDown.png", 32, 32, 1, 1, 1},
    {Point, "resources/images/Point.png", 32, 32, 1, 1, 1},
	{PericoIdle, "resources/images/PericoIdle.png", 60, 120, 3, 2, 4},
	{PericoDab, "resources/images/PericoDab.png", 60, 120, 2, 1, 2},
	{PericoBaile1, "resources/images/PericoBaile1.png", 60, 120, 2, 1, 2}
};

vector<Resources::TextMsgInfo> Resources::messages_ {
	//Forma de usar el texto con fuentes --> { HelloWorld, "Hello World", { COLOR(0xaaffffff) }, ARIAL16 }
};

vector<Resources::MusicInfo> Resources::musics_ {
	{Pruebas , "resources/sound/TutorialJuego.wav"}
};

vector<Resources::SoundInfo> Resources::sounds_ {
};

