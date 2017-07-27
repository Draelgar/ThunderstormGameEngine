/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-03-31
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include "Quaternion.h"

namespace ts
{
	namespace math
	{
		/** This class represents a row major 4 x 4 floating point matrix. **/
		class Matrix
		{
		protected:
			/** The actual matrix data. **/
			float mMatrix[16];

			// Calculate the upper and lower triangles with LU-Decomposition.
			void LUDecomposition(float l[], float u[]) const;

		public:
			/** Default constructor, creates a matrix with all items set to 0.0f. **/
			Matrix() { for (unsigned short i = 0; i < 16; i++) mMatrix[i] = 0.0f; };

			/** Create a matrix with all values set to the given value.
			*	\param value -The value to set all components to. **/
			explicit Matrix(const float value) { for (unsigned short i = 0; i < 16; i++) mMatrix[i] = value; };

			/** Create a matrix by using the given vectors as rows.
			*	\param a -The first row of the matrix.
			*	\param b -The second row of the matrix.
			*	\param c -The third row of the matrix.
			*	\param d -The fourth and last row of the matrix. **/
			explicit Matrix(const Float4 a, const Float4 b, const Float4 c, const Float4 d);

			/** Set the element at selected row and column of the matrix to the given value.
			*	\param row -The row index of the element to set.
			*	\param column -The column index of the element to set.
			*	\param value -The value to set the element to. **/
			inline void Set(const unsigned short row, const unsigned short column, const float value) { mMatrix[column + (row * 4)] = value; };

			/** Get the value at the given row and column in the matrix.
			*	\param row -The row index of the element to get.
			*	\param column -The column of the element to set.
			*	\return The value of the element if the indices was within the matrix. **/
			inline float Get(const unsigned short row, const unsigned short column) const { return mMatrix[column + (row * 4)]; };

			/** Get the element at row 0 and column 0. **/
			inline float a00() const { return mMatrix[0]; };
			/** Get the element at row 0 and column 1. **/
			inline float a01() const { return mMatrix[1]; };
			/** Get the element at row 0 and column 2. **/
			inline float a02() const { return mMatrix[2]; };
			/** Get the element at row 0 and column 3. **/
			inline float a03() const { return mMatrix[3]; };

			/** Get the element at row 1 and column 0. **/
			inline float a10() const { return mMatrix[4]; };
			/** Get the element at row 1 and column 1. **/
			inline float a11() const { return mMatrix[5]; };
			/** Get the element at row 1 and column 2. **/
			inline float a12() const { return mMatrix[6]; };
			/** Get the element at row 1 and column 3. **/
			inline float a13() const { return mMatrix[7]; };

			/** Get the element at row 2 and column 0. **/
			inline float a20() const { return mMatrix[8]; };
			/** Get the element at row 2 and column 1. **/
			inline float a21() const { return mMatrix[9]; };
			/** Get the element at row 2 and column 2. **/
			inline float a22() const { return mMatrix[10]; };
			/** Get the element at row 2 and column 3. **/
			inline float a23() const { return mMatrix[11]; };

			/** Get the element at row 3 and column 0. **/
			inline float a30() const { return mMatrix[12]; };
			/** Get the element at row 3 and column 1. **/
			inline float a31() const { return mMatrix[13]; };
			/** Get the element at row 3 and column 2. **/
			inline float a32() const { return mMatrix[14]; };
			/** Get the element at row 3 and column 3. **/
			inline float a33() const { return mMatrix[15]; };

			/** Set the element at row 0 and column 0. **/
			inline void a00(const float value) { mMatrix[0] = value; };
			/** Set the element at row 0 and column 1. **/
			inline void a01(const float value) { mMatrix[1] = value; };
			/** Set the element at row 0 and column 2. **/
			inline void a02(const float value) { mMatrix[2] = value; };
			/** Set the element at row 0 and column 3. **/
			inline void a03(const float value) { mMatrix[3] = value; };

			/** Set the element at row 1 and column 0. **/
			inline void a10(const float value) { mMatrix[4] = value; };
			/** Set the element at row 1 and column 1. **/
			inline void a11(const float value) { mMatrix[5] = value; };
			/** Set the element at row 1 and column 2. **/
			inline void a12(const float value) { mMatrix[6] = value; };
			/** Set the element at row 1 and column 3. **/
			inline void a13(const float value) { mMatrix[7] = value; };

			/** Set the element at row 2 and column 0. **/
			inline void a20(const float value) { mMatrix[8] = value; };
			/** Set the element at row 2 and column 1. **/
			inline void a21(const float value) { mMatrix[9] = value; };
			/** Set the element at row 2 and column 2. **/
			inline void a22(const float value) { mMatrix[10] = value; };
			/** Set the element at row 2 and column 3. **/
			inline void a23(const float value) { mMatrix[11] = value; };

