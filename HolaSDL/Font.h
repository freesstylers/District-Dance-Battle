#ifndef FONT_H_
#define FONT_H_

//fuentes de texto

#include "sdl_includes.h"
#include <string>
#include "checkML.h"

using namespace std;

class Font {
public:
	Font();
	Font(string fileName, int size);
	virtual ~Font();

	bool load(string fileName, int size);
	void close();
	SDL_Surface* renderText(string text, SDL_Color color, Uint32 size) const;
private:
	TTF_Font *font_;
};

#endif /* FONT_H_ */
