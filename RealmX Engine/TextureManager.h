#include <string>
#include "SDL.h"
#include <map>

class TextureManager
{
public:
	static TextureManager* GetInstance()
	{
		if (s_Instance == nullptr)
			s_Instance = new TextureManager();
		return s_Instance;
	}

	bool Load(std::string id, std::string fileName);
	void Drop(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	static TextureManager* s_Instance;

	std::map<std::string, SDL_Texture*> m_TextureMap;

	TextureManager() {}
};

