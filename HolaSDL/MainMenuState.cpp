#include "MainMenuState.h"
#include "Creditos.h"
#include <stdio.h>


MainMenuState::MainMenuState(GameManager*g):GameState(g)
{
	gameManager = g;
	isXbox = gameManager->getController();
	gameManager->setController(isXbox);
	buttons.reserve (10);
	selectButton.reserve (5);
	controller = SDL_GameControllerOpen(0);
	

	EmptyObject* fondo = new EmptyObject(g, Vector2D(0, 0), gameManager->getDefaultWindowWidth(), gameManager->getDefaultWindowHeight(), Resources::MainMenu);
	EmptyObject* chargeGame1 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+85, gameManager->getDefaultWindowHeight() / 2 -395), 600, 190, Resources::ChargeGameNoSelected);
	EmptyObject* chargeGame2 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+85, gameManager->getDefaultWindowHeight() / 2 -395), 600, 190, Resources::ChargeGameSelected);
	EmptyObject* newGame1 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+70 , gameManager->getDefaultWindowHeight() /2-270), 600, 190, Resources::NewGameNoSelected);
	EmptyObject* newGame2 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2 +70, gameManager->getDefaultWindowHeight() / 2-270), 600, 190, Resources::NewGameSelected);
	EmptyObject* options1 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+100, gameManager->getDefaultWindowHeight() / 2 -120), 600, 190, Resources::OptionsNoSelected);
	EmptyObject* options2 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+100, gameManager->getDefaultWindowHeight() / 2-120 ), 600, 190, Resources::OptionsSelected);
	EmptyObject* credits1 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+60, gameManager->getDefaultWindowHeight() / 2+15 ), 600, 190, Resources::CreditsNoSelected);
	EmptyObject* credits2 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+60, gameManager->getDefaultWindowHeight() / 2+15 ), 600, 190, Resources::CreditsSelected);
	EmptyObject* exit1 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+200, gameManager->getDefaultWindowHeight() / 2 + 165), 600, 190, Resources::ExitNoSelected);
	EmptyObject* exit2 = new EmptyObject(g, Vector2D(gameManager->getDefaultWindowWidth() / 2+200, gameManager->getDefaultWindowHeight() / 2 + 165), 600, 190, Resources::ExitSelected);
	
	buttons.push_back(chargeGame1);
	buttons.push_back(chargeGame2);
	buttons.push_back(newGame1);
	buttons.push_back(newGame2);
	buttons.push_back(options1);
	buttons.push_back(options2);
	buttons.push_back(credits1);
	buttons.push_back(credits2);
	buttons.push_back(exit1);
	buttons.push_back(exit2);
	
	bool b1= true;
	bool b2 = false;
	bool b3 = false;
	bool b4 = false;
	bool b5 = false;

	selectButton.push_back(b1);
	selectButton.push_back(b2);
	selectButton.push_back(b3);
	selectButton.push_back(b4);
	selectButton.push_back(b5);

	//buttons[0]->scale(2);
	stage.push_back(fondo);


	double menuX = gameManager->getDefaultWindowWidth() / 3;
	double menuY = gameManager->getDefaultWindowHeight() / 6;
	double menuW = gameManager->getDefaultWindowWidth() / 3;
	double menuH = gameManager->getDefaultWindowHeight() * 2 / 3;


	double buttonConst = menuH / 8 - 50;

	op_bg = new EmptyObject(gameManager, Vector2D(menuX, menuY), menuW, menuH, Resources::MenuBG);

	music = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 0.1 + buttonConst), menuW / 2, 45, Resources::ButtonMusic);
	music->scale(0.8);
	musicSelect = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 0.1 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	sounds = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 0.295 + buttonConst), menuW / 2, 45, Resources::ButtonSound);
	sounds->scale(0.8);
	soundsSelect = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 0.295 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	controls = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 0.49 + buttonConst), menuW / 2, 45, Resources::ButtonControls);
	controls->scale(0.8);
	controlsSelect = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 0.49 + buttonConst + 45), menuW / 2, 45, Resources::ButtonVol);

	op_exit = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 0.685 + buttonConst + 25), menuW / 2, 45, Resources::ButtonExit);

	musicTxt = new TextObject(gameManager, gameManager->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	soundTxt = new TextObject(gameManager, gameManager->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));
	controlTxt = new TextObject(gameManager, gameManager->getServiceLocator()->getFonts()->getFont(Resources::RETRO30), Vector2D(0, 0));

	updateTxt();

	optionsButtons.push_back(musicSelect);
	optionsButtons.push_back(soundsSelect);
	optionsButtons.push_back(controlsSelect);
	optionsButtons.push_back(op_exit);
	optionsButtons.push_back(music);
	optionsButtons.push_back(sounds);
	optionsButtons.push_back(controls);
	selection = new EmptyObject(gameManager, Vector2D(menuX + menuX / 4, menuY + menuH * 2 / 3), menuW / 2, 45, Resources::ButtonSelection);

	g->getServiceLocator()->getAudios()->setChannelVolume(60, 1);
	g->getServiceLocator()->getAudios()->setChannelVolume(40, 0);

	manager->getServiceLocator()->getAudios()->resumeChanne(0);
	manager->getServiceLocator()->getAudios()->playChannel(Resources::MainTheme, 1, 0);
	
}


