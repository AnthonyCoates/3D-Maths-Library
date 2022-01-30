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
};