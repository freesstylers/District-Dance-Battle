#include <tuple>
#include "Resources.h"
#include "sdl_includes.h"

vector<Resources::FontInfo> Resources::fonts_ {
	//Forma de usar las fuentes --> { ARIAL16, "resources/fonts/ARIAL.ttf", 16 }
};

vector<Resources::ImageInfo> Resources::images_ {
	{FlechaLeft, "resources/images/FlechaLeft.png"},
	{FlechaRight, "resources/images/FlechaRight.png"},
	{FlechaUp, "resources/images/FlechaUp.png"},
	{FlechaDown, "resources/images/FlechaDown.png"},
    {Point, "resources/images/Point.png"},
	{AnimTest, "resources/images/AnimTest.png"}
};

vector<Resources::TextMsgInfo> Resources::messages_ {
	//Forma de usar el texto con fuentes --> { HelloWorld, "Hello World", { COLOR(0xaaffffff) }, ARIAL16 }
};

vector<Resources::MusicInfo> Resources::musics_ {
	{Pruebas , "resources/sound/TutorialJuego.wav"}
};

vector<Resources::SoundInfo> Resources::sounds_ {
};