MainMenuState::~MainMenuState()
{
	for (int i = 0; i < 10; i++)
	{
		delete buttons[i];
		buttons[i] = nullptr;
	}

	delete op_bg;
	delete music;
	delete musicSelect;
	delete sounds;
	delete soundsSelect;
	delete controls;
	delete controlsSelect;
	delete op_exit;

	delete selection;

	delete musicTxt;
	delete soundTxt;
	delete controlTxt;

	optionsButtons.clear();
}

void MainMenuState::render(Uint32 time, bool beatHandler)
{
	GameState::render(time);
	for (int i = 0;i < 5;i++)
	{
		if (selectButton[i] == true)
		{
			buttons[2 * i + 1]->render(time);
		}
		else {
			buttons[2*i]->render(time);
		}
	}
	if (optionsOpen) 
	{
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

void MainMenuState::options()
{
	optionsOpen = !op_bg->isActive();

	op_bg->setActive(optionsOpen);

	for (EmptyObject* g : optionsButtons)
		g->setActive(optionsOpen);

	musicTxt->setActive(optionsOpen);
	soundTxt->setActive(optionsOpen);
	controlTxt->setActive(optionsOpen);


	if (optionsOpen) {
		selectedButton = 0;
		selection->setPosition(optionsButtons[selectedButton]->getPosition());
		selection->forceAnimationChange(Resources::VolSelection);
	}
	gameManager->mainmenu = true;

}

void MainMenuState:: updateMusic(bool raise)
{
	if (raise && gameManager->getMusicVolume() < 100) {
		gameManager->setMusicVolume(gameManager->getMusicVolume() + 5);
	}
	else if (!raise && gameManager->getMusicVolume() > 0) {
		gameManager->setMusicVolume(gameManager->getMusicVolume() - 5);
	}


	gameManager->getServiceLocator()->getAudios()->setChannelVolume(gameManager->getMusicVolume(), 0);
	gameManager->getServiceLocator()->getAudios()->setChannelVolume(gameManager->getMusicVolume(), 2);
	gameManager->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 2);

	updateTxt();
}

void MainMenuState::updateSound(bool raise)
{
	if (raise && gameManager->getSoundVolume() < 100) {
		gameManager->setSoundVolume(gameManager->getSoundVolume() + 5);
	}
	else if (!raise && gameManager->getSoundVolume() > 0) {
		gameManager->setSoundVolume(gameManager->getSoundVolume() - 5);
	}

	gameManager->getServiceLocator()->getAudios()->setChannelVolume(gameManager->getSoundVolume(), 1);
	gameManager->getServiceLocator()->getAudios()->playChannel(Resources::Snare, 0, 1);

	updateTxt();
}

void MainMenuState::updateControls()
{
	isXbox = !manager->getController();
	manager->setController(isXbox);
	updateTxt();
}

void MainMenuState::updateTxt()
{
	musicTxt->setText(to_string(gameManager->getMusicVolume()), SDL_Color{ 0, 0, 0, 255 });
	musicTxt->setPosition(musicSelect->getPosition() + Vector2D(musicSelect->getWidth() / 2, musicSelect->getHeight() / 2) - Vector2D(musicTxt->getWidth() / 2, musicTxt->getHeight() / 2));

	soundTxt->setText(to_string(gameManager->getSoundVolume()), SDL_Color{ 0, 0, 0, 255 });
	soundTxt->setPosition(soundsSelect->getPosition() + Vector2D(soundsSelect->getWidth() / 2, soundsSelect->getHeight() / 2) - Vector2D(soundTxt->getWidth() / 2, soundTxt->getHeight() / 2));

	if (isXbox)
		controlTxt->setText("Xbox", SDL_Color{ 0, 0, 0, 255 });
	else
		controlTxt->setText("PS4", SDL_Color{ 0, 0, 0, 255 });

	controlTxt->setPosition(controlsSelect->getPosition() + Vector2D(controlsSelect->getWidth() / 2, controlsSelect->getHeight() / 2) - Vector2D(controlTxt->getWidth() / 2, controlTxt->getHeight() / 2));
}

void MainMenuState::nextButton() 
{
		if (optionsOpen == true)
		{
			if (selectedButton == 3)
				selectedButton = 0;
			else {
				selectedButton++;
			}
			selection->setPosition(optionsButtons[selectedButton]->getPosition());

			if (selectedButton == 3)
				selection->forceAnimationChange(Resources::ButtonSelection);
			else
				selection->forceAnimationChange(Resources::VolSelection);
		}
		else {
			//buttons[index]->scale(0.5);
			selectButton[index] = false;
			if (index < max)
			{
				index++;
			}
			else {
				index = min;
			}
			//buttons[index]->scale(2);
			selectButton[index] = true;
		}
}
void MainMenuState::backButton()
{
		if (optionsOpen)
		{
			if (selectedButton == 0)
				selectedButton = 3;
			else {
				selectedButton--;
			}
			selection->setPosition(optionsButtons[selectedButton]->getPosition());

			if (selectedButton == 3)
				selection->forceAnimationChange(Resources::ButtonSelection);
			else
				selection->forceAnimationChange(Resources::VolSelection);
		}
		else {
			//buttons[index]->scale(0.5);
			selectButton[index] = false;
			if (index > min)
			{
				index--;
			}
			else {
				index = max;
			}
			//buttons[index]->scale(2);
			selectButton[index] = true;
		}
}


void MainMenuState::newGame(GameManager* gameManager) 
{
	remove("resources/data/1.txt");
	remove("resources/data/2.txt");
	remove("resources/data/3.txt");
	remove("resources/data/4.txt");
	remove("resources/data/5.txt");
	gameManager->getMachine()->changeState(new MapState(gameManager));
}
void MainMenuState::exit(GameManager* gameManager)
{
	gameManager->exit_ = true;
}

bool MainMenuState::handleEvent(Uint32 time, SDL_Event e) 
{
	bool input = false;
	if (keyup)
	{
		if (SDL_CONTROLLERBUTTONDOWN &&SDL_CONTROLLERBUTTONUP || e.type == SDL_KEYDOWN)
		{
			if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_DOWN && e.type == SDL_KEYUP)
			{

				nextButton();

				input = true;
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_UP && e.type == SDL_KEYUP)
			{
				backButton();
				input = true;
			}
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_RIGHT && e.type == SDL_KEYUP)
			{
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
			else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_LEFT && e.type == SDL_KEYUP)
			{
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
			else if (selectButton[0] == true && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYUP))
			{
				manager->getServiceLocator()->getAudios()->haltChannel(0);
				gameManager->mainmenu = false;
				gameManager->getMachine()->changeState(new MapState(gameManager));
				input = true;
			}
			else if (selectButton[1] == true && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYUP))
			{
				manager->getServiceLocator()->getAudios()->haltChannel(0);
				gameManager->mainmenu = false;
				newGame(gameManager);
				input = true;
			}

			else if (selectButton[2] == true && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYUP))
			{
				gameManager->mainmenu = false;
				options();
				gameManager->mainmenu = true;

				input = true;
			}
			else if (selectButton[3] == true && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYUP))
			{
				gameManager->mainmenu = false;
				manager->getMachine()->changeState(new Creditos(gameManager));
				//gameManager->mainmenu = true;
				input = true;
			}
			else if (selectButton[4] == true && (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) && SDL_CONTROLLERBUTTONUP || e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYUP))
			{
				gameManager->mainmenu = false;
				exit(gameManager);
				input = true;
			}

			keyup = false;
		}
	}
	
	else if (e.type == SDL_CONTROLLERBUTTONUP) keyup = true; input = false;
	return input;
}


