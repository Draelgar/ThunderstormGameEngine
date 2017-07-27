/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-03-30
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include "Float3.h"

namespace ts
{
	namespace math
	{
		class Float4
		{
		protected:
			/** The actual data. **/
			union
			{
				struct
				{
					float mX;
					float mY;
					float mZ;
					float mW;
				};

				float mVector[4];
			};

		public:
			/** Default Constructor. All values are set to zero. **/
			Float4() { mX = 0.0f; mY = 0.0f; mZ = 0.0f; mW = 0.0f; };
			/** Create a new vector with all values set to the same. **/
			explicit Float4(float value) { mX = value; mY = value; mZ = value; mW = value; };
			/** Create a new vector with the given data. **/
			explicit Float4(float x, float y, float z, float w) { mX = x; mY = y; mZ = z; mW = w; };
			/** Create a new vector with the given data. **/
			explicit Float4(Float2 vector, float z, float w) { mX = vector.X(); mY = vector.Y(); mZ = z; mW = w; };
			/** Create a new vector with the given data. **/
			explicit Float4(Float3 vector, float w) { mX = vector.X(); mY = vector.Y(); mZ = vector.Z(); mW = w; };


			/** Get the i'th element. **/
			inline float operator[](const unsigned short index) const { return mVector[index]; };
			/** Set the i'th element to the given value. **/
			inline void Set(const unsigned short index, const float value) { mVector[index] = value; };
			/** Set all elements to the given value. **/
			inline void Set(const float value) { mX = value; mY = value; mZ = value; mW = value; };

			/** Get the X-coordinate. **/
			inline float X() const { return mX; };
			/** Set the X-coordinate. **/
			inline void X(const float value) { mX = value; };

			/** Get the Y-coordinate. **/
			inline float Y() const { return mY; };
			/** Set the Y-coordinate. **/
			inline void Y(const float value) { mY = value; };

			/** Get the Z-coordinate. **/
			inline float Z() const { return mZ; };
			/** Set the Z-coordinate. **/
			inline void Z(const float value) { mZ = value; };

			/** Get the W-coordinate. **/
			inline float W() const { return mW; };
			/** Set the W-coordinate. **/
			inline void W(const float value) { mW = value; };

			/** Get the X and Y compinents of the vector. **/
			inline Float2 XY() const { return Float2(mX, mY); };
			/** Get the Y and Z compinents of the vector. **/
			inline Float2 YZ() const { return Float2(mY, mZ); };
			/** Get the X and Z compinents of the vector. **/
			inline Float2 XZ() const { return Float2(mX, mZ); };
			/** Get the X and W compinents of the vector. **/
			inline Float2 XW() const { return Float2(mX, mW); };
			/** Get the Y and W compinents of the vector. **/
			inline Float2 YW() const { return Float2(mY, mW); };
			/** Get the Z and W compinents of the vector. **/
			inline Float2 ZW() const { return Float2(mZ, mW); };

			/** Get the X, Y and Z components of the vector. **/
			inline Float3 XYZ() const { return Float3(mX, mY, mZ); };
			/** Get the X, Y and W components of the vector. **/
			inline Float3 XYW() const { return Float3(mX, mY, mW); };
			/** Get the X, Z and W components of the vector. **/
			inline Float3 XZW() const { return Float3(mX, mZ, mW); };
			/** Get the Y, Z and W components of the vector. **/
			inline Float3 YZW() const { return Float3(mY, mZ, mW); };

			/** Get the length of this vector. **/
			inline float Length() const { return sqrtf(powf(mX, 2.0f) + powf(mY, 2.0f) + powf(mZ, 2.0f) + powf(mW, 2.0f)); };

			/** Multiply by scalar. **/
			inline void operator*=(const float scalar)
			{
				mX *= scalar;
				mY *= scalar;
				mZ *= scalar;
				mW *= scalar;
			};
			/** Multiply by scalar. **/
			inline Float4 operator*(const float scalar) const
			{
				Float4 result((*this));
				result *= scalar;
				return result;
			};
			/** Multiply by scalar. **/
			inline friend Float4 operator*(const float scalar, const Float4 vector) { return vector * scalar; };

			/** Divide by scalar; **/
			inline void operator/=(const float scalar)
			{
				mX /= scalar;
				mY /= scalar;
				mZ /= scalar;
				mW /= scalar;
			};
			/** Divide by scalar; **/
			inline Float4 operator/(const float scalar) const
			{
				Float4 result((*this));
				result /= scalar;
				return result;
			};

			/** Compare two vectors. **/
			inline bool operator==(const Float4 vector) const 
			{
				return fabsf(mX - vector.X()) < 1.0e-07f && fabsf(mY - vector.Y()) < 1.0e-07f && fabsf(mZ - vector.Z()) < 1.0e-07f && fabsf(mW - vector.W()) < 1.0e-07f;
			};
			/** Compare two vectors. **/
			inline bool operator!=(const Float4 vector) const { return !((*this) == vector); };

			/** Add two vectors together. **/
			inline void operator+=(const Float4 vector)
			{
				mX += vector.X();
				mY += vector.Y();
				mZ += vector.Z();
				mW += vector.W();
			};
			/** Add two vectors together. **/
			inline Float4 operator+(const Float4 vector) const
			{
				Float4 result(*this);
				result += vector;
				return result;
			};

			/** Subtract a vector from another. **/
			inline void operator-=(const Float4 vector)
			{
				mX -= vector.X();
				mY -= vector.Y();
				mZ -= vector.Z();
				mZ -= vector.W();
			};
			/** Subtract a vector from another. **/
			inline Float4 operator-(const Float4 vector) const
			{
				Float4 result(*this);
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
			inline Float4 Normalized() const
			{
				Float4 unitVector(*this);
				unitVector.Normalize();
				return unitVector;
			};

			/** Calculate the dot product of the two vectors. **/
			inline float Dot(Float4 vector) const { return (mX * vector.X()) + (mY * vector.Y()) + (mZ * vector.Z()) + (mW * vector.W()); };

			/** Calculate the cross product of the two vectors. **/
			inline Float4 Cross(Float4 vector) const
			{
				float x = (mW * vector.Z()) - (mY * vector.Z());
				float y = (mX * vector.W()) - (mZ * vector.W());
				float z = (mY * vector.X()) - (mW * vector.X());
				float w = (mZ * vector.Y()) - (mX * vector.Y());
				return Float4(x, y, z, w);
			};
		};
	}
}
