#include "PauseMenu.h"
#include "TutorialState.h"
#include "PlayState.h"

PauseMenu::PauseMenu(SDLGame* game, PlayState* ps, int controllerMode_) : GameObject(game), controllerMode(controllerMode_) //Creates all the UI related
{

	level = ps;

	double menuX = game->getDefaultWindowWidth() / 3;
	double menuY = game->getDefaultWindowHeight() / 6;
	double menuW = game->getDefaultWindowWidth() / 3;
	double menuH = game->getDefaultWindowHeight() * 2 / 3;

	double buttonConst = menuH / 9 - 50;

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

	music = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.08 + buttonConst), menuW / 2, 45, Resources::ButtonMusic);
	music->scale(0.8);
	musicSelect = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.08 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	sounds = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.275 + buttonConst), menuW / 2, 45, Resources::ButtonSound);
	sounds->scale(0.8);
	soundsSelect = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.275 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	controls = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.475 + buttonConst), menuW / 2, 45, Resources::ButtonControls);
	controls->scale(0.8);
	controlsSelect = new EmptyObject(game, Vector2D(menuX + menuX / 4 - 75, menuY + menuH * 0.475 + buttonConst + 41), menuW / 2, 45, Resources::ButtonVol);
	controlsSelect->setWidth(controlsSelect->getWidth() + 150);
	controlsSelect->scale(0.8);

	controls2 = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.650 + buttonConst), menuW / 2, 45, Resources::ButtonControls2);
	controls2->scale(0.8);
	controlsSelect2 = new EmptyObject(game, Vector2D(menuX + menuX / 4 - 75, menuY + menuH * 0.650 + buttonConst + 41), menuW / 2, 45, Resources::ButtonVol);
	controlsSelect2->setWidth(controlsSelect2->getWidth() + 150);
	controlsSelect2->scale(0.8);


	op_exit = new EmptyObject(game, Vector2D(menuX + menuX / 4, menuY + menuH * 0.8 + buttonConst + 25), menuW / 2, 45, Resources::ButtonExit);

	musicTxt = new TextObject(game, game->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	soundTxt = new TextObject(game, game->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	controlTxt = new TextObject(game, game->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	control2Txt = new TextObject(game, game->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));

	P1Controller = game->getP1Controller();
	P2Controller = game_->getP2Controller();

	updateTxt();

	optionsButtons.push_back(musicSelect);
	optionsButtons.push_back(soundsSelect);
	optionsButtons.push_back(controlsSelect);
	optionsButtons.push_back(controlsSelect2);
	optionsButtons.push_back(op_exit);
	optionsButtons.push_back(music);
	optionsButtons.push_back(sounds);
	optionsButtons.push_back(controls);
	optionsButtons.push_back(controls2);

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
	delete control2Txt;

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
	control2Txt->setActive(false);
}

bool PauseMenu::handleInput(Uint32 time, const SDL_Event& event)
{
	if (active_)
	{
		if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN) {
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) || event.key.keysym.sym == SDLK_UP) {
				

				if (optionsOpen) {
					selectedButton = (selectedButton == 0) ? 4 : selectedButton - 1;
					selection->setPosition(optionsButtons[selectedButton]->getPosition());

					if (selectedButton == 0 || selectedButton == 1)
					{
						selection->setHeight(musicSelect->getHeight());
						selection->setWidth(musicSelect->getWidth());
					}

					else if (selectedButton == 2 || selectedButton == 3)
					{
						selection->setHeight(controlsSelect->getHeight());
						selection->setWidth(controlsSelect->getWidth());
					}

					if (selectedButton == 4)
					{
						selection->setHeight(op_exit->getHeight());
						selection->setWidth(op_exit->getWidth());
						selection->forceAnimationChange(Resources::ButtonSelection);
					}
					else
						selection->forceAnimationChange(Resources::VolSelection);
				}
				else {
					selectedButton = (selectedButton == 0) ? 3 : selectedButton - 1;
					selection->setPosition(menuButtons[selectedButton]->getPosition());
				}
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || event.key.keysym.sym == SDLK_DOWN) {
				

				if (optionsOpen) {
					selectedButton = (selectedButton == 4) ? 0 : selectedButton + 1;
					selection->setPosition(optionsButtons[selectedButton]->getPosition());
					if (selectedButton == 0 || selectedButton == 1)
					{
						selection->setHeight(musicSelect->getHeight());
						selection->setWidth(musicSelect->getWidth());
					}

					else if (selectedButton == 2 || selectedButton == 3)
					{
						selection->setHeight(controlsSelect->getHeight());
						selection->setWidth(controlsSelect->getWidth());
					}

					if (selectedButton == 4)
					{
						selection->setHeight(op_exit->getHeight());
						selection->setWidth(op_exit->getWidth());
						selection->forceAnimationChange(Resources::ButtonSelection);
					}
					else
						selection->forceAnimationChange(Resources::VolSelection);
				}
				else {
					selectedButton = (selectedButton == 3) ? 0 : selectedButton + 1;
					selection->setPosition(menuButtons[selectedButton]->getPosition());
				}
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) || event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE) {
				if (optionsOpen) {
					switch (selectedButton) {
					case 4:
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
						updateControlsP1(true);
						break;
					case 3:
						updateControlsP2(true);
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
						updateControlsP1(false);
						break;
					case 3:
						updateControlsP2(false);
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

void PauseMenu::resumeSong() //Gets back to the level
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
	control2Txt->setActive(optionsOpen);

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
	if (TutorialState * a = dynamic_cast<TutorialState*>(level))
		a->restart();

	else
		level->restart();
}

void PauseMenu::exitSong()
{
	if (TutorialState * a = dynamic_cast<TutorialState*>(level))
		a->exit();

	else
		level->exit(); //returns to the Map State
}

void PauseMenu::updateMusic(bool raise) //Music control, the one at MainMenuState has the same code, but not possible to get by inheritance (one is a GameState, and other a GameObject) 
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

void PauseMenu::updateSound(bool raise) //SFX (like error sound) control, the one at MainMenuState has the same code, but not possible to get by inheritance (one is a GameState, and other a GameObject) 
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

void PauseMenu::updateControlsP1(bool raise)
{
	if (raise)
	{
		if (P1Controller == 0 || (P1Controller == 1 && game_->getP2Controller() != 2))
		{
			game_->setP1Controller((P1Controller + 1));
		}
		else
		{
			game_->setP1Controller(0);
		}
		P1Controller = game_->getP1Controller();

	}
	else
	{
		if (P1Controller == 1 || P1Controller == 2)
		{
			game_->setP1Controller((P1Controller - 1));
		}
		else if (P1Controller == 0)
		{
			if (game_->getP2Controller() != 2)
				game_->setP1Controller(2);
			else
				game_->setP1Controller(1);
		}
		P1Controller = game_->getP1Controller();
	}
	updateTxt();
	level->changeControls();
}

void PauseMenu::updateControlsP2(bool raise)
{
	if (raise)
	{
		if (P2Controller == 0 || (P2Controller == 1 && game_->getP1Controller() != 2))
		{
			game_->setP2Controller((P2Controller + 1));
		}
		else
		{
			game_->setP2Controller(0);
		}
		P2Controller = game_->getP2Controller();

	}
	else
	{
		if (P2Controller == 1 || P2Controller == 2)
		{
			game_->setP2Controller((P2Controller - 1));
		}
		else if (P2Controller == 0)
		{
			if (game_->getP1Controller() != 2)
				game_->setP2Controller(2);
			else
				game_->setP2Controller(1);
		}
		P2Controller = game_->getP2Controller();
	}
	updateTxt();
	level->changeControls();
}

void PauseMenu::updateTxt()
{
	musicTxt->setText(to_string(game_->getMusicVolume()), SDL_Color{ 0, 0, 0, 255 });
	musicTxt->setPosition(musicSelect->getPosition() + Vector2D(musicSelect->getWidth() / 2, musicSelect->getHeight() / 2) - Vector2D(musicTxt->getWidth() / 2, musicTxt->getHeight() / 2));

	soundTxt->setText(to_string(game_->getSoundVolume()), SDL_Color{ 0, 0, 0, 255 });
	soundTxt->setPosition(soundsSelect->getPosition() + Vector2D(soundsSelect->getWidth() / 2, soundsSelect->getHeight() / 2) - Vector2D(soundTxt->getWidth() / 2, soundTxt->getHeight() / 2));

	switch (P1Controller)
	{
	case 0:
		controlTxt->setText("Xbox", SDL_Color{ 0, 0, 0, 255 });
		break;
	case 1:
		controlTxt->setText("PS4", SDL_Color{ 0, 0, 0, 255 });
		break;
	case 2:
		controlTxt->setText("Teclado", SDL_Color{ 0, 0, 0, 255 });
		break;
	default:
		game_->setP1Controller(0);
		P1Controller = game_->getP1Controller();
		controlTxt->setText("Xbox", SDL_Color{ 0, 0, 0, 255 });
		break;
	}

	controlTxt->setPosition(controlsSelect->getPosition() + Vector2D(controlsSelect->getWidth() / 2, controlsSelect->getHeight() / 2) - Vector2D(controlTxt->getWidth() / 2, controlTxt->getHeight() / 2));

	switch (P2Controller)
	{
	case 0:
		control2Txt->setText("Xbox", SDL_Color{ 0, 0, 0, 255 });
		break;
	case 1:
		control2Txt->setText("PS4", SDL_Color{ 0, 0, 0, 255 });
		break;
	case 2:
		control2Txt->setText("Teclado", SDL_Color{ 0, 0, 0, 255 });
		break;
	default:
		game_->setP2Controller(0);
		P2Controller = game_->getP2Controller();
		control2Txt->setText("Xbox", SDL_Color{ 0, 0, 0, 255 });
		break;
	}

	control2Txt->setPosition(controlsSelect2->getPosition() + Vector2D(controlsSelect2->getWidth() / 2, controlsSelect2->getHeight() / 2) - Vector2D(control2Txt->getWidth() / 2, control2Txt->getHeight() / 2));

	level->updateOptionsFile();
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
		control2Txt->render(time);
	}
}