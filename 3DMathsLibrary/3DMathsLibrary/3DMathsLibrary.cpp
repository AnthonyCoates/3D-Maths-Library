#include "pch.h"
#include <utility>
#include <limits.h>

// Standard mathematical functions
float HeronSqrt(float s) // This estimates the square root of a float without the need for any external libraries, using the Heron method
{
	float e = s / 2;

	for (size_t i = 0; i < 10; i++)
	{
		e = (e + s / e) * 0.5;
	}

	return e;
}

float Power(float n, int exp) // This is a simple power function without the need for any external libraries
{
	if (exp > 0)
	{
		for (size_t i = 0; i < exp; i++)
		{
			n *= n;
		}

		return n;
	}
	else if (exp < 0)
	{
		return 1 / Power(n, -exp);
	}

	return 1.0f;
}

int Factorial(int f) // This is a simple factorial function without the need for any external libraries
{
	if (f > 1)
	{
		return f * Factorial(f - 1);
	}

	return 1;
}

float Cos(float c) // This is a simple cosine function without the need for any external libraries
{
	const float rateDegreeRadian = 0.0174533; // This is the conversion rate between degrees and radians (pi/180)
	float cos = 1.0f;

	c *= rateDegreeRadian; // Need to convert degrees to radians for the below formula to work

	for (size_t i = 1; i < 11; i++)
	{
		if (i % 2 > 0)
		{
			cos -= (Power(c, i * 2) / Factorial(i * 2));
		}
		else
		{
			cos += (Power(c, i * 2) / Factorial(i * 2));
		}
	}

	return cos;
}

struct Vector3
{
	float x{};
	float y{};
	float z{};

	// Constructors
	Vector3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	// Operator Overloads - Vector3
	Vector3 operator+(const Vector3& v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(const Vector3& v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(const Vector3& v)
	{
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	Vector3 operator/(const Vector3& v)
	{
		return Vector3(x / v.x, y / v.y, z / v.z);
	}

	// Operator Overloads - Float
	Vector3 operator+(const float& f)
	{
		return Vector3(x + f, y + f, z + f);
	}

	Vector3 operator-(const float& f)
	{
		return Vector3(x - f, y - f, z - f);
	}

	Vector3 operator*(const float& f)
	{
		return Vector3(x * f, y * f, z * f);
	}

	Vector3 operator/(const float& f)
	{
		return Vector3(x / f, y / f, z / f);
	}

	// Standard 3D Vector maths functions
	float Magnitude()
	{
		float x2 = Power(this->x, 2);
		float y2 = Power(this->y, 2);
		float z2 = Power(this->z, 2);

		return HeronSqrt(x2 + y2 + z2);
	}

	float Distance(Vector3 v)
	{
		float x2 = Power(this->x - v.x, 2);
		float y2 = Power(this->y - v.y, 2);
		float z2 = Power(this->z - v.z, 2);
		
		return HeronSqrt(x2 + y2 + z2);
	}


};