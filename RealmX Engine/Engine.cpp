#include "Engine.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Transform.h"

 Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
	{
		SDL_Log("Error initializing SDL: %s", SDL_GetError());
		return false;
	}

	m_Window = SDL_CreateWindow("RealmX Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_Window == nullptr)
	{
		SDL_Log("Error creating window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr)
	{
		SDL_Log("Error creating renderer: %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->Load("tree", "assets/tree.png");

	return m_IsRunning = true;
}

void Engine::Update()
{
	// Update game logic here
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 50, 80, 125, 255);
	SDL_RenderClear(m_Renderer);
	TextureManager::GetInstance()->Draw("tree", 100, 100, 400, 643);
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;
	default:
		break;
	}
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	return false;
}

void Engine::Quit()
{
	m_IsRunning = false;
}
