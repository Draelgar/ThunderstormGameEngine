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
			union 
			{
				struct 
				{
					float mX;
					float mY;
				};

				float mVector[2];
			};

		public:
			/** Default Constructor.All values are set to zero. **/
			Float2() { mX = 0.0f; mY = 0.0f; };
			/** Create a new vector with all values set to the same. **/
			explicit Float2(float value) { mX = value; mY = value; };
			/** Create a new vector with the given data. **/
			explicit Float2(float x, float y) { mX = x; mY = y; };

			/** Get the i'th element. **/
			inline float operator[](const unsigned short index) const { return mVector[index]; };
			/** Set the i'th element to the given value. **/
			inline void set(const unsigned short index, const float value) { mVector[index] = value; };
			/** Set both components to the given value. **/
			inline void set(const float value) { mX = value; mY = value; };

			/** Get the X-coordinate. **/
			inline float X() const { return mX; };
			/** Set the X-coordinate. **/
			inline void X(const float value) { mX = value; };

			/** Get the Y-coordinate. **/
			inline float Y() const { return mY; };
			/** Set the Y-coordinate. **/
			inline void Y(const float value) { mY = value; };

			/** Get the length of this vector. **/
			inline float Length() const { return sqrtf(powf(mX, 2.0f) + powf(mY, 2.0f)); };

			/** Multiply vector by scalar. **/
			inline void operator*=(const float scalar) { mX *= scalar; mY *= scalar; };
			/** Multiply vector by scalar. **/
			inline Float2 operator*(const float scalar) const { Float2 result((*this)); result *= scalar; return result; };
			/** Multiply vector by scalar. **/
			inline friend Float2 operator*(const float scalar, const Float2 vector) { return vector * scalar; };

			/** Divide vector by scalar. **/
			inline void operator/=(const float scalar) { mX /= scalar; mY /= scalar; };
			/** Divide vector by scalar. **/
			inline Float2 operator/(const float scalar) const { Float2 result((*this)); result /= scalar; return result; };

			/** Compare two vectors. **/
			inline bool operator==(const Float2 vector) const { if (mX == vector.X() && mY == vector.Y()) return true; };
			/** Compare two vectors. **/
			inline bool operator!=(const Float2 vector) const { return !((*this) == vector); };

			/** Add two vectors together.**/
			inline void operator+=(const Float2 vector) { mX += vector.X(); mY += vector.Y(); };
			/** Add two vectors together.**/
			inline Float2 operator+(const Float2 vector) const { Float2 result(*this); result += vector; return result; };

			/** Subtract a vector from another. **/
			inline void operator-=(const Float2 vector) { mX -= vector.X(); mY -= vector.Y(); };
			/** Subtract a vector from another. **/
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

			/** Calculate the Dot product of two vectors. **/
			inline float Dot(Float2 vector) const { return (mX * vector.X()) + (mY * vector.Y()); };

			// Cross product for a 2D vector is redundant, as it will always return zero.
		};
	}
}