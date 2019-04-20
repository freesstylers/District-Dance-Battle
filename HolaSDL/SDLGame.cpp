#include "SDLGame.h"
#include <time.h>
#include <iostream>

SDLGame::SDLGame(string windowTitle, int width, int height) :
		windowTitle_(windowTitle), width_(width), height_(height) {
	initSDL();
	initResources();
}

SDLGame::~SDLGame() {
	closeResources();
	closeSDL();
}

void SDLGame::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create window .
	SDL_GetCurrentDisplayMode(0, &DM);
	width_ = DM.w;
	height_ = DM.h;
	window_ = SDL_CreateWindow(windowTitle_.c_str(),
	SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN);

	// Create the renderer
	renderer_ = SDL_CreateRenderer(window_, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Clear screen (background color).
	SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);

	// hide cursor by default
	//SDL_ShowCursor(0);

	//the game is coded with an 800x600 resolution in mind, so we need to set values for rescaling
	widthScale_ = width_ / getDefaultWindowWidth();
	heightScale_ = height_ / getDefaultWindowHeight();

}

void SDLGame::closeSDL() {

	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;

	SDL_DestroyWindow(window_);
	window_ = nullptr;

	SDL_Quit();
}

void SDLGame::initResources() {

	fonts_.init();
	textures_.init();
	audio_.init();

	services_.setTextures(&textures_);
	services_.setAudios(&audio_);
	services_.setFonts(&fonts_);
	services_.setRandomGenerator(&random_);

	for (auto &image : Resources::images_) {
		textures_.loadFromImg(image.id, renderer_, image.fileName, image.width, image.height, image.columns, image.rows, image.frameTotal);
	}

	for (auto &font : Resources::fonts_) {
		fonts_.loadFont(font.id, font.fileName, font.size);
	}

	for (auto &txtmsg : Resources::messages_) {
		textures_.loadFromText(txtmsg.id, renderer_, txtmsg.msg,
				fonts_[txtmsg.fontId], txtmsg.color);
	}

	for (auto &sound : Resources::sounds_) {
		audio_.loadSound(sound.id, sound.fileName);
	}

	for (auto &music : Resources::musics_) {
		audio_.loadSound(music.id, music.fileName);
	}

}

void SDLGame::closeResources() {
}

SDL_Window* SDLGame::getWindow() const {
	return window_;
}

SDL_Renderer* SDLGame::getRenderer() const {
	return renderer_;
}

const ServiceLocator* SDLGame::getServiceLocator() const {
	return &services_;
}

int SDLGame::getWindowWidth() const {
	return width_;
}

int SDLGame::getWindowHeight() const {
	return height_;
}

int SDLGame::getDefaultWindowWidth() const
{
	return 1280;
}

int SDLGame::getDefaultWindowHeight() const
{
	return 720;
}

double SDLGame::getWidthScale() const
{
	return widthScale_;
}

double SDLGame::getHeightScale() const
{
	return heightScale_;
}

