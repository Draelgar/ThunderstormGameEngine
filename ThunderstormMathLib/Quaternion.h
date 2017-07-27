/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-03-30
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include "Float4.h"

namespace ts
{
	namespace math
	{
		/** This class represents a quaternion. **/
		class Quaternion : public Float4
		{
		public:
			/** Create a new quaternion with all values set to zero. **/
			Quaternion() : Float4() {};

			/** Create a new quaternion with the given imaginary part and real part. **/
			explicit Quaternion(Float3 imaginary, float real) : Float4(imaginary, real) {};

			/** Convert a 4D vector into a quaternion. **/
			explicit Quaternion(Float4 vector)
			{
				mVector[0] = vector.X();
				mVector[1] = vector.Y();
				mVector[2] = vector.Z();
				mVector[3] = vector.W();
			};

			/** Create a new quaternion with the given components. **/
			explicit Quaternion(float x, float y, float z, float w) : Float4(x, y, z, w) {};

			/** Convert this quaternion into a regular 4D vector. **/
			inline Float4 ToFloat4() { return Float4(X(), Y(), Z(), W()); }

			inline Float3 Imaginary() const { return XYZ(); };
			inline float Real() const { return W(); }
			inline void Real(const float real) { mVector[3] = real; };
			inline void Imaginary(const Float3 imaginary)
			{
				mVector[0] = imaginary.X();
				mVector[1] = imaginary.Y();
				mVector[2] = imaginary.Z();
			};

			/** Multiply two quaternions with each other.
			*	\param quat -The other quaternion.
			*	\return The resulting quaternion. **/
			Quaternion operator*(const Quaternion quaternion) const;

			/** Multiply two quaternions with each other.
			*	\param quat -The other quaternion. **/
			void operator*=(const Quaternion quaternion);

			/** Multiply a quaternion by a scalar value.
			*	\param scalar -The scalar to multiply with.
			*	\return The resulting quaternion. **/
			inline Quaternion operator*(const float scalar) const { return Quaternion(X() * scalar, Y() * scalar, Z() * scalar, W() * scalar); };

			/** Divide a quaternion by a scalar value.
			*	\param scalar -The scalar to divide by.
			*	\return The resulting quaternion. **/
			inline Quaternion operator/(const float scalar) const { return Quaternion(X() / scalar, Y() / scalar, Z() / scalar, W() / scalar); }

			/** Addition between two quaternions.
			*	\param quat -The quaternion to add.
			*	\result The resulting quaternion. **/
			inline Quaternion operator+(const Quaternion quaternion) const { return Quaternion(X() + quaternion.X(), Y() + quaternion.Y(), Z() + quaternion.Z(), W() + quaternion.W()); };

			/** Subtraction between two quaternions.
			*	\param quat -The quaternion to subtract.
			*	\result The resulting quaternion. **/
			inline Quaternion operator-(const Quaternion quaternion) const { return Quaternion(X() - quaternion.X(), Y() - quaternion.Y(), Z() - quaternion.Z(), W() - quaternion.W()); };

			/** Get a conjugate of this quaternion.
			*	\return The resulting quaternion. **/
			inline Quaternion Conjugate() const { return Quaternion(-X(), -Y(), -Z(), W()); };

			/** Get an identity quaternion.
			*	\return The identity quaternion. **/
			inline Quaternion Identity() const { return Quaternion(0.0f, 0.0f, 0.0f, 1.0f); };

			/** Get the norm of this quaternion.
			*	\return The norm of this quaternion as a floating-point value.**/
			inline float Norm() const { return Length(); };

			/** Get the inverse of this quaternion.
			*	\return The inverse of this quaternion.**/
			inline Quaternion Inverse() const { return Conjugate() / Norm(); };

			/** Rotate a point by the aid of this quaternion. (Assumes it is a unit quaternion).
			*	\param point -The values of the point inserted into a quaternion.
			*	\return The rotated point in the form of a quaternion. **/
			inline Quaternion RotatePoint(Quaternion point) const { return ((*this) * point) * Conjugate(); };

			/** Rotate a point by the aid of this quaternion. (Assumes it is a unit quaternion).
			*	\param point -The values of the point inserted into a quaternion.
			*	\return The rotated point in the form of a quaternion. **/
			inline Float4 RotatePoint(Float4 point) const { Quaternion quaternion(point); return RotatePoint(quaternion).ToFloat4(); };

			/** Get a normalized version of unit length of this quaternion.
			*	\return The unit length version.**/
			inline Quaternion Normalized() const { return Quaternion(Float4::Normalized()); };
		};
	}
}
