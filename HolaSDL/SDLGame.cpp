#include "SDLGame.h"
#include <time.h>
#include <iostream>
#include "Character.h"

SDLGame::SDLGame(string windowTitle, int width, int height) :
		windowTitle_(windowTitle), width_(width), height_(height) {
	initSDL();

	initResources();
}

SDLGame::~SDLGame() {

	delete bg;
	bg = nullptr;

	delete anim;
	anim = nullptr;

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
	SDL_RenderSetLogicalSize(renderer_, width_, height_);
	// Create the renderer
	renderer_ = SDL_CreateRenderer(window_, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Clear screen (background color).
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);  // Dark grey.
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);

	// hide cursor by default
	//SDL_ShowCursor(0);

	//the game is coded with an 800x600 resolution in mind, so we need to set values for rescaling
	widthScale_ = (double)width_ / (double)getDefaultWindowWidth();
	heightScale_ = (double)height_ / (double)getDefaultWindowHeight();

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

	for (auto &image : Resources::specialImages_) {
		textures_.loadFromImg(image.id, renderer_, image.fileName, image.width, image.height, image.columns, image.rows, image.frameTotal);
	}

	bg = new Character(this, getDefaultWindowWidth(), getDefaultWindowHeight(), Vector2D(0, 0), Resources::LoadingBG);
	anim = new Character(this, 50, 50, Vector2D(0, 0), Resources::LoadingAnim);
	anim->setAnimationFramerate(4);
	anim->isAnimationSynced(false);
	render();

	for (auto &image : Resources::images_) {
		textures_.loadFromImg(image.id, renderer_, image.fileName, image.width, image.height, image.columns, image.rows, image.frameTotal);
		render();
	}

	for (auto &font : Resources::fonts_) {
		fonts_.loadFont(font.id, font.fileName, font.size);
		render();
	}

	for (auto &txtmsg : Resources::messages_) {
		textures_.loadFromText(txtmsg.id, renderer_, txtmsg.msg,
				fonts_[txtmsg.fontId], txtmsg.color);
		render();
	}

	for (auto &sound : Resources::sounds_) {
		audio_.loadSound(sound.id, sound.fileName);
		render();
	}

	for (auto &music : Resources::musics_) {
		audio_.loadSound(music.id, music.fileName);
		render();
	}

}

void SDLGame::closeResources() {
	
}

void SDLGame::render()
{
	double time = SDL_GetTicks();

	bg->render(time);
	anim->render(time);
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

int SDLGame::getMusicVolume() const
{
	return musicVolume_;
}

int SDLGame::getSoundVolume() const
{
	return soundVolume_;
}

void SDLGame::setMusicVolume(int volume)
{
	musicVolume_ = volume;
}

void SDLGame::setSoundVolume(int volume)
{
	soundVolume_ = volume;
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

int SDLGame::getP1Controller()
{
	return P1Controller;
}

void SDLGame::setP1Controller(int value)
{
	P1Controller = value;
}

int SDLGame::getP2Controller()
{
	return P2Controller;
}

void SDLGame::setP2Controller(int value)
{
	P2Controller = value;
}