#include "pch.h"
#include <utility>
#include <limits.h>
#include "ThreeDMathsLibrary.h"

// Standard mathematical functions
#pragma region StandardFunctions
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
		for (size_t i = 2; i < exp; i++)
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
	const float rateDegreeRadian = 0.0174533; // This is the conqersion rate between degrees and radians (pi/180)
	float cos = 1.0f;

	c *= rateDegreeRadian; // Need to conqert degrees to radians for the below formula to work

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
	const float rateDegreeRadian = 0.0174533; // This is the conqersion rate between degrees and radians (pi/180)

	s *= rateDegreeRadian; // Need to conqert degrees to radians for the below formula to work

	float sin = s;

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
#pragma endregion StandardFunctions

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

	// Operator Oqerloads - Vector3
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

	bool operator!=(const Vector3& v)
	{
		if (x == v.x && y == v.y && z == v.z)
		{
			return false;
		}

		return true;
	}

	// Operator Oqerloads - Float
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

	float Dot(Vector3 v) // Returns the dot product of two Vectors
	{
		Vector3 v1N = Normalise();
		Vector3 v2N = v.Normalise();

		return (v1N.x * v2N.x) + (v1N.y * v2N.y) + (v1N.z * v2N.z);
	}

	Vector3 Cross(Vector3 v) // Returns the cross product of two Vectors
	{
		float xC = (y * v.z) - (z * v.y);
		float yC = (z * v.x) - (x * v.z);
		float zC = (x * v.y) - (y * v.x);

		return Vector3{ xC, yC, zC };
	}

	float Angle(Vector3 v) // Returns the angle between this Vector and another
	{
		float dot = Dot(v);

		return ArcCos(dot);
	}
};

struct Quaternion
{
	float x{};
	float y{};
	float z{};
	float w{};

	// Constructors
	Quaternion()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
	}

	Quaternion(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Quaternion(Vector3 v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = 1.0f;
	}

	Quaternion(Vector3 v, float w)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		this->w = w;
	}

	// Operator Oqerloads - Quaternion
	Quaternion operator*(const Quaternion& q)
	{
		float xM = (w * q.x) + (x * q.w) + (y * q.z) - (z * q.y);
		float yM = (w * q.y) - (x * q.z) + (y * q.w) + (z * q.x);
		float zM = (w * q.z) + (x * q.y) - (y * q.x) + (z * q.w);
		float wM = (w * q.w) - (x * q.x) - (y * q.y) - (z * q.z);

		return Quaternion(xM, yM, zM, wM);
	}

	Quaternion operator/(const Quaternion& q)
	{
		float xD = ((w * q.x) - (x * q.w) - (y * q.z) + (z * q.y)) / (Power(q.w, 2) + Power(q.x, 2) + Power(q.y, 2) + Power(q.z, 2));
		float yD = ((w * q.y) + (x * q.z) - (y * q.w) - (z * q.x)) / (Power(q.w, 2) + Power(q.x, 2) + Power(q.y, 2) + Power(q.z, 2));
		float zD = ((w * q.z) - (x * q.y) + (y * q.x) - (z * q.w)) / (Power(q.w, 2) + Power(q.x, 2) + Power(q.y, 2) + Power(q.z, 2));
		float wD = ((w * q.w) + (x * q.x) + (y * q.y) + (z * q.z)) / (Power(q.w, 2) + Power(q.x, 2) + Power(q.y, 2) + Power(q.z, 2));

		return Quaternion(xD, yD, zD, wD);
	}

	bool operator==(const Quaternion& q)
	{
		if (x == q.x && y == q.y && z == q.z && w == q.w)
		{
			return true;
		}

		return false;
	}

	bool operator!=(const Quaternion& q)
	{
		if (x == q.x && y == q.y && z == q.z && w == q.w)
		{
			return false;
		}

		return true;
	}

	// Operator Oqerloads - Float
	Quaternion operator+(const float& f)
	{
		return Quaternion(x + f, y + f, z + f, w + f);
	}

	Quaternion operator-(const float& f)
	{
		return Quaternion(x - f, y - f, z - f, w - f);
	}

	Quaternion operator*(const float& f)
	{
		return Quaternion(x * f, y * f, z * f, w * f);
	}

	Quaternion operator/(const float& f)
	{
		return Quaternion(x / f, y / f, z / f, w / f);
	}

	// Quaterion methods
	Quaternion Identity()
	{
		return Quaternion();
	}

	float Magnitude()
	{
		float x2 = Power(x, 2);
		float y2 = Power(y, 2);
		float z2 = Power(z, 2);
		float w2 = Power(w, 2);

		return HeronSqrt(x2 + y2 + z2 + w2);
	}

	Quaternion Normalise()
	{
		return Quaternion{ x, y, z, w } / Magnitude();
	}

	Quaternion Conjugate()
	{
		return Quaternion(-x, -y, -z, w);
	}

	Quaternion Inverse()
	{
		return Quaternion(Normalise()).Conjugate();
	}

	float Dot(Quaternion q)
	{
		return x * q.x + y * q.y + z * q.z + w * q.w;
	}

	float Angle(Quaternion q)
	{
		return ArcCos(Dot(q));
	}

	Quaternion Relative(Quaternion q)
	{
		return Inverse() * q.Normalise();
	}
};