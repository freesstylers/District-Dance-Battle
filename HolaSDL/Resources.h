#pragma once

#include "sdl_includes.h"
#include <string>
#include <vector>

using namespace std;

class Resources {
public:

	enum TextureId {
		// images
		FlechaLeft,
		FlechaRight,
		FlechaUp,
		FlechaDown,
		BotonA,
		BotonB,
		BotonX,
		BotonY,
		Point,
		Nota,
		Bar,
		PericoIdle,
		PericoDab,
		PericoBaile1,
		PericoMaxPower,
		FeedbackGood,
		FeedbackBad,
		FeedbackRegular,
		FeedbackPerfect
		// text
	};

	enum AudioId {
		// music
		Pruebas,
		Sunflower
		// sound effects

	};

	enum FontId {
		//Ejemplo de fuentes --> ARIAL16
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
