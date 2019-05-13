#include <tuple>
#include "Resources.h"
#include "sdl_includes.h"

vector<Resources::FontInfo> Resources::fonts_ {
	{ ARIAL16, "resources/fonts/ARIAL.ttf", 16 },	//Not used, delete to save memory?
	{ ARIAL24, "resources/fonts/ARIAL.ttf", 40 },	//Not used, delete to save memory?
	{PIXEL30, "resources/fonts/NES-Chimera.ttf",30},	//Not used, delete to save memory? 
	{PIXEL20, "resources/fonts/NES-Chimera.ttf",20},	//Not used, delete to save memory?
	{PIXEL10, "resources/fonts/NES-Chimera.ttf",10 },	//Not used, delete to save memory?
	{PIXEL50, "resources/fonts/NES-Chimera.ttf",45},	//Not used, delete to save memory?
	{FIPPS10, "resources/fonts/Fipps-Regular.otf",10},	//Not used, delete to save memory?
	{FIPPS20, "resources/fonts/Fipps-Regular.otf",20},
	{FIPPS30, "resources/fonts/Fipps-Regular.otf",30},	//Not used, delete to save memory?
	{FIPPS50, "resources/fonts/Fipps-Regular.otf",50},	//Not used, delete to save memory?
	{RETRO10, "resources/fonts/Retro Gaming.ttf",10},
	{RETRO20, "resources/fonts/Retro Gaming.ttf",20},
	{RETRO30, "resources/fonts/Retro Gaming.ttf",30},
	{RETRO50, "resources/fonts/Retro Gaming.ttf",50}
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
		{testBG, "resources/images/FondoPrueba.png", 213, 120, 2, 1, 2},
		{PixelatedTextBG, "resources/images/FondoPixel.png", 213, 128, 2, 1, 2},
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
		{ScoreA, "resources/images/Letra_A.png", 16, 26, 1, 1, 1},
		{ScoreB, "resources/images/Letra_B.png", 16, 26, 1, 1, 1},
		{ScoreC, "resources/images/Letra_C.png", 16, 26, 1, 1, 1},
		{ScoreD, "resources/images/Letra_D.png", 16, 26, 1, 1, 1},
		{ScoreS, "resources/images/Letra_S.png", 16, 26, 1, 1, 1},
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
		{BackgroundHipHop, "resources/images/FondoHipHop.png", 213, 120, 2, 1, 2 },
		{BackgroundHipHopPixel, "resources/images/FondoHipHopPixel.png", 213, 120, 2, 1, 2 },
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
		{RedAura, "resources/images/RedVignette.png", 800, 600, 1, 1, 1},
		{NivelExtra, "resources/images/NivelExtra.png", 100, 100, 1, 1, 1},
		{ButtonPlaceholder, "resources/images/buttonPlaceholder.png", 153, 29, 1, 1, 1},
		{ButtonSelection, "resources/images/buttonSelection.png", 153, 29, 1, 1, 1},
		{MenuBG, "resources/images/menuBG.png", 50, 75, 1, 1, 1},
		{ButtonResume, "resources/images/buttonResume.png", 153, 29, 1, 1, 1},
		{ButtonRestart, "resources/images/buttonRestart.png", 153, 29, 1, 1, 1},
		{ButtonOptions, "resources/images/buttonOptions.png", 153, 29, 1, 1, 1},
		{ButtonExit, "resources/images/buttonExit.png", 153, 29, 1, 1, 1},
		{MenuCanciones, "resources/images/menuCanciones.png", 1600, 900, 1, 1, 1},
		{MasterHand,"resources/images/Dedo.png", 128, 128, 1, 1, 1},
		{Recuadro1P, "resources/images/Recuadro1P.png", 32, 100, 4, 1, 4},
		{Recuadro2P, "resources/images/Recuadro2P.png", 32, 100, 4, 1, 4},
		{EndBG, "resources/images/EndTemplate.png", 1600, 900, 1, 1, 1},
		{EndBG2, "resources/images/EndTemplate2.png", 1600, 900, 1, 1, 1},
		{PapitoBox, "resources/images/PapitoBox.png", 153, 65, 1, 1, 1},
		{Select, "resources/images/Select.png",100,19,1,1,1},
		{CabezaPapito , "resources/images/cabezaPapito.png", 40, 40, 1, 1, 1 },
		{CiuBG, "resources/images/fondoReggaeton.png", 213, 120, 2, 1, 2},
		{CiuBGPixel, "resources/images/fondoReggaetonPixel.png", 213, 120, 2, 1, 2},
		{PapitoIdle, "resources/images/papitoIdle.png", 60, 120, 3, 3, 7 },
		{PapitoTwerk, "resources/images/papitoDance.png", 60, 120, 2, 1, 2},
		{ExtraBG, "resources/images/fondoExtra.png", 208, 120, 2, 1, 2},
		{ExtraPixel, "resources/images/fondoExtraPixel.png", 208, 120, 2, 1, 2},
		{ShrekIdle, "resources/images/shrekIdle.png", 60, 120, 2, 1, 2 },
		{ShrekDance, "resources/images/shrekDance.png", 60, 120, 2, 1, 2},
		{SansIdle, "resources/images/sansIdle.png", 60, 120, 2, 1, 2 },
		{SansDance, "resources/images/sansDance.png", 60, 120, 3, 2, 4},
		{fourButtons, "resources/images/CuatroBotones.png", 75, 81, 1, 1, 1},
		{Crown, "resources/images/Crown.png",32,32,4,1,4},
		{Recuadro1PWin, "resources/images/Recuadro1PWinning.png", 32, 100, 4, 1, 4 },
		{Recuadro2PWin, "resources/images/Recuadro2PWinning.png", 32, 100, 4, 1, 4 },
		{MenuIcon, "resources/images/icon.png", 32, 100, 4, 1, 4 },
        {LeftArrowPlay, "resources/images/FlechaLeftPlay.png", 32, 32, 1, 1, 1 },
		{ButtonVol, "resources/images/volumeSprite.png", 153, 29, 1, 1, 1 },
		{VolSelection, "resources/images/volumeSelection.png", 153, 29, 1, 1, 1 },
		{RightArrowPlay, "resources/images/FlechaRightPlay.png", 32, 32, 1, 1, 1 },
		{UpArrowPlay, "resources/images/FlechaUpPlay.png", 32, 32, 1, 1, 1 },
		{DownArrowPlay, "resources/images/FlechaDownPlay.png", 32, 32, 1, 1, 1 },
		{XButtonPlay, "resources/images/BotonXPlay.png", 32, 32, 1, 1, 1 },
		{BButtonPlay, "resources/images/BotonCirculoPlay.png", 32, 32, 1, 1, 1 },
		{SquareButtonPlay, "resources/images/BotonCuadradoPlay.png", 32, 32, 1, 1, 1 },
		{TriangleButtonPlay, "resources/images/BotonTrianguloPlay.png", 32, 32, 1, 1, 1 },
		{ ButtonMusic, "resources/images/buttonMusic.png", 153, 29, 1, 1, 1},
		{ ButtonSound, "resources/images/buttonSound.png", 153, 29, 1, 1, 1 },
		{ ButtonControls, "resources/images/buttonControls.png", 153, 29, 1, 1, 1 },
		{ NewGameButton, "resources/images/NewGame.png", 153, 65, 1, 1, 1 },
		{ ChargeGameButton, "resources/images/Cargar.png", 153, 65, 1, 1, 1 },
		{ CreditsButton, "resources/images/Creditos_Menu.png", 153, 65, 1, 1, 1 },
		{ ZombieIdle, "resources/images/zombieIdle.png", 58, 94, 3, 2, 4 },
		{ ZombieDance, "resources/images/zombieDance.png", 58, 94, 3, 3, 7 },
		{ MainMenu, "resources/images/MenuPrincipal.png", 1600, 900, 1, 1, 1 },
		{ NewGameSelected, "resources/images/NuevaPartida2.png", 800, 200, 1, 1, 1 },
		{ NewGameNoSelected, "resources/images/NuevaPartida1.png", 800, 200, 1, 1, 1 },
		{ ChargeGameSelected, "resources/images/Continuar2.png", 800, 200, 1, 1, 1 },
		{ ChargeGameNoSelected, "resources/images/Continuar1.png", 800, 200, 1, 1, 1 },
		{ OptionsSelected, "resources/images/Opciones2.png", 800, 200, 1, 1, 1 },
		{ OptionsNoSelected, "resources/images/Opciones.png", 800, 200, 1, 1, 1 },
		{ CreditsSelected, "resources/images/Creditos2.png", 800, 200, 1, 1, 1 },
		{ CreditsNoSelected, "resources/images/Creditos1.png", 800, 200, 1, 1, 1 },
		{ ExitSelected, "resources/images/Salir2.png", 800, 200, 1, 1, 1 },
		{ ExitNoSelected, "resources/images/Salir1.png", 800, 200, 1, 1, 1 },
		{ ZombieBox, "resources/images/corpselillo_dialog.png", 153, 65, 1, 1, 1 },
		{ MarcelinoBox, "resources/images/marcelino_dialog.png", 153, 65, 1, 1, 1 },
		{ CabezaZombie , "resources/images/ZombieHead.png", 40, 40, 1, 1, 1 },
		{ Creditos, "resources/images/Creditos.png", 1600, 900, 1, 1, 1 },
		{ PericoRoom, "resources/images/fondoTutorial.png", 213, 120, 2, 1, 2 },
		{ PericoRoomPixel, "resources/images/fondoTutorialPixel.png", 213, 120, 2, 1, 2 },
		{ PericoEspejo, "resources/images/Perico-Espejo.png", 60, 120, 3, 2, 4 },
		{ TutoBox1, "resources/images/tutoBox1.png", 1224, 504, 1, 1, 1 },
		{ TutoBox2, "resources/images/tutoBox2.png", 1224, 504, 1, 1, 1 },
		{ TutoBox3, "resources/images/tutoBox3.png", 1224, 504, 1, 1, 1 },
		{ TutoBox4, "resources/images/tutoBox4.png", 1224, 504, 1, 1, 1 },
		{ TutoFiltro, "resources/images/TutoFiltro.png", 450, 338, 1, 1, 1 },
		{ AlienIdle, "resources/images/AlienFumeta.png", 60, 120, 3, 2, 5 },
		{ AlienDance, "resources/images/AlienSquat.png", 60, 120, 3, 2, 6 },
		{ AlienTransformacion, "resources/images/AlienTransformacion.png", 60, 120, 8, 4, 29 },
		{ MarcelinoIdle, "resources/images/MarcelinoIdle.png", 60, 120, 3, 2, 4 },
		{ MarcelinoDance, "resources/images/MarcelinoDab.png", 60, 120, 3, 2, 4 },
		{ AlienBox, "resources/images/AlienBox.png",153, 65, 1, 1, 1 },
		{ Lost, "resources/images/Lost.png", 213, 120, 2, 1, 2 },
		{ YouLost, "resources/images/YouLost.png", 213, 120, 1, 1, 1 },
		{ EstacionBg, "resources/images/fondoMadrid.png", 213, 120, 2, 1, 2 },
};

