#include <tuple>
#include "Resources.h"
#include "sdl_includes.h"

vector<Resources::FontInfo> Resources::fonts_ {
	//Forma de usar las fuentes --> { ARIAL16, "resources/fonts/ARIAL.ttf", 16 }
};

vector<Resources::ImageInfo> Resources::images_ {

//Enum, direcci�n a archivo, ancho de frame, alto de frame, columnas, filas, total de frames//

	{FlechaLeft, "resources/images/FlechaLeft.png", 32, 32, 1, 1, 1},
	{FlechaRight, "resources/images/FlechaRight.png", 32, 32, 1, 1, 1},
	{FlechaUp, "resources/images/FlechaUp.png", 32, 32, 1, 1, 1},
	{FlechaDown, "resources/images/FlechaDown.png", 32, 32, 1, 1, 1},
	{BotonA, "resources/images/BotonA.png", 32, 32, 1, 1, 1},
	{BotonB, "resources/images/BotonB.png", 32, 32, 1, 1, 1},
	{BotonX, "resources/images/BotonX.png", 32, 32, 1, 1, 1},
	{BotonY, "resources/images/BotonY.png", 32, 32, 1, 1, 1},
    {Point, "resources/images/Point.png", 32, 32, 1, 1, 1},
	{Nota, "resources/images/Nota.png", 9, 11, 1, 1, 1},
	{Bar, "resources/images/enemy_mana_bar_001.png", 196, 16, 1, 1, 1},
	{PericoIdle, "resources/images/PericoIdle.png", 60, 120, 3, 2, 4},
	{PericoDab, "resources/images/PericoDab.png", 60, 120, 2, 1, 2},
	{PericoBaile1, "resources/images/PericoBaile1.png", 60, 120, 2, 1, 2},
	{PericoMaxPower, "resources/images/PericoMaxPower.png", 69, 120, 2, 2, 3},
	{FeedbackBad, "resources/images/Bad.png", 64, 64, 2, 1, 2},
	{FeedbackRegular, "resources/images/Regular.png", 64, 64, 2, 1, 2},
	{FeedbackPerfect, "resources/images/Perfect.png", 64, 64, 2, 1, 2},
	{FeedbackGood, "resources/images/Good.png", 64, 64, 2, 1, 2}
};

vector<Resources::TextMsgInfo> Resources::messages_ {
	//Forma de usar el texto con fuentes --> { HelloWorld, "Hello World", { COLOR(0xaaffffff) }, ARIAL16 }
};

vector<Resources::MusicInfo> Resources::musics_ {
	{Pruebas , "resources/sound/TutorialJuego.wav"},
	{Sunflower, "resources/sound/sunflower.mp3"}
};

vector<Resources::SoundInfo> Resources::sounds_ {
};

