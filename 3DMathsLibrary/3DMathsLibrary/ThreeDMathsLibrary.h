#pragma once

#ifdef THREEDMATHSLIBRARY_EXPORTS
#define THREEDMATHSLIBRARY_API __declspec(dllexport)
#else
#define THREEDMATHSLIBRARY_API __declspec(dllimport)
#endif

extern "C" THREEDMATHSLIBRARY_API float HeronSqrt(float s);

extern "C" THREEDMATHSLIBRARY_API float Power(float n, int exp);

extern "C" THREEDMATHSLIBRARY_API int Factorial(int f);

extern "C" THREEDMATHSLIBRARY_API float Absolute(float a);

extern "C" THREEDMATHSLIBRARY_API float Cos(float c);

extern "C" THREEDMATHSLIBRARY_API float Sin(float s);

extern "C" THREEDMATHSLIBRARY_API float ArcCos(float a);

extern "C" THREEDMATHSLIBRARY_API struct Vector3
								{
									float x;
									float y;
									float z;

									Vector3();

									Vector3(float x, float y, float z);

									float Magnitude();

									Vector3 Normalise();

									float Distance(Vector3 v);

									float Dot(Vector3 v);

									Vector3 Cross(Vector3 v);

									float Angle(Vector3 v);
								};