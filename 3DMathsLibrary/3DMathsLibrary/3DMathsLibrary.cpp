#include "pch.h"
#include <utility>
#include <limits.h>

struct Vector3
{
	float x{};
	float y{};
	float z{};

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
};