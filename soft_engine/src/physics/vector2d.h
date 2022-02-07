#pragma once

#include <iostream>

class Vector2D
{

public:
	float X;
	float Y;

public:
	//Vector2D() : X{ 0.0 }, Y{ 0.0 } {};
	Vector2D(float a_x=0, float a_y=0) : X{ a_x }, Y{ a_y } {}

	inline Vector2D operator+(const Vector2D& rhs) const
	{
		return Vector2D(X + rhs.X, Y + rhs.Y );
	}

	inline Vector2D operator-(const Vector2D& rhs) const
	{
		return Vector2D(X - rhs.X, Y - rhs.Y);
	}

	inline Vector2D operator*(const float a_scalar) const
	{
		return Vector2D(X * a_scalar, Y * a_scalar);
	}

	void Log(std::string msg = "")
	{
		std::cout << msg;
		std::cout << "(" << X << ", " << Y << ")" << std::endl;
	}
private:



};
