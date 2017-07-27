/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-03-30
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include<math.h>

namespace ts
{
	namespace math
	{
		class Float2
		{
		protected:
			/** The actual data. **/
			float mVector[2];

		public:
			/** Default Constructor.All values are set to zero. **/
			Float2() { mVector[0] = 0.0f; mVector[1] = 0.0f; };
			/** Create a new vector with all values set to the same. **/
			explicit Float2(float value) { mVector[0] = value; mVector[1] = value; };
			/** Create a new vector with the given data. **/
			explicit Float2(float x, float y) { mVector[0] = x; mVector[1] = y; };

			/** Get the i'th element. **/
			inline float operator[](const unsigned short index) const { return mVector[index]; };
			/** Set the i'th element to the given value. **/
			inline float set(const unsigned short index, const float value) { mVector[index] = value; };

			/** Get the X-coordinate. **/
			inline float X() const { return mVector[0]; };
			/** Set the X-coordinate. **/
			inline void X(const float value) { mVector[0] = value; };

			/** Get the Y-coordinate. **/
			inline float Y() const { return mVector[1]; };
			/** Set the Y-coordinate. **/
			inline void Y(const float value) { mVector[1] = value; };

			/** Get the length of this vector. **/
			inline float Length() const { return sqrtf(powf(mVector[0], 2.0f) + powf(mVector[1], 2.0f)); };

			inline void operator*=(const float scalar) { mVector[0] *= scalar; mVector[1] *= scalar; };
			inline Float2 operator*(const float scalar) const { Float2 result((*this)); result *= scalar; return result; };

			inline void operator/=(const float scalar) { mVector[0] /= scalar; mVector[1] /= scalar; };
			inline Float2 operator/(const float scalar) const { Float2 result((*this)); result /= scalar; return result; };

			inline bool operator==(const Float2 vector) const { if (mVector[0] == vector.X() && mVector[1] == vector.Y()) return true; };
			inline bool operator!=(const Float2 vector) const { return !((*this) == vector); };

			inline void operator+=(const Float2 vector) { mVector[0] += vector.X(); mVector[1] += vector.Y(); };
			inline Float2 operator+(const Float2 vector) const { Float2 result(*this); result += vector; return result; };

			inline void operator-=(const Float2 vector) { mVector[0] -= vector.X(); mVector[1] -= vector.Y(); };
			inline Float2 operator-(const Float2 vector) const { Float2 result(*this); result -= vector; return result; };

			/** Normalize the vector and return its former length. **/
			inline float Normalize()
			{
				float length = Length();
				(*this) /= length;
				return length;
			};

			/** Get a normalized version of this vector. **/
			inline Float2 Normalized() const { Float2 unitVector(*this); unitVector.Normalize(); return unitVector; };

			inline float Dot(Float2 vector) const { return (mVector[0] * vector.X()) + (mVector[1] * vector.Y()); };
		};
	}
}