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
		/** This clas represets a floating-point vector in 3D space. **/
		class Float3
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
				};

				float mVector[3];
			};

		public:
			/** Default Constructor.All values are set to zero. **/
			Float3() 
			{ 
				mX = 0.0f; 
				mY = 0.0f; 
				mZ = 0.0f; 
			};

			/** Create a new vector with all values set to the same. **/
			explicit Float3(float value) 
			{ 
				mX = value; 
				mY = value; 
				mZ = value; 
			};

			/** Create a new vector with the given data. **/
			explicit Float3(float x, float y, float z) 
			{ 
				mX = x; 
				mY = y; 
				mZ = z; 
			};

			/** Create a new vector with the given data. **/
			explicit Float3(Float2 vector, float z) 
			{ 
				mX = vector.X(); 
				mY = vector.Y(); 
				mZ = z; 
			};


			/** Get the i'th element. **/
			inline float operator[](const unsigned short index) const { return mVector[index]; };
			/** Set the i'th element to the given value. **/
			inline void set(const unsigned short index, const float value) { mVector[index] = value; };
			/** Set all elements to the given value. **/
			inline void set(const float value) { mX = value; mY = value; mZ = value; };

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

			/** Get the X and Y coordinates. **/
			inline Float2 XY() const { return Float2(mX, mY); };
			/** Get the Y and Z coordinates. **/
			inline Float2 YZ() const { return Float2(mY, mZ); };
			/** Get the X and Z coordinates. **/
			inline Float2 XZ() const { return Float2(mX, mZ); };

			/** Get the length of this vector. **/
			inline float Length() const 
			{ 
				return sqrtf(powf(mX, 2.0f) + 
					powf(mY, 2.0f) + 
					powf(mZ, 2.0f)); 
			};

			/** Multiply vector by scalar. **/
			inline void operator*=(const float scalar)
			{
				mX *= scalar;
				mY *= scalar;
				mZ *= scalar;
			};

			/** Multiply vector by scalar. **/
			inline Float3 operator*(const float scalar) const
			{
				Float3 result((*this));
				result *= scalar;
				return result;
			};

			/** Multiply vector by scalar. **/
			inline friend Float3 operator*(const float scalar, const Float3 vector)
			{
				return vector * scalar;
			}

			/** Divide vector by scalar. **/
			inline void operator/=(const float scalar)
			{
				mX /= scalar;
				mY /= scalar;
				mZ /= scalar;
			};

			/** Divide vector by scalar. **/
			inline Float3 operator/(const float scalar) const
			{
				Float3 result((*this));
				result /= scalar;
				return result;
			};

			/** Compare two vectors. **/
			inline bool operator==(const Float3 vector) const 
			{
				return fabsf(mX - vector.X()) < MATH_FLOAT_PRECISION &&
					fabsf(mY - vector.Y()) < MATH_FLOAT_PRECISION &&
					fabsf(mZ - vector.Z()) < MATH_FLOAT_PRECISION;
			};

			/** Compare two vectors. **/
			inline bool operator!=(const Float3 vector) const 
			{ 
				return !((*this) == vector); 
			};

			/** Add two vectors together. **/
			inline void operator+=(const Float3 vector)
			{
				mX += vector.X();
				mY += vector.Y();
				mZ += vector.Z();
			};

			/** Add two vectors together. **/
			inline Float3 operator+(const Float3 vector) const
			{
				Float3 result(*this);
				result += vector;
				return result;
			};

			/** Subtract a vector from another. **/
			inline void operator-=(const Float3 vector)
			{
				mX -= vector.X();
				mY -= vector.Y();
				mZ -= vector.Z();
			};

			/** Subtract a vector from another. **/
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
				float length = Length();		
				return (*this) / length;
			};

			/** Calculate the dot product of the two vectors. **/
			inline float Dot(Float3 vector) const 
			{ 
				return (mX * vector.X()) + 
					(mY * vector.Y()) + 
					(mZ * vector.Z()); 
			};

			/** Calculate the cross product of the two vectors. **/
			inline Float3 Cross(Float3 vector) const
			{
				float x = (mZ * vector.Y()) - (mY * vector.Z());
				float y = (mX * vector.Z()) - (mZ * vector.X());
				float z = (mY * vector.X()) - (mX * vector.Y());
				return Float3(x, y, z);
			};
		};
	}
}