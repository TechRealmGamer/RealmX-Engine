#include <iostream>

class Vector2D
{
public:
	// vector components
	float X, Y;

	// constructor
	Vector2D(float x = 0, float y = 0) : X(x), Y(y) {}
	
	// add two vectors
	inline Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(X + v2.X, Y + v2.Y);
	}

	// subtract two vectors
	inline Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(X - v2.X, Y - v2.Y);
	}

	// multiply vector by scalar
	inline Vector2D operator*(float scalar) const
	{
		return Vector2D(X * scalar, Y * scalar);
	}

	// divide vector by scalar
	inline Vector2D operator/(float scalar) const
	{
		return Vector2D(X / scalar, Y / scalar);
	}

	// log vector
	void Log(std::string mag = "")
	{
		std::cout << mag << "(X, Y) = (" << X << ", " << Y << ")" << std::endl;
	}

};

