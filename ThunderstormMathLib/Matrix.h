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
			union
			{
				struct
				{
					float mE00, mE01, mE02, mE03,
						mE10, mE11, mE12, mE13,
						mE20, mE21, mE22, mE23,
						mE30, mE31, mE32, mE33;
				};

				float mMatrix[16];
			};

			// Calculate the upper and lower triangles with LU-Decomposition.
			void LUDecomposition(float l[], float u[]) const;

		public:
			/** Default constructor, creates a matrix with all items set to 0.0f. **/
			Matrix() 
			{ 
				for (unsigned short i = 0; i < 16; i++) 
					mMatrix[i] = 0.0f; 
			};

			/** Create a matrix with all values set to the given value.
			*	\param value -The value to set all components to. **/
			explicit Matrix(const float value) 
			{ 
				for (unsigned short i = 0; i < 16; i++) 
					mMatrix[i] = value; 
			};

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
			inline void Set(const unsigned short row, const unsigned short column, const float value) 
			{ 
				mMatrix[column + (row * 4)] = value; 
			};

			/** Get the value at the given row and column in the matrix.
			*	\param row -The row index of the element to get.
			*	\param column -The column of the element to set.
			*	\return The value of the element if the indices was within the matrix. **/
			inline float Get(const unsigned short row, const unsigned short column) const 
			{ 
				return mMatrix[column + (row * 4)]; 
			};

			/** Get the element at row 0 and column 0. **/
			inline float E00() const { return mE00; };
			/** Get the element at row 0 and column 1. **/
			inline float E01() const { return mE01; };
			/** Get the element at row 0 and column 2. **/
			inline float E02() const { return mE02; };
			/** Get the element at row 0 and column 3. **/
			inline float E03() const { return mE03; };

			/** Get the element at row 1 and column 0. **/
			inline float E10() const { return mE10; };
			/** Get the element at row 1 and column 1. **/
			inline float E11() const { return mE11; };
			/** Get the element at row 1 and column 2. **/
			inline float E12() const { return mE12; };
			/** Get the element at row 1 and column 3. **/
			inline float E13() const { return mE13; };

			/** Get the element at row 2 and column 0. **/
			inline float E20() const { return mE20; };
			/** Get the element at row 2 and column 1. **/
			inline float E21() const { return mE21; };
			/** Get the element at row 2 and column 2. **/
			inline float E22() const { return mE22; };
			/** Get the element at row 2 and column 3. **/
			inline float E23() const { return mE23; };

			/** Get the element at row 3 and column 0. **/
			inline float E30() const { return mE30; };
			/** Get the element at row 3 and column 1. **/
			inline float E31() const { return mE31; };
			/** Get the element at row 3 and column 2. **/
			inline float E32() const { return mE32; };
			/** Get the element at row 3 and column 3. **/
			inline float E33() const { return mE33; };

			/** Set the element at row 0 and column 0. **/
			inline void E00(const float value) { mE00 = value; };
			/** Set the element at row 0 and column 1. **/
			inline void E01(const float value) { mE01 = value; };
			/** Set the element at row 0 and column 2. **/
			inline void E02(const float value) { mE02 = value; };
			/** Set the element at row 0 and column 3. **/
			inline void E03(const float value) { mE03 = value; };

			/** Set the element at row 1 and column 0. **/
			inline void E10(const float value) { mE10 = value; };
			/** Set the element at row 1 and column 1. **/
			inline void E11(const float value) { mE11 = value; };
			/** Set the element at row 1 and column 2. **/
			inline void E12(const float value) { mE12 = value; };
			/** Set the element at row 1 and column 3. **/
			inline void E13(const float value) { mE13 = value; };

			/** Set the element at row 2 and column 0. **/
			inline void E20(const float value) { mE20 = value; };
			/** Set the element at row 2 and column 1. **/
			inline void E21(const float value) { mE21 = value; };
			/** Set the element at row 2 and column 2. **/
			inline void E22(const float value) { mE22 = value; };
			/** Set the element at row 2 and column 3. **/
			inline void E23(const float value) { mE23 = value; };

			/** Set the element at row 3 and column 0. **/
			inline void E30(const float value) { mE30 = value; };
			/** Set the element at row 3 and column 1. **/
			inline void E31(const float value) { mE31 = value; };
			/** Set the element at row 3 and column 2. **/
			inline void E32(const float value) { mE32 = value; };
			/** Set the element at row 3 and column 3. **/
			inline void E33(const float value) { mE33 = value; };

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
				Matrix matrix;
				matrix.E00(1.0f);
				matrix.E11(1.0f);
				matrix.E22(1.0f);
				matrix.E33(1.0f);

				return matrix;
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

			/** Multiply a scalar and a matrix. **/
			friend Matrix operator*(const float scalar, const Matrix matrix)
			{
				return matrix * scalar;
			}

			/** Multiply the matrix by a scalar value. **/
			inline void operator*=(const float scalar) 
			{ 
				for (unsigned short i = 0; i < 16; i++) 
					mMatrix[i] *= scalar; 
			};

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
				E30(E30() + translation.X());
				E31(E31() + translation.Y());
				E32(E32() + translation.Z());
			};

			/** Translate this matrix using DirectX standard. **/
			inline void TranslateDX(const Float3 translation)
			{
				E03(E03() + translation.X());
				E13(E13() + translation.Y());
				E23(E23() + translation.Z());
			};

			/** Setup a translation matrix using OpenGL standard. **/
			inline static Matrix TranslationGL(const Float3 translation)
			{
				Matrix matrix = Identity();
				matrix.E30(translation.X());
				matrix.E31(translation.Y());
				matrix.E32(translation.Z());
				return matrix;
			};

			/** Setup a translation matrix using DirectX standard. **/
			inline static Matrix TranslationDX(const Float3 translation)
			{
				Matrix matrix = Identity();
				matrix.E03(translation.X());
				matrix.E13(translation.Y());
				matrix.E23(translation.Z());
				return matrix;
			};

			/** Get the translation for OpenGL. **/
			inline Float3 TranslationGL() const { return Float3(E30(), E31(), E32()); };

			/** Get the translation for DirectX. **/
			inline Float3 TranslationDX() const { return Float3(E03(), E13(), E23()); };

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
			inline void Scale(const float scalar) { E33(E33() * scalar); };

			/** Scale each axis individually.
			* \param scalars -A vector containing the scalars for each axis. **/
			inline void Scale(const Float3 scalars)
			{
				E00(E00() * scalars.X());
				E11(E11() * scalars.Y());
				E22(E22() * scalars.Z());
			};

			/** Get the scale as a vector.
			* \return The vector representing the scale. **/
			inline Float3 GetScale() const { return Float3(E00(), E11(), E22()); };

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
			inline static Float2 CalculateRecommendedFieldOfView(float width, float height, float distance) 
			{ 
				return Float2(2.0f * atanf(width / (2 * distance)), 2.0f * atanf(height / (2 * distance))); 
			};

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
			static Matrix CameraViewGL(const float left, const float right, const float top, const float bottom, 
				const float near, const float far, const Float4 orientation, const Float4 position);

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
			static Matrix CameraViewDX(const float left, const float right, const float top, const float bottom, 
				const float near, const float far, const Float4 orientation, const Float4 position);

			/** Setup a camera view matrix.
			*	\param lens -The projection matrix to use.
			*	\param orientation -The orientation of the camera.
			*	\param position -The position of the camera.
			*	\return A view matrix for the defined camera. **/
			static Matrix CameraViewDX(const Matrix lens, const Float4 orientation, const Float4 position);
		};
	}
}