#include <tuple>
#include "Resources.h"
#include "sdl_includes.h"

vector<Resources::FontInfo> Resources::fonts_ {
	//{ ARIAL16, "resources/fonts/ARIAL.ttf", 16 }
};

vector<Resources::ImageInfo> Resources::images_ {

//Enum, file path, frame width, frame height, columns, rows, frame total//

	{LeftArrow, "resources/images/FlechaLeft.png", 32, 32, 1, 1, 1},
	{RightArrow, "resources/images/FlechaRight.png", 32, 32, 1, 1, 1},
	{UpArrow, "resources/images/FlechaUp.png", 32, 32, 1, 1, 1},
	{DownArrow, "resources/images/FlechaDown.png", 32, 32, 1, 1, 1},
	{AButton, "resources/images/BotonA.png", 32, 32, 1, 1, 1},
	{BButton, "resources/images/BotonB.png", 32, 32, 1, 1, 1},
	{XButton, "resources/images/BotonX.png", 32, 32, 1, 1, 1},
	{YButton, "resources/images/BotonY.png", 32, 32, 1, 1, 1},
	{FlechaEspBomba, "resources/images/FlechaEspBomba.png", 32, 32, 1, 1, 1},
    {Point, "resources/images/Point.png", 32, 32, 1, 1, 1},
	{NoteIcon, "resources/images/Nota.png", 9, 11, 1, 1, 1},
	{YellowBar, "resources/images/enemy_mana_bar_002.png", 196, 16, 1, 1, 1},
	{PericoIdle, "resources/images/PericoIdle.png", 60, 120, 3, 2, 4},
	{PericoDab, "resources/images/PericoDab.png", 60, 120, 2, 1, 2},
	{PericoDance1, "resources/images/PericoBaile1.png", 60, 120, 2, 1, 2},
	{PericoMaxPower, "resources/images/PericoMaxPower.png", 60, 120, 2, 2, 3},
	{FeedbackBad, "resources/images/Bad.png", 64, 64, 2, 1, 2},
	{FeedbackRegular, "resources/images/Regular.png", 64, 64, 2, 1, 2},
	{FeedbackPerfect, "resources/images/Perfect.png", 64, 64, 2, 1, 2},
	{FeedbackGood, "resources/images/Good.png", 64, 64, 2, 1, 2},
	{Blank, "resources/images/blank.png", 64, 64, 1, 1, 1},
	{EffectVaporWave, "resources/images/VW2.png", 450, 338, 5, 9, 42 },
	{Square, "resources/images/Recuadro.png", 32, 100, 4, 1, 4},
	{SquareMiss,"resources/images/RecuadroMiss.png", 32, 100, 2, 1, 2},
	{testBG, "resources/images/FondoPrueba.png", 128, 100, 2, 1, 2},
	{PixelatedTextBG, "resources/images/FondoPixel.png", 128, 100, 2, 1, 2},
	{RobotIdle, "resources/images/RobotVaporwave.png", 60, 120, 2, 1, 2},
	{RobotDance, "resources/images/VaporwaveDance.png", 60, 120, 3, 2, 4},
	{Mira, "resources/images/mira.png", 60, 120, 3, 2, 4},
};

vector<Resources::TextMsgInfo> Resources::messages_ {
	//{ HelloWorld, "Hello World", { COLOR(0xaaffffff) }, ARIAL16 }
};

vector<Resources::MusicInfo> Resources::musics_ {
	{Test , "resources/sound/TutorialJuego.wav"},
	{Sunflower, "resources/sound/sunflower.mp3"},
	{Bill, "resources/sound/billijean_noGlitch.mp3"},
	{Error, "resources/sound/Error.WAV"}
};

vector<Resources::SoundInfo> Resources::sounds_ {
};

