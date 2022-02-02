#include "pch.h"
#include <utility>
#include <limits.h>
#include "ThreeDMathsLibrary.h"

// Standard mathematical functions
float HeronSqrt(float s) // This estimates the square root of a float without the need for any external libraries, using the Heron method
{
	float e = s / 2;

	for (size_t i = 0; i < 10; i++)
	{
		e = (e + s / e) * 0.5f;
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

float Absolute(float a) // This is a simple absolute function without the need for any external libraries
{
	if (a < 0.0f)
	{
		return -a;
	}

	return a;
}

float Cos(float c) // This is a simple cosine function without the need for any external libraries
{
	const float rateDegreeRadian = 0.0174533; // This is the conversion rate between degrees and radians (pi/180)
	float cos = 1.0f;

	c *= rateDegreeRadian; // Need to convert degrees to radians for the below formula to work

	for (size_t i = 1; i < 11; i++)
	{
		float x = (Power(c, i * 2) / Factorial(i * 2));

		if (i % 2 > 0)
		{
			cos -= x;
		}
		else
		{
			cos += x;
		}
	}

	return cos;
}

float Sin(float s) // This is a simple sine function without the need for any external libraries
{
	const float rateDegreeRadian = 0.0174533; // This is the conversion rate between degrees and radians (pi/180)
	float sin = 1.0f;

	s *= rateDegreeRadian; // Need to convert degrees to radians for the below formula to work

	for (size_t i = 1; i < 11; i++)
	{
		float x = (Power(s, (i * 2) + 1) / Factorial((i * 2) + 1));

		if (i % 2 > 0)
		{
			sin -= x;
		}
		else
		{
			sin += x;
		}
	}

	return sin;
}

float ArcCos(float a) // This is a simple sine function without using Newton's method
{
	float delta = 1e-5f;
	float pi = 3.14f;

	float x = pi * (1 - a) / 2;
	float last = x;

	x += Cos(x - a) / Sin(x);

	while (Absolute(x - last) > delta)
	{
		last = x;
		x += (Cos(x - a) / Sin(x));
	}

	return x;
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

	bool operator==(const Vector3& v)
	{
		if (x == v.x && y == v.y && z == v.z)
		{
			return true;
		}

		return false;
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
		float x2 = Power(x, 2);
		float y2 = Power(y, 2);
		float z2 = Power(z, 2);

		return HeronSqrt(x2 + y2 + z2);
	}

	Vector3 Normalise()
	{
		return Vector3{x, y, z} / Magnitude();
	}

	float Distance(Vector3 v)
	{
		float x2 = Power(x - v.x, 2);
		float y2 = Power(y - v.y, 2);
		float z2 = Power(z - v.z, 2);
		
		return HeronSqrt(x2 + y2 + z2);
	}

	float Dot(Vector3 v) // Returns the dot product of two vectors
	{
		Vector3 v1N = Normalise();
		Vector3 v2N = v.Normalise();

		return (v1N.x * v2N.x) + (v1N.y * v2N.y) + (v1N.z * v2N.z);
	}

	Vector3 Cross(Vector3 v) // Returns the cross product of two vectors
	{
		float xC = (y * v.z) - (z * v.y);
		float yC = (z * v.x) - (x * v.z);
		float zC = (x * v.y) - (y * v.x);

		return Vector3{ xC, yC, zC };
	}

	float Angle(Vector3 v) // Returns the angle between this vector and another
	{
		float dot = Dot(v);

		return ArcCos(dot);
	}
};