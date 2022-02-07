#pragma once
#include "vector2d.h"

class Transform
{
public:
	float X, Y;

public:
	Transform(float a_x = 0, float a_y = 0) : X{ a_x }, Y{ a_y } {};
	inline void TranslateX(float a_x) { X += a_x; }
	inline void TranslateY(float a_y) { Y += a_y; }
	inline void Translate(const Vector2D a_vec) { X += a_vec.X; Y += a_vec.Y; }

	void Log(std::string msg = "")
	{
		std::cout << msg;
		std::cout << "(" << X << ", " << Y << ")" << std::endl;
	}
};