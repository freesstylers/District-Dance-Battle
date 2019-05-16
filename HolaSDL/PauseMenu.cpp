#include "PauseMenu.h"
#include "TutorialState.h"
#include "PlayState.h"

PauseMenu::PauseMenu(SDLGame* game, PlayState* ps, bool isXbox) : GameObject(game), isXbox(isXbox)
{

	level = ps;


	double menuX = game->getDefaultWindowWidth() / 3;
	double menuY = game->getDefaultWindowHeight() / 6;
	double menuW = game->getDefaultWindowWidth() / 3;
	double menuH = game->getDefaultWindowHeight() * 2 / 3;

	double buttonConst = menuH / 8 - 50;

	double opX = menuX + (menuW * 0.3) / 2;
	double opY = menuY + (menuH * 0.3) / 2;
	double opW = menuW * 0.7;
	double opH = menuH * 0.7;


	bg = new EmptyObject(game, Vector2D(menuX, menuY), menuW, menuH, Resources::MenuBG);

	resume = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.18 + buttonConst), menuW / 2, 45, Resources::ButtonResume);

	restart = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.34 + buttonConst), menuW / 2, 45, Resources::ButtonRestart);

	options = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.5 + buttonConst), menuW / 2, 45, Resources::ButtonOptions);

	exit = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.66 + buttonConst), menuW / 2, 45, Resources::ButtonExit);

	menuButtons.push_back(resume);
	menuButtons.push_back(restart);
	menuButtons.push_back(options);
	menuButtons.push_back(exit);


	op_bg = new EmptyObject(game, Vector2D(menuX, menuY), menuW, menuH, Resources::MenuBG);

	music = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.1 + buttonConst), menuW / 2, 45, Resources::ButtonMusic);
	music->scale(0.8);
	musicSelect = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.1 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	sounds = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.295 + buttonConst), menuW / 2, 45, Resources::ButtonSound);
	sounds->scale(0.8);
	soundsSelect = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.295 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	controls = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.49 + buttonConst), menuW / 2, 45, Resources::ButtonControls);
	controls->scale(0.8);
	controlsSelect = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.49 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	op_exit = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.685 + buttonConst + 25), menuW / 2, 45, Resources::ButtonExit);

	musicTxt = new TextObject(game, game->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	soundTxt = new TextObject(game, game->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	controlTxt = new TextObject(game, game->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));

	updateTxt();

	optionsButtons.push_back(musicSelect);
	optionsButtons.push_back(soundsSelect);
	optionsButtons.push_back(controlsSelect);
	optionsButtons.push_back(op_exit);
	optionsButtons.push_back(music);
	optionsButtons.push_back(sounds);
	optionsButtons.push_back(controls);

	controller = SDL_GameControllerOpen(0);

	timer = new Timer();

	selection = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 2 / 3), menuW / 2, 45, Resources::ButtonSelection);
}

PauseMenu::~PauseMenu()
{
	delete timer;
	delete bg;
	delete op_bg;
	delete selection;
	delete musicTxt;
	delete soundTxt;
	delete controlTxt;

	for (GameObject* g : menuButtons) {
		delete g;
	}
	for (GameObject* g : optionsButtons) {
		delete g;
	}
}

void PauseMenu::activate()
{
	selectedButton = 0;
	timer->Reset();
	optionsOpen = false;
	selection->setPosition(menuButtons[selectedButton]->getPosition());
	selection->forceAnimationChange(Resources::ButtonSelection);

	op_bg->setActive(false);
	for (EmptyObject* g : optionsButtons) {
		g->setActive(false);
	}
	musicTxt->setActive(false);
	soundTxt->setActive(false);
	controlTxt->setActive(false);
}

bool PauseMenu::handleInput(Uint32 time, const SDL_Event& event)
{
	if (active_)
	{
		if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) {
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || event.key.keysym.sym == SDLK_UP) {
				
				selectedButton = (selectedButton == 0) ? 3 : selectedButton - 1;

				if (optionsOpen) {
					selection->setPosition(optionsButtons[selectedButton]->getPosition());

					if (selectedButton == 3)
						selection->forceAnimationChange(Resources::ButtonSelection);
					else
						selection->forceAnimationChange(Resources::VolSelection);
				}
				else
					selection->setPosition(menuButtons[selectedButton]->getPosition());
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || event.key.keysym.sym == SDLK_DOWN) {
				
				selectedButton = (selectedButton == 3) ? 0 : selectedButton + 1;

				if (optionsOpen) {
					selection->setPosition(optionsButtons[selectedButton]->getPosition());

					if (selectedButton == 3)
						selection->forceAnimationChange(Resources::ButtonSelection);
					else
						selection->forceAnimationChange(Resources::VolSelection);
				}
				else
					selection->setPosition(menuButtons[selectedButton]->getPosition());
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || event.key.keysym.sym == SDLK_RETURN) {
				if (optionsOpen) {
					switch (selectedButton) {
					case 3:
						toggleOptions();
						break;
					default:
						break;
					}
				}
				else {
					switch (selectedButton) {
					case 0:
						resumeSong();
						return true;
						break;
					case 1:
						restartSong();
						break;
					case 2:
						toggleOptions();
						break;
					case 3:
						exitSong();
						break;
					default:
						break;
					}
				}
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || event.key.keysym.sym == SDLK_RIGHT) {
				if (optionsOpen) {
					switch (selectedButton) {
					case 0:
						updateMusic(true);
						break;
					case 1:
						updateSound(true);
						break;
					case 2:
						updateControls();
						break;
					default:
						break;
					}
				}
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || event.key.keysym.sym == SDLK_LEFT) {
				if (optionsOpen) {
					switch (selectedButton) {
					case 0:
						updateMusic(false);
						break;
					case 1:
						updateSound(false);
						break;
					case 2:
						updateControls();
						break;
					default:
						break;
					}
				}
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) || event.key.keysym.sym == SDLK_DELETE) {
				resumeSong();
				return true;
			}
		}
	}

	return false;
}

