#include "Engine.h"
#include <iostream>

 Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	m_IsRunning = true;
	return true;
}

void Engine::Update()
{
	std::cout << "Update" << std::endl;
}

void Engine::Render()
{
}

void Engine::Events()
{
}

bool Engine::Clean()
{
	return false;
}

void Engine::Quit()
{
}
