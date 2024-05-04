#include <string>
#include "IObject.h"
#include "Transform.h"
#include "SDL.h"

struct Properties
{
public:
	Vector2D Position;
	int Width, Height;
	std::string TextureID;
	SDL_RendererFlip Flip;

	Properties(float x, float y, int width, int height, std::string textureID, SDL_RendererFlip flip = SDL_FLIP_NONE)
	{
		Position = Vector2D(x, y);
		Width = width;
		Height = height;
		TextureID = textureID;
		Flip = flip;
	}
};

class GameObject : public IObject
{
public:
	GameObject(Properties* props)
	{
		m_Transform = new Transform(props->Position);
		m_Width = props->Width;
		m_Height = props->Height;
		m_TextureID = props->TextureID;
		m_Flip = props->Flip;
	}

	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;

protected:
	Transform* m_Transform;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};
