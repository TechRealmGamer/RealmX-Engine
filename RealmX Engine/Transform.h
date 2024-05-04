#include "Vector2D.h"

class Transform
{
public:

	Vector2D position;

	// constructor
	Transform(float x = 0, float y = 0) : position(x, y) {}

private:
	// position - setter and getter
	inline void SetPosition(float x, float y) { position.X = x; position.Y = y; }
	inline Vector2D GetPosition() { return position; }

	// translate
	inline void TranslateX(float x) { position.X += x; }
	inline void TranslateY(float y) { position.Y += y; }
	inline void Translate(float x, float y)	{ position.X += x; position.Y += y; }
	inline void Translate(Vector2D v) { position.X += v.X; position.Y += v.Y; }


	// log transform
	void Log(std::string mag = "")
	{
		std::cout << mag << "(X, Y) = (" << position.X << ", " << position.Y << ")" << std::endl;
	}
};
