#pragma once
#include "Flechas.h"
#include "Texture.h"
#include <list>
#include "Vector2D.h"
#include "Timer.h"

const int W = 1000;
const int H = 700;
const enum TextureName { FlechaText, PointText };
const int NUM_TEXTURES = 2;
const string IMAGES_PATH = "..\\images\\";
const int FRAME_RATE = 60;
class EscenaPrueba
{
private:
	int frames = 0;
	int start = 0;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool exit = false;
	struct TextureAtributes {
		string name;
		int row;
		int col;
	};
	Texture* textures[NUM_TEXTURES];
	const TextureAtributes TEXTURE_ATRIBUTES[NUM_TEXTURES] = { {"FlechaIzquierda.png", 1, 1}, {"Point.png",1,1} };
	list<Flechas*> lista;
	list<Flechas*>otros;
	bool generated = false;
	Timer* timer;
public:
	EscenaPrueba();
	~EscenaPrueba();
	void handleEvents();
	void render();
	void update();
	void generate();
	void run();
};