			/** Set the element at row 3 and column 0. **/
			inline void a30(const float value) { mMatrix[12] = value; };
			/** Set the element at row 3 and column 1. **/
			inline void a31(const float value) { mMatrix[13] = value; };
			/** Set the element at row 3 and column 2. **/
			inline void a32(const float value) { mMatrix[14] = value; };
			/** Set the element at row 3 and column 3. **/
			inline void a33(const float value) { mMatrix[15] = value; };

			/** Transpose this matrix by swapping rows with columns. **/
			void Transpose();

			/** Get a transposed copy of this matrix. **/
			inline Matrix GetTranspose() const
			{
				Matrix transpose(*this);
				transpose.Transpose();
				return transpose;
			};

			/** Multiply two 4x4 matrices. **/
			Matrix operator*(const Matrix matrix) const;

			/** Multiply this metrix with another. **/
			void operator*=(const Matrix matrix);

			/** Add two matrices together. **/
			inline Matrix operator+(const Matrix matrix) const
			{
				Matrix result(*this);
				result += matrix;
				return result;
			};

			/** Subtract a matrix from another. **/
			inline Matrix operator-(const Matrix matrix) const
			{
				Matrix result(*this);
				result -= matrix;
				return result;
			}

			/** Add another matrix onto this one. **/
			inline void operator+=(const Matrix matrix)
			{
				for (unsigned int row = 0; row < 4; row++)
					for (unsigned int col = 0; col < 4; col++)
						mMatrix[col + (row * 4)] += matrix.Get(row, col); // Add the elements pair wise.
			};

			/** Subtract another matrix from this one. **/
			inline void operator-=(const Matrix matrix)
			{
				for (unsigned int row = 0; row < 4; row++)
					for (unsigned int col = 0; col < 4; col++)
						mMatrix[col + (row * 4)] -= matrix.Get(row, col); // Subtract the elements pair wise.
			};

			/** Get an identity matrix. **/
			inline static Matrix Identity()
			{
				return Matrix(Float4(1.0f, 0.0f, 0.0f, 0.0f), Float4(0.0f, 1.0f, 0.0f, 0.0f),
					Float4(Float2(), 1.0f, 0.0f), Float4(Float3(), 1.0f));
			};

			/** Get the determinant of the matrix. **/
			float Determinant() const;

			/** Get the trace of the matrix. **/
			inline float Trace() const
			{
				float sum = 0.0f;
				// The trace is the sum of the diagonal elements.
				for (unsigned short i = 0; i < 4; i++)
					sum += mMatrix[i + (i * 4)];
				return sum;
			};

			/** Multiply the matrix by a 4D vector. **/
			Float4 operator*(const Float4 vector) const;

			/** Multiply the matrix by a scalar value. **/
			inline Matrix operator*(const float scalar) const
			{
				Matrix result(*this);
				result *= scalar;
				return result;
			};

			/** Multiply the matrix by a scalar value. **/
			inline void operator*=(const float scalar) { for (unsigned short i = 0; i < 16; i++) mMatrix[i] *= scalar; };

			/** Divide the matrix by a scalar value. **/
			inline Matrix operator/(const float scalar) const
			{
				Matrix result(*this);
				result /= scalar;
				return result;
			};

			/** Divide the matrix by a scalar value. **/
			void operator/=(const float scalar);

			/** Calculate the inverse of the matrix (if it has one!). **/
			Matrix Inverse() const;

			/** Make sure the rows of this matrix are unit vectors. **/
			void Orthonormalize();

			/** Translate this matrix using OpenGL standard. **/
			inline void TranslateGL(const Float3 translation)
			{
				a30(a30() + translation.X());
				a31(a31() + translation.Y());
				a32(a32() + translation.Z());
			};

			/** Translate this matrix using DirectX standard. **/
			inline void TranslateDX(const Float3 translation)
			{
				a03(a03() + translation.X());
				a13(a13() + translation.Y());
				a23(a23() + translation.Z());
			};

			/** Setup a translation matrix using OpenGL standard. **/
			inline static Matrix TranslationGL(const Float3 translation)
			{
				Matrix matrix = Identity();
				matrix.a30(translation.X());
				matrix.a31(translation.Y());
				matrix.a32(translation.Z());
				return matrix;
			};

			/** Setup a translation matrix using DirectX standard. **/
			inline static Matrix TranslationDX(const Float3 translation)
			{
				Matrix matrix = Identity();
				matrix.a03(translation.X());
				matrix.a13(translation.Y());
				matrix.a23(translation.Z());
				return matrix;
			};

