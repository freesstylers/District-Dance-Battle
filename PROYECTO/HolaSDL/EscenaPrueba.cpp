#include "EscenaPrueba.h"
#include <iostream>
EscenaPrueba::EscenaPrueba()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Practica1", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//Si no se ha podido crear la ventana o el renderer, lanza una excepción
	if (window == nullptr || renderer == nullptr)
		throw "Error al cargar pantalla";
	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		try {
			textures[i] = new Texture(renderer, IMAGES_PATH + TEXTURE_ATRIBUTES[i].name, TEXTURE_ATRIBUTES[i].row, TEXTURE_ATRIBUTES[i].col);
		}
		catch (string e) {
			throw "Error al cargar texturas";
		}
	}

	timer = Timer::Instance();
	Vector2D pos(900, 350);
	Flechas* flecha1 = new Flechas(pos, textures[FlechaText], 115, 100, 100);
	lista.push_back(flecha1);
	Vector2D pos2(200, 320);
	Flechas* point = new Flechas(pos2, textures[PointText], 0, 150, 150);
	otros.push_back(point);
}

void EscenaPrueba::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT)
			exit = true;
		else
		{
			if (!lista.empty())
			{
				auto it = lista.front();
				if (it != nullptr)
				{
					if (event.type == SDL_KEYUP && event.key.keysym.sym == (it)->getKey())
					{
						if (abs(it->getPos().CompX() - otros.front()->getPos().CompX()) <= 100)
						{
							cout << "bien";
						}
						else
						{
							cout << "mal";
						}
						delete (it);
						lista.remove(it);
					}
					else if (event.type == SDL_KEYUP)
					{
						cout << "mal";
						delete (it);
						lista.remove(it);
					}
				}
			}
		}
	}
}

void EscenaPrueba::render()
{
	SDL_RenderClear(renderer);
	otros.front()->render();
	for (auto it = lista.begin(); it != lista.end(); it++)
	{
		(*it)->render();
	}
	SDL_RenderPresent(renderer);
}

void EscenaPrueba::update()
{
	for (auto it = lista.begin(); it != lista.end(); it++)
	{
		(*it)->update();
	}
}
void EscenaPrueba::generate()
{
		Vector2D pos(900, 350);
		Flechas* flecha1 = new Flechas(pos, textures[FlechaText], 115, 100, 100);
		lista.push_back(flecha1);
}
void EscenaPrueba::run()
{
	uint32_t startTime, frameTime = 0;
	startTime = SDL_GetTicks();
	while (!exit)
	{
		timer->Update();
		frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
		if (frameTime >= FRAME_RATE) {
			update();
			handleEvents();
			startTime = SDL_GetTicks();
		}
		if (timer->DeltaTime() > 2.0f)
		{
			generate();
			timer->Reset();
		}
		render();
	}
}
EscenaPrueba::~EscenaPrueba()
{
	for (auto it = lista.begin(); it != lista.end(); it++)
	{
		delete (*it);
	}
	for (auto it = otros.begin(); it != otros.end(); it++)
	{
		delete(*it);
	}
	for (int i = 0; i < NUM_TEXTURES; i++) {
		delete textures[i];
	}
}
