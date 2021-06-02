#pragma once

#include "sdl_includes.h"
#include <string>
#include <vector>
#include "Resources.h"
#include "SDLTexturesManager.h"
#include "SDLAudioManager.h"
#include "SDLFontsManager.h"
#include "ServiceLocator.h"
#include "SRandBasedGenerator.h"
#include "checkML.h"

using namespace std;

const int MAXFPS = 144;

class Character;

class SDLGame {
public:
	SDLGame(string windowTitle_, int width, int height);
	virtual ~SDLGame();

	SDL_Window* getWindow() const; // returns a pointer to the SDL window
	SDL_Renderer* getRenderer() const; // returns a pointer to the SDL renderer

	int getWindowWidth() const; // returns the window width
	int getWindowHeight() const; // returns the window height
	int getMusicVolume() const;
	int getSoundVolume() const;
	int getDefaultWindowWidth() const; // returns the default window width (800)
	int getDefaultWindowHeight() const; // returns the default window height (600)
	double getWidthScale() const;
	double getHeightScale() const;
	const ServiceLocator* getServiceLocator() const; // returns a pointer to the resources
	// abstract methods to be implemented by subclasses
	virtual void start() = 0; // start the game
	virtual void stop() = 0;  // stop the game

	int deltaTime = 0; //Va cambiando segun el tiempo de refresco (se le multiplica a las velocidades)

	//void setController(bool xbox) { isXbox = xbox; };
	int getP1Controller();
	void setP1Controller(int value);
	int getP2Controller();
	void setP2Controller(int value);

	void setMusicVolume(int volume);
	void setSoundVolume(int volume);

private:
	void initSDL(); // initialize SDL (ttf, mixer, image, create window and renderer, etc)
	void closeSDL(); // close all SDL resources
	void initResources(); // initialize the SDLResources object with the data at the top of this file
	void closeResources(); // close the  SDLResources object (frees all memory)

	void render();

protected:
	ServiceLocator services_; // (textures, font, music, etc)
	SDLFontsManager fonts_;
	SDLTexturesManager textures_;
	SDLAudioManager audio_;
	SRandBasedGenerator random_;

	SDL_Window* window_; // the window
	SDL_Renderer* renderer_;  // the renderer

	string windowTitle_; // window title
	int width_; // window width
	int height_; // window height
	int musicVolume_ = 50;
	int soundVolume_ = 50;

	double widthScale_;
	double heightScale_;
	SDL_DisplayMode DM;

	Character* bg;
	Character* anim;

	//bool isXbox = true;
	//0 xbox, 1 ps4, 2 flechas, 3 teclado
	int P1Controller;
	int P2Controller;
};