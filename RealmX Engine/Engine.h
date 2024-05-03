#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine
{
public:
	static Engine* GetInstance()
	{
		if (s_Instance == nullptr)
			s_Instance = new Engine();
		return s_Instance;
	}

	bool Init();

	void Update();
	void Render();
	void Events();

	bool Clean();
	void Quit();

	inline bool IsRunning() { return m_IsRunning; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }

private:
	static Engine* s_Instance;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	bool m_IsRunning;
	
	Engine() {}
};