void PauseMenu::resumeSong()
{
	timer->Update();
	float time = timer->DeltaTime() * 1000;
	level->resume(time);
}

void PauseMenu::toggleOptions()
{
	optionsOpen = !op_bg->isActive();

	op_bg->setActive(optionsOpen);

	for(EmptyObject* g : optionsButtons)
		g->setActive(optionsOpen);

	musicTxt->setActive(optionsOpen);
	soundTxt->setActive(optionsOpen);
	controlTxt->setActive(optionsOpen);


	if (optionsOpen) {
		selectedButton = 0;
		selection->setPosition(optionsButtons[selectedButton]->getPosition());
		selection->forceAnimationChange(Resources::VolSelection);
	}
	else {
		selectedButton = 2;
		selection->setPosition(menuButtons[selectedButton]->getPosition());
		selection->forceAnimationChange(Resources::ButtonSelection);
	}
}

void PauseMenu::restartSong()
{
	level->restart();
}

void PauseMenu::exitSong()
{
	if (TutorialState * a = dynamic_cast<TutorialState*>(level))
		a->exit();

	else
		level->exit();
}

void PauseMenu::updateMusic(bool raise)
{
	if (raise && game_->getMusicVolume() < 100) {
		game_->setMusicVolume(game_->getMusicVolume() + 5);
	}
	else if(!raise && game_->getMusicVolume() > 0) {
		game_->setMusicVolume(game_->getMusicVolume() - 5);
	}


	game_->getServiceLocator()->getAudios()->setChannelVolume(game_->getMusicVolume(), 0);
	game_->getServiceLocator()->getAudios()->setChannelVolume(game_->getMusicVolume(), 2);

	game_->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 2);

	updateTxt();
}

void PauseMenu::updateSound(bool raise)
{
	if (raise && game_->getSoundVolume() < 100) {
		game_->setSoundVolume(game_->getSoundVolume() + 5);
	}
	else if (!raise && game_->getSoundVolume() > 0) {
		game_->setSoundVolume(game_->getSoundVolume() - 5);
	}

	game_->getServiceLocator()->getAudios()->setChannelVolume(game_->getSoundVolume(), 1);
	game_->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 1);

	updateTxt();
}

void PauseMenu::updateControls()
{
	isXbox = level->changeControls();

	updateTxt();
}

void PauseMenu::updateTxt()
{
	musicTxt->setText(to_string(game_->getMusicVolume()), SDL_Color{ 0, 0, 0, 255 });
	musicTxt->setPosition(musicSelect->getPosition() + Vector2D(musicSelect->getWidth() / 2, musicSelect->getHeight() / 2) - Vector2D(musicTxt->getWidth() / 2, musicTxt->getHeight() / 2));

	soundTxt->setText(to_string(game_->getSoundVolume()), SDL_Color{ 0, 0, 0, 255 });
	soundTxt->setPosition(soundsSelect->getPosition() + Vector2D(soundsSelect->getWidth() / 2, soundsSelect->getHeight() / 2) - Vector2D(soundTxt->getWidth() / 2, soundTxt->getHeight() / 2));

	if (isXbox)
		controlTxt->setText("Xbox", SDL_Color{ 0, 0, 0, 255 });
	else
		controlTxt->setText("PS4", SDL_Color{ 0, 0, 0, 255 });

	controlTxt->setPosition(controlsSelect->getPosition() + Vector2D(controlsSelect->getWidth() / 2, controlsSelect->getHeight() / 2) - Vector2D(controlTxt->getWidth() / 2, controlTxt->getHeight() / 2));


	ofstream file("resources/data/options.ddb");

	file << "MUSIC" << endl << game_->getMusicVolume() << endl << "SOUND" << endl << game_->getSoundVolume() << endl << "CONTROLLER" << endl << game_->getController();

	file.close();
}


void PauseMenu::update(Uint32 time)
{
}

void PauseMenu::render(Uint32 time, bool beatSync)
{
	if (active_) {
		bg->render(time);
		for (EmptyObject* g : menuButtons) {
			g->render(time);
		}

		op_bg->render(time);
		for (EmptyObject* g : optionsButtons) {
			g->render(time);
		}

		selection->render(time);
		musicTxt->render(time);
		soundTxt->render(time);
		controlTxt->render(time);
	}
}