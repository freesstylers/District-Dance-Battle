#pragma once

#include "sdl_includes.h"
#include <string>
#include <vector>
#include "checkML.h"

using namespace std;

class Resources {
public:

	enum SpecialId {
		LoadingBG = 999,
		LoadingAnim = 1000
	};

	enum TextureId {
		// images
		LeftArrow,
		RightArrow,
		UpArrow,
		DownArrow,
		AButton,
		BButton,
		XButton,
		YButton,
		FlechaEspBomba,
		Point,
		NoteIcon,
		YellowBar,
		PericoIdle,
		PericoDab,
		PericoDance1,
		PericoMaxPower,
		FeedbackGood,
		FeedbackBad,
		FeedbackRegular,
		FeedbackPerfect,
		Blank,
		EffectVaporWave,
		Square,
		SquareMiss,
		testBG,
		PixelatedTextBG,
		RobotIdle,
		RobotDance,
		Mira,
		TextboxPerico,
		TextBoxRobot,
		TextBoxBlanc,
		AButton1,
		BButton1,
		XButton1,
		YButton1,
		ScoreA,
		ScoreB,
		ScoreC,
		ScoreD,
		ScoreS,
		NumPlayersSwitch,
		Star,
		PointPushed,
		Dance,
		Panel,
		CabezaVaporWave,
		GreyDialog,
		EminemciaIdle,
		EminemciaDance, 
		FondoVK,
		EminemciaTextBox,
		CleonTextBox,
		EminemciaHead,
		BackgroundHipHop,
		BackgroundHipHopPixel,
		HipHopEffect,
		Map,
		Difficulty,
		MetroOn,
		MetroOff,
		BackMap,
		Exit,
		Particles,
		HitGold,
		HitSilver,
		HitCopper,
		StarBar,
		RedAura,
		NivelExtra,
		ButtonPlaceholder,
		ButtonSelection,
		MenuBG,
		ButtonResume,
		ButtonRestart,
		ButtonOptions,
		ButtonExit,
		MenuCanciones,
		MasterHand,
		Recuadro1P,
		Recuadro2P,
		EndBG,
		EndBG2,
		PapitoBox,
		Select,
		CabezaPapito,
		CiuBG,
		CiuBGPixel,
		PapitoIdle,
		PapitoTwerk,
		ExtraBG,
		ExtraPixel,
		ShrekIdle,
		ShrekDance,
		SansIdle,
		SansDance,
		fourButtons,
		Crown,
		Recuadro1PWin,
		Recuadro2PWin,
		MenuIcon,
     	LeftArrowPlay,
		ButtonVol,
		VolSelection,
		RightArrowPlay,
		UpArrowPlay,
		DownArrowPlay,
		XButtonPlay,
		BButtonPlay,
		SquareButtonPlay,
		TriangleButtonPlay,
		ButtonMusic,
		ButtonSound,
		ButtonControls,
		NewGameButton,
		ChargeGameButton,
		CreditsButton,
		ZombieIdle,
		ZombieDance,
		MainMenu,
		NewGameSelected,
		NewGameNoSelected,
		ChargeGameSelected,
		ChargeGameNoSelected,
		OptionsSelected,
		OptionsNoSelected,
		CreditsSelected,
		CreditsNoSelected,
		ExitSelected,
		ExitNoSelected,
		ZombieBox,
		MarcelinoBox,
		CabezaZombie,
		Credits,
		PericoRoom,
		PericoRoomPixel,
		PericoEspejo,
		TutoBox1,
		TutoBox2,
		TutoBox3,
		TutoBox4,
		TutoFiltro,
		AlienIdle,
		AlienDance,
		AlienTransformacion,
		MarcelinoIdle,
		MarcelinoDance,
		AlienBox,
		Lost,
		YouLost,
		EstacionBg,
		FondoRock,
		FondoRockPixel,
		AlienHead,
		FondoHardbass,
		FondoHardbassPixel,
		MarcelinoEraYo,
		newGameConfirm,
		TutoBox5,
		KeyA,
		KeyD,
		KeyDown,
		KeyLeft,
		KeyPoint,
		KeyPointPushed,
		KeyRight,
		KeyS,
		KeyUp,
		KeyW
		// text
	};

	enum AudioId {
		// music
		Tutorial,
		Sunflower,
		Bill,
		Error,
		Snare,
		Hiphop,
		Mapa,
		StarSound,
		ComboSound,
		AllStar,
		Megalovania,
		Asereje,
		Africa,
		Test186BPM,
		Papito,
		Running,
		Error2,
		Ok,
		Shoot,
		Rock,
		MainTheme,
		Ambient,
		Hardbass,
		Megalovania1
		// sound effects
	};

	enum FontId {
		//Ejemplo de fuentes --> ARIAL16
		ARIAL16,
		ARIAL24,
		PIXEL30,
		PIXEL20,
		PIXEL10,
		PIXEL50,
		FIPPS10,
		FIPPS20,
		FIPPS30,
		FIPPS50,
		RETRO10,
		RETRO20,
		RETRO30,
		RETRO50
	};


	struct FontInfo {
		FontId id;
		string fileName;
		int size;
	};

	struct SpecialInfo {
		SpecialId id;
		string fileName;
		int width;
		int height;
		int columns;
		int rows;
		int frameTotal;
	};


	struct ImageInfo {
		TextureId id;
		string fileName;
		int width;
		int height;
		int columns;
		int rows;
		int frameTotal;
	};

	struct TextMsgInfo {
		TextureId id;
		string msg;
		SDL_Color color;
		FontId fontId;
	};

	struct MusicInfo {
		AudioId id;
		string fileName;
	};

	struct SoundInfo {
		AudioId id;
		string fileName;

	};

	static vector<FontInfo> fonts_; // initialized in .cpp
	static vector<ImageInfo> images_; // initialized in .cpp
	static vector<SpecialInfo> specialImages_; // initialized in .cpp
	static vector<TextMsgInfo> messages_; // initialized in .cpp
	static vector<MusicInfo> musics_; // initialized in .cpp
	static vector<SoundInfo> sounds_; // initialized in .cpp

};