			/** Get the translation for OpenGL. **/
			inline Float3 TranslationGL() const { return Float3(a30(), a31(), a32()); };

			/** Get the translation for DirectX. **/
			inline Float3 TranslationDX() const { return Float3(a03(), a13(), a23()); };

			/** Create a matrix representing the rotation around an arbitrary axis. **/
			static Matrix Rotation(Float4 rotation);

			/** Rotate this matrix around an arbitrary axis. **/
			inline void Rotate(Float4 rotation)
			{
				Matrix matrix = Rotation(rotation);
				for (unsigned short r = 0; r < 4; r++)
					for (unsigned short c = 0; c < 4; c++)
						Set(r, c, matrix.Get(r, c));
			};

			/** Return a raw pointer to the array so it can be handed over to the GPU. **/
			inline float* ToArray() { return mMatrix; }

			/** Scale the matrix.
			* \param scalar -The value by which to scale the matrix.**/
			inline void Scale(const float scalar) { a33(a33() * scalar); };

			/** Scale each axis individually.
			* \param scalars -A vector containing the scalars for each axis. **/
			inline void Scale(const Float3 scalars)
			{
				a00(a00() * scalars.X());
				a11(a11() * scalars.Y());
				a22(a22() * scalars.Z());
			};

			/** Get the scale as a vector.
			* \return The vector representing the scale. **/
			inline Float3 GetScale() const { return Float3(a00(), a11(), a22()); };

			/** Unify the scales by pushing the axis scales towards one and use the main scalar to keep track of the scale.**/
			void UnifyScale();

			/** Create a shearing effect on the matrix. The allowed axis/element combos are xy, xz, yx, yz, zx and zy.
			* \param
			* \param shear -The amount by which to shear the axis element. **/
			inline void Shear(const unsigned short axis, const unsigned short element, const float shear) {
				if (axis != element && axis < 3 && element < 3)
					mMatrix[element + (axis * 4)] *= shear;
			};

			/** Build the rotation matrix from a quaternion. **/
			void FromQuaternion(const Quaternion quaternion);

			/** Convert the rotation matrix into a quaternion. **/
			Quaternion ToQuaternion() const;

			/** Setup a perspective view matrix.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing a perspective view projection.**/
			static Matrix PerspectiveViewGL(const float left, const float right, const float top, const float bottom, const float near, const float far);

			/** Setup a perspective view matrix.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing a perspective view projection.**/
			static Matrix PerspectiveViewDX(const float left, const float right, const float top, const float bottom, const float near, const float far);

			/** Create an orthogonal view matrix for openGL.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing an orthogonal view projection. **/
			static Matrix OrthogonalViewGL(const float left, const float right, const float top, const float bottom, const float near, const float far);

			/** Create an orthogonal view matrix for direct3D.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing an orthogonal view projection. **/
			static Matrix OrthogonalViewDX(const float left, const float right, const float top, const float bottom, const float near, const float far);

			/** Calculate the best horizontal and vertical field of view based on the display's width & height and the distance to the viewer. **/
			inline static Float2 CalculateRecommendedFieldOfView(float width, float height, float distance) { return Float2(2.0f * atanf(width / (2 * distance)), 2.0f * atanf(height / (2 * distance))); };

			/** Setup a camera view matrix.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\param orientation -The orientation of the camera.
			*	\param position -The position of the camera.
			*	\return A view matrix for the defined camera. **/
			static Matrix CameraViewGL(const float left, const float right, const float top, const float bottom, const float near, const float far, const Float4 orientation, const Float4 position);

			/** Setup a camera view matrix.
			*	\param lens -The projection matrix to use.
			*	\param orientation -The orientation of the camera.
			*	\param position -The position of the camera.
			*	\return A view matrix for the defined camera. **/
			static Matrix CameraViewGL(const Matrix lens, const Float4 orientation, const Float4 position);

			/** Setup a camera view matrix.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\param orientation -The orientation of the camera.
			*	\param position -The position of the camera.
			*	\return A view matrix for the defined camera. **/
			static Matrix CameraViewDX(const float left, const float right, const float top, const float bottom, const float near, const float far, const Float4 orientation, const Float4 position);

			/** Setup a camera view matrix.
			*	\param lens -The projection matrix to use.
			*	\param orientation -The orientation of the camera.
			*	\param position -The position of the camera.
			*	\return A view matrix for the defined camera. **/
			static Matrix CameraViewDX(const Matrix lens, const Float4 orientation, const Float4 position);
		};
	}
}