vector<Resources::TextMsgInfo> Resources::messages_ {
	//{ HelloWorld, "Hello World", { COLOR(0xaaffffff) }, ARIAL16 }
};

vector<Resources::MusicInfo> Resources::musics_ {
	{Test , "resources/sound/TutorialJuego.wav"},	//Not used, delete to save memory?
	{Sunflower, "resources/sound/sunflower.mp3"},	//Not used, delete to save memory?
	{Bill, "resources/sound/billijean_noGlitch.mp3"},
	{Error, "resources/sound/Error.wav"},	//Make it .mp3 to save memory?
	{Snare, "resources/sound/snare.wav"},	//Make it .mp3 to save memory?
	{Hiphop, "resources/sound/hiphop.mp3"},
	{Mapa, "resources/sound/Mapa.mp3"},
	{StarSound, "resources/sound/Star.wav"},	//Make it .mp3 to save memory?
	{ComboSound, "resources/sound/Combo.wav"},	//Make it .mp3 to save memory?
	{AllStar, "resources/sound/allstar.mp3"},
	{Megalovania, "resources/sound/megalovania.mp3"},
	{Asereje, "resources/sound/asereje.mp3"},
	{Africa, "resources/sound/africa.mp3"},
	{Test186BPM, "resources/sound/186-bpm.mp3"},
	{Papito, "resources/sound/Papito.mp3"},
	{Running, "resources/sound/RunningInThe90s.mp3"},
	{Error2, "resources/sound/Error.mp3"},
	{Ok, "resources/sound/ok.mp3"},
	{Shoot, "resources/sound/shoot.mp3"},
	{Rock, "resources/sound/rock.mp3"},
	{MainTheme, "resources/sound/MainTheme.mp3"},
	{Ambient, "resources/sound/ambient.mp3"},
	{Hardbass, "resources/sound/hardbass.mp3"}
};

vector<Resources::SoundInfo> Resources::sounds_ {
};


vector<Resources::SpecialInfo> Resources::specialImages_{

	{LoadingBG, "resources/images/EndTemplate.png", 1600, 900, 1, 1, 1},
	{LoadingAnim, "resources/images/HitAnimationGold.png", 32, 32, 3, 1, 3}
};