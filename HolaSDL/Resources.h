#pragma once

#include "sdl_includes.h"
#include <string>
#include <vector>

using namespace std;

class Resources {
public:

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
		Dance
		
		// text
	};

	enum AudioId {
		// music
		Test,
		Sunflower,
		Bill,
		Error,
		Snare,
		// sound effects

	};

	enum FontId {
		//Ejemplo de fuentes --> ARIAL16
		ARIAL16,
		ARIAL24,
		PIXEL30,
		PIXEL20,
		PIXEL10
	};


	struct FontInfo {
		FontId id;
		string fileName;
		int size;
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
	static vector<TextMsgInfo> messages_; // initialized in .cpp
	static vector<MusicInfo> musics_; // initialized in .cpp
	static vector<SoundInfo> sounds_; // initialized in .cpp

};
