/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-03-30
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include "Float2.h"

namespace ts 
{
	namespace math
	{
		class Float3
		{
		protected:
			/** The actual data. **/
			float mVector[3];

		public:
			/** Default Constructor.All values are set to zero. **/
			Float3() { mVector[0] = 0.0f; mVector[1] = 0.0f; mVector[2] = 0.0f; };
			/** Create a new vector with all values set to the same. **/
			explicit Float3(float value) { mVector[0] = value; mVector[1] = value; mVector[2] = value; };
			/** Create a new vector with the given data. **/
			explicit Float3(float x, float y, float z) { mVector[0] = x; mVector[1] = y; mVector[2] = z; };
			/** Create a new vector with the given data. **/
			explicit Float3(Float2 vector, float z) { mVector[0] = vector.X(); mVector[1] = vector.Y(); mVector[2] = z; };


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

			/** Get the Z-coordinate. **/
			inline float Z() const { return mVector[2]; };
			/** Set the Z-coordinate. **/
			inline void Z(const float value) { mVector[2] = value; };

			inline Float2 XY() const { return Float2(mVector[0], mVector[1]); };
			inline Float2 YZ() const { return Float2(mVector[1], mVector[2]); };
			inline Float2 XZ() const { return Float2(mVector[0], mVector[2]); };

			/** Get the length of this vector. **/
			inline float Length() const { return sqrtf(powf(mVector[0], 2.0f) + powf(mVector[1], 2.0f) + powf(mVector[2], 2.0f)); };

			inline void operator*=(const float scalar)
			{
				mVector[0] *= scalar;
				mVector[1] *= scalar;
				mVector[2] *= scalar;
			};
			inline Float3 operator*(const float scalar) const
			{
				Float3 result((*this));
				result *= scalar;
				return result;
			};

			inline void operator/=(const float scalar)
			{
				mVector[0] /= scalar;
				mVector[1] /= scalar;
				mVector[2] /= scalar;
			};
			inline Float3 operator/(const float scalar) const
			{
				Float3 result((*this));
				result /= scalar;
				return result;
			};

			inline bool operator==(const Float3 vector) const { if (mVector[0] == vector.X() && mVector[1] == vector.Y() && mVector[2] == vector.Z()) return true; };
			inline bool operator!=(const Float3 vector) const { return !((*this) == vector); };

			inline void operator+=(const Float3 vector)
			{
				mVector[0] += vector.X();
				mVector[1] += vector.Y();
				mVector[2] += vector.Z();
			};
			inline Float3 operator+(const Float3 vector) const
			{
				Float3 result(*this);
				result += vector;
				return result;
			};

			inline void operator-=(const Float3 vector)
			{
				mVector[0] -= vector.X();
				mVector[1] -= vector.Y();
				mVector[2] -= vector.Z();
			};
			inline Float3 operator-(const Float3 vector) const
			{
				Float3 result(*this);
				result -= vector;
				return result;
			};

			/** Normalize the vector and return its former length. **/
			inline float Normalize()
			{
				float length = Length();
				(*this) /= length;
				return length;
			};

			/** Get a normalized version of this vector. **/
			inline Float3 Normalized() const
			{
				Float3 unitVector(*this);
				unitVector.Normalize();
				return unitVector;
			};

			/** Calculate the dot product of the two vectors. **/
			inline float Dot(Float3 vector) const { return (mVector[0] * vector.X()) + (mVector[1] * vector.Y()) + (mVector[2] * vector.Z()); };

			/** Calculate the cross product of the two vectors. **/
			inline Float3 Cross(Float3 vector) const
			{
				float x = (mVector[2] * vector.Y()) - (mVector[1] * vector.Z());
				float y = (mVector[0] * vector.Z()) - (mVector[2] * vector.X());
				float z = (mVector[1] * vector.X()) - (mVector[0] * vector.Y());
				return Float3(x, y, z);
			};
		};
	}
}