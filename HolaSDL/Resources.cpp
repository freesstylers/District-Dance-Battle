#include <tuple>
#include "Resources.h"
#include "sdl_includes.h"

vector<Resources::FontInfo> Resources::fonts_ {
		{ ARIAL16, "resources/fonts/ARIAL.ttf", 16 },
	{ ARIAL24, "resources/fonts/ARIAL.ttf", 40 },
	{PIXEL30, "resources/fonts/NES-Chimera.ttf",25},
	{PIXEL20, "resources/fonts/NES-Chimera.ttf",20},
	{PIXEL10, "resources/fonts/NES-Chimera.ttf",10 }
	//{ ARIAL16, "resources/fonts/ARIAL.ttf", 16 }
};

vector<Resources::ImageInfo> Resources::images_{

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
		{YellowBar, "resources/images/enemy_mana_bar_002.png", 20, 100, 1, 1, 1},
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
		{SquareMiss,"resources/images/RecuadroMiss2.png", 32, 100, 2, 1, 2},
		{testBG, "resources/images/FondoPrueba.png", 128, 100, 2, 1, 2},
		{PixelatedTextBG, "resources/images/FondoPixel.png", 128, 100, 2, 1, 2},
		{RobotIdle, "resources/images/RobotVaporwave.png", 60, 120, 2, 1, 2},
		{RobotDance, "resources/images/VaporwaveDance.png", 60, 120, 3, 2, 4},
		{Mira, "resources/images/mira.png", 512, 512, 1, 1, 1},
		{TextboxPerico, "resources/images/perico_dialog.png",153, 65, 1, 1, 1},
		{TextBoxRobot, "resources/images/robot_dialog.png", 153, 65, 1, 1, 1},
		{TextBoxBlanc, "resources/images/blanc_dialog.png", 153, 65, 1, 1, 1},
		{AButton1, "resources/images/BotonA_1.png", 32, 32, 1, 1, 1},
		{BButton1,  "resources/images/BotonB_1.png", 32, 32, 1, 1, 1},
		{XButton1, "resources/images/BotonX_1.png", 32, 32, 1, 1, 1},
		{YButton1, "resources/images/BotonY_1.png", 32, 32, 1, 1, 1},
		{ScoreA, "resources/images/Letra_A.png", 100, 100, 1, 1, 1},
		{ScoreB, "resources/images/Letra_B.png", 100, 100, 1, 1, 1},
		{ScoreC, "resources/images/Letra_C.png",100, 100, 1, 1, 1},
		{ScoreD, "resources/images/Letra_D.png", 100, 100,1, 1, 1},
		{ScoreS, "resources/images/Letra_S.png", 100, 100, 1, 1, 1},
		{NumPlayersSwitch, "resources/images/1P2P.png", 34, 30, 2, 1, 2},
		{Star, "resources/images/Star.png", 40, 38, 1, 1, 1 },
		{PointPushed, "resources/images/PointPushed.png", 32, 32, 1, 1, 1 },
		{Dance, "resources/images/BotonDance.png", 68, 30, 2, 1, 2 },
		{Panel, "resources/images/Panel.png", 50, 75, 1, 1, 1 },
		{CabezaVaporWave, "resources/images/RobotVaporwaveHead.png", 40, 40, 1, 1, 1 },
		{GreyDialog, "resources/images/greyDialog.png",  153, 65, 1, 1, 1 },
		{EminemciaIdle, "resources/images/EminemciaIdle.png", 60, 120, 3, 2, 4 },
		{EminemciaDance, "resources/images/EminemciaDance.png", 60, 120, 4, 3, 9 },
		{FondoVK, "resources/images/FondoHipHop.png", 128, 100, 2, 1, 2},
		{EminemciaTextBox, "resources/images/EminemciaBox.png", 153, 65, 1, 1, 1},
		{CleonTextBox, "resources/images/CarlosBox.png", 153, 65, 1, 1, 1},
		{EminemciaHead, "resources/images/EminemciaHead.png", 40, 40, 1, 1, 1 },
		{BackgroundHipHop, "resources/images/FondoHipHop.png", 128, 100, 2, 1, 2 },
		{BackgroundHipHopPixel, "resources/images/FondoHipHopPixel.png", 128, 100, 2, 1, 2 },
		{HipHopEffect, "resources/images/HipHopEffect.png", 450, 338, 1, 1, 1},
		{Map, "resources/images/Mapa.png", 400, 300, 1, 1, 1},
		{Difficulty, "resources/images/Easy-Hard.png", 34, 30, 2, 1, 2},
		{MetroOn, "resources/images/metroOn.png", 64, 64, 1, 1, 1},
		{MetroOff, "resources/images/metroOff.png", 64, 64, 1, 1, 1},
		{BackMap, "resources/images/backmap.png", 153, 65, 1, 1, 1},
		{Exit, "resources/images/exit.png", 153, 65, 1, 1, 1},
		{Particles, "resources/images/Particles.png", 16, 16, 3, 2, 6},
		{HitGold, "resources/images/HitAnimationGold.png", 32, 32, 3, 1, 3},
		{HitSilver, "resources/images/HitAnimationSilver.png", 32, 32, 3, 1, 3},
		{HitCopper, "resources/images/HitAnimationCopper.png", 32, 32, 3, 1, 3},
		{StarBar, "resources/images/ScoreStars.png", 22, 102, 6, 6, 1},
		{RedAura, "resources/images/RedVignette.png", 800, 600, 1, 1, 1}
	
};

vector<Resources::TextMsgInfo> Resources::messages_ {
	//{ HelloWorld, "Hello World", { COLOR(0xaaffffff) }, ARIAL16 }
};

vector<Resources::MusicInfo> Resources::musics_ {
	{Test , "resources/sound/TutorialJuego.wav"},
	{Sunflower, "resources/sound/sunflower.mp3"},
	{Bill, "resources/sound/billijean_noGlitch.mp3"},
	{Error, "resources/sound/Error.wav"},
	{Snare, "resources/sound/snare.wav"},
	{Hiphop, "resources/sound/hiphop.mp3"},
	{Mapa, "resources/sound/Mapa.mp3"},
	{StarSound, "resources/sound/Star.wav"},
	{ComboSound, "resources/sound/Combo.wav"}
};

vector<Resources::SoundInfo> Resources::sounds_ {
};

