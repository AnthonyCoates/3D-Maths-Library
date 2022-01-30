#include "pch.h"
#include <utility>
#include <limits.h>

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

	// Standard mathematical functions
	float HeronSqrt(float s) // This estimates the square root of a float without the need for any external libraries, using the Heron method
	{
		float e = s/2;

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

	// Standard 3D Vector maths functions
	float Distance(Vector3 v1, Vector3 v2)
	{
		float xP = Power(v1.x - v2.x, 2);
		float yP = Power(v1.y - v2.y, 2);
		float zP = Power(v1.z - v2.z, 2);
		
		return HeronSqrt(xP + yP + zP);
	}


};