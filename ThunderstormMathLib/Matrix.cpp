#include "Matrix.h"

using namespace ts::math;

void Matrix::LUDecomposition(float l[], float u[]) const
{
	const unsigned short size = 4;

	for (unsigned short i = 0; i < size; i++)
	{
		for (unsigned j = 0; j < size; j++)
		{
			// Elements above the diagonal is set to zero.
			if (j < i)
				l[i + (j * size)] = 0.0f;
			else
			{
				l[i + (j * size)] = mMatrix[i + (j * size)];

				for (unsigned short k = 0; k < i; k++)
				{
					l[i + (j * size)] = l[i + (j * size)] - l[i + (k * size)] * u[i + (k * size)];
				}
			}
		}
		for (unsigned short j = 0; j < size; j++)
		{
			// Elements below the diagonal is set to zero.
			if (j < i)
				u[j + (i * size)] = 0.0f;

			// Elements at the diagonal is set to 1.
			else if (j == i)
				u[j + (i * size)] = 1.0f;

			else
			{
				// Avoid possible division by zero!
				if (fabsf(l[i + (i * size)]) >= 0.000001f)
				{
					u[j + (i * size)] = mMatrix[j + (i * size)] / l[i + (i * size)];

					for (unsigned short k = 0; k < i; k++)
					{
						u[j + (i * size)] = u[j + (i * size)] - ((l[k + (i * size)] * u[j + (k * size)]) / l[i + (i * size)]);
					}
				}
				else
					u[j + (i * size)] = 0.0f;

			}

		}
	}
}

Matrix::Matrix(const Float4 a, const Float4 b, const Float4 c, const Float4 d)
{
	for (unsigned short i = 0; i < 16; i++)
		mMatrix[i] = a[i];

	for (unsigned short i = 0; i < 16; i++)
		mMatrix[i + 4] = b[i];

	for (unsigned short i = 0; i < 16; i++)
		mMatrix[i + 8] = c[i];

	for (unsigned short i = 0; i < 16; i++)
		mMatrix[i + 12] = d[i];
}

void Matrix::Transpose()
{
	float temp = 0.0f;
	for (unsigned short r = 0; r < 4; r++)
		for (unsigned short c = r; c < 4; c++)
		{
			temp = mMatrix[c + (r * 4)];
			mMatrix[c + (r * 4)] = mMatrix[r + (c * 4)];
			mMatrix[r + (c * 4)] = temp;
		}
}

Matrix Matrix::operator*(const Matrix matrix) const
{
	Matrix result;
	float element = 0.0f;

	for (unsigned short i = 0; i < 4; i++)
		for (unsigned short j = 0; j < 4; j++)
		{
			// Multiply each row of matrix a with each column of matrix b.
			for (unsigned short k = 0; k < 4; k++)
				element += Get(i, k) * matrix.Get(k, j);

			result.Set(i, j, element); // set the matrix element.
			element = 0.0f; // reset element storage.
		}

	return result;
}

void Matrix::operator*=(const Matrix matrix)
{
	Matrix result(*this);
	float element = 0.0f;

	for (unsigned short i = 0; i < 4; i++)
		for (unsigned short j = 0; j < 4; j++)
		{
			element = 0.0f; // reset element storage.
			// Multiply each row of matrix a with each column of matrix b.
			for (unsigned short k = 0; k < 4; k++)
				element += result.Get(i, k) * matrix.Get(k, j);

			Set(i, j, element); // set the matrix element.
		}
}

void Matrix::operator/=(const float scalar)
{
	if (fabsf(scalar) >= 0.000001f)
		// Divide each element by the scalar.
		for (unsigned short i = 0; i < 16; i++)
			mMatrix[i] /= scalar;
	else
		// Multiply each element by the scalar.
		for (unsigned short i = 0; i < 16; i++)
			mMatrix[i] = scalar;
}

Matrix Matrix::Inverse() const
{
	// Does this matrix even have an inverse? If the determinant is zero, it has no inverse.
	if (fabsf(Determinant()) >= 0.000001f)
	{
		Matrix inverse;
		float l[16], u[16];

		// Use LU decomposition.
		LUDecomposition(l, u);

		/** For each column of the inverse: LUx = b => Ld = b & Ux = d.
		d = [b_x / L11, (b_y - (L21 * d_x)) / L22, (b_z - (L31 * d_x) - (L32 * d_y)) / L33]
		x = [(d_x - (U12 * x_y) - (U13 * x_z)) / U11, (d_y - (U23 * x_z)) / U22, d_z / U33] **/

		Float4 x(0.0f), d(0.0f), b(0.0f);

		// Calculate vector x for each column of the inverse matrix.
		for (unsigned short i = 0; i < 4; i++)
		{
			// Prepare vectors.
			for (unsigned short j = 0; j < 4; j++)
			{
				// Clean vector x and d.
				x.Set(j, 0.0f);
				d.Set(j, 0.0f);

				// Build the column from the identity matrix.
				if (i == j)
					b.Set(j, 1.0f);
				else
					b.Set(j, 0.0f);
			}

			// Calculate column vector d.
			if (fabsf(l[0]) >= 0.000001f)
				d.X(b.X() / l[0]); // b_x / L00

			if (fabsf(l[5]) >= 0.000001f)
				d.Y((b.Y() - (l[4] * d.X())) / l[5]); // (b_y - (L10 * d_x)) / L11

			if (fabsf(l[10]) >= 0.000001f)
				d.Z((b.Z() - (l[8] * d.X()) - (l[9] * d.Y())) / l[10]); // (b_z - (L20 * d_x) - (L21 * d_y)) / L22

			if (fabsf(l[15]) >= 0.000001f)
				d.W((b.W() - (l[12] * d.X()) - (l[13] * d.Y()) - (l[14] * d.Z())) / l[15]); // (b_w - (L30 * d_x) - (L31 * d_y) - (L32 * d_z) / L33

																										   // Calculate column i for the inversed matrix.
			if (fabsf(u[15]) >= 0.000001f)
				x.W(d.W() / u[15]); // d_w / U33

			if (fabsf(u[10]) >= 0.000001f)
				x.Z((d.Z() - (x.W() * u[11])) / u[10]); // (d_z - (x_w * U23)) / U22

			if (fabsf(u[5]) >= 0.000001f)
				x.Y((d.Y() - (x.W() * u[7]) - (u[6] * x.Z())) / u[5]); // (d_y - (x_w * U13) - (U12 * x_z)) / U11

			if (fabsf(u[0]) >= 0.000001f)
				x.X((d.X() - (u[1] * x.Y()) - (u[2] * x.Z()) - (u[3] * x.W())) / u[0]); // (d_x - (U01 * x_y) - (U02 * x_z) - (x_w * U03)) / U00

																									   // Insert the column into the matrix.
			for (unsigned k = 0; k < 4; k++)
				inverse.Set(k, i, x[k]);
		}

		// Return the inverse.
		return inverse;
	}

	// No inverse to be found, so give the identity matrix instead.
	return Matrix::Identity();
}

void Matrix::Orthonormalize()
{
	// First row.
	float scale = sqrtf(powf(a00(), 2.0f) + powf(a01(), 2.0f) + powf(a02(), 2.0f));
	a00(a00() / scale);
	a01(a01() / scale);
	a02(a02() / scale);

	// Second row.
	scale = sqrtf(powf(a10(), 2.0f) + powf(a11(), 2.0f) + powf(a12(), 2.0f));
	a10(a10() / scale);
	a11(a11() / scale);
	a12(a12() / scale);

	// Third Row.
	scale = sqrtf(powf(a20(), 2.0f) + powf(a21(), 2.0f) + powf(a22(), 2.0f));
	a20(a20() / scale);
	a21(a21() / scale);
	a22(a22() / scale);
}

Matrix Matrix::Rotation(Float4 rotation)
{
	Matrix matrix = Identity();

	// First row
	// cos a + (1 - cos a)x^2; (1 - cos a)xy - zsin a; (1 - cos a)xz + ysin a
	matrix.a00(cosf(rotation.W()) + ((1.0f - cosf(rotation.W())) * powf(rotation.X(), 2.0f)));
	matrix.a01((1.0f - cosf(rotation.W())) * rotation.X() * rotation.Y() - (rotation.Z() * sinf(rotation.W())));
	matrix.a02((1.0f - cosf(rotation.W())) * rotation.X() * rotation.Z() + (rotation.Y() * sinf(rotation.W())));

	// Second row
	// (1 - cos a)xy + zsin a; cos a + (1 - cos a)y^2; (1 - cos a)yz - xsin a
	matrix.a10((1.0f - cosf(rotation.W())) * rotation.X() * rotation.Y() + (rotation.Z() * sinf(rotation.W())));
	matrix.a11(cosf(rotation.W()) + ((1.0f - cosf(rotation.W())) * powf(rotation.Y(), 2.0f)));
	matrix.a12((1.0f - cosf(rotation.W())) * rotation.Y() * rotation.Z() - (rotation.X() * sinf(rotation.W())));

	// Third row
	// (1 - cos a)xz - ysin a; (1 - cos a)yz + xsin a; cos a + (1 - cos a)z^2
	matrix.a20((1.0f - cosf(rotation.W())) * rotation.X() * rotation.Z() - (rotation.Y() * sinf(rotation.W())));
	matrix.a21((1.0f - cosf(rotation.W())) * rotation.Y() * rotation.Z() + (rotation.X() * sinf(rotation.W())));
	matrix.a22(cosf(rotation.W()) + ((1.0f - cosf(rotation.W())) * powf(rotation.Z(), 2.0f)));

	return matrix;
}

void Matrix::UnifyScale()
{
	// Identify the smallest value.
	float smallest = a00();
	if (a11() < smallest)
		smallest = a11();
	if (a22() < smallest)
		smallest = a22();

	// Divide all scalars by the lowest value.
	a00(a00() / smallest);
	a01(a01() / smallest);
	a02(a02() / smallest);
	a03(a03() / smallest);
}

void Matrix::FromQuaternion(const Quaternion quaternion)
{
	// First row:
	a00(1.0f - (2.0f * powf(quaternion.Y(), 2.0f)) - (2.0f * powf(quaternion.Z(), 2.0f)));
	a01((2.0f * quaternion.X() * quaternion.Y()) - (2.0f * quaternion.Z() * quaternion.W()));
	a02((2.0f * quaternion.X() * quaternion.Z()) + (2.0f * quaternion.Y() * quaternion.W()));

	// Second row:
	a10((2.0f * quaternion.X() * quaternion.Y()) + (2.0f * quaternion.Z() * quaternion.W()));
	a11(1.0f - (2.0f * powf(quaternion.X(), 2.0f)) - (2.0f * powf(quaternion.Z(), 2.0f)));
	a12((2.0f * quaternion.Y() * quaternion.Z()) - (2.0f * quaternion.X() * quaternion.W()));

	//Third row:
	a20((2.0f * quaternion.X() * quaternion.Z()) - (2.0f * quaternion.Y() * quaternion.W()));
	a21((2.0f * quaternion.Y() * quaternion.Z()) + (2.0f * quaternion.X() * quaternion.W()));
	a22(1.0f - (2.0f * powf(quaternion.X(), 2.0f)) - (2.0f * powf(quaternion.Y(), 2.0f)));
}

Quaternion Matrix::ToQuaternion() const
{
	float w = sqrtf(1.0f + a00() + a11() + a22()) / 2.0f;
	float x = (a21() - a12()) / (4.0f * w);
	float y = (a02() - a20()) / (4.0f * w);
	float z = (a10() - a01()) / (4.0f * w);

	return Quaternion(x, y, z, w);
}

Matrix Matrix::PerspectiveViewGL(const float left, const float right, const float top, const float bottom, const float near, const float far)
{
	Matrix perspective = Identity();

	perspective.a00((2.0f * near) / (right - left));
	perspective.a02((right + left) / (right - left));
	perspective.a11((2.0f * near) / (top - bottom));
	perspective.a12((top + bottom) / (top - bottom));
	perspective.a22(-((far + near) / (far - near)));
	perspective.a23(-((2.0f * far * near) / (far - near)));
	perspective.a32(-1.0f);

	return perspective;
}

Matrix Matrix::PerspectiveViewDX(const float left, const float right, const float top, const float bottom, const float near, const float far)
{
	Matrix perspective = Identity();

	perspective.a00((2.0f * near) / (right - left));
	perspective.a02(-((right + left) / (right - left)));
	perspective.a11((2.0f * near) / (top - bottom));
	perspective.a12(-((top + bottom) / (top - bottom)));
	perspective.a22(far / (far - near));
	perspective.a23(-((far * near) / (far - near)));
	perspective.a32(1.0f);

	return perspective;
}

Matrix Matrix::OrthogonalViewGL(const float left, const float right, const float top, const float bottom, const float near, const float far)
{
	Matrix orthoView = Identity();

	// Set the diagonal.
	orthoView.a00(2.0f / (right - left));
	orthoView.a11(2.0f / (top - bottom));
	orthoView.a22(2.0f / (far - near));

	// Set the last column.
	orthoView.a03(-1.0f * ((right + left) / (right - left)));
	orthoView.a13(-1.0f * ((top + bottom) / (top - bottom)));
	orthoView.a23(-1.0f * ((far + near) / (far - near)));

	return orthoView;
}

Matrix Matrix::OrthogonalViewDX(const float left, const float right, const float top, const float bottom, const float near, const float far)
{
	Matrix orthoView = Identity();

	// Set the diagonal.
	orthoView.a00(2.0f / (right - left));
	orthoView.a11(2.0f / (top - bottom));
	orthoView.a22(1.0f / (far - near));

	// Set the last row.
	orthoView.a30(-1.0f * ((right + left) / (right - left)));
	orthoView.a31(-1.0f * ((top + bottom) / (top - bottom)));
	orthoView.a32(-1.0f * (near / (far - near)));

	return orthoView;
}

Matrix Matrix::CameraViewGL(const float left, const float right, const float top, const float bottom, const float near, const float far, const Float4 orientation, const Float4 position)
{
	Matrix view = Matrix::PerspectiveViewGL(left, right, top, bottom, near, far);
	view.Rotate(orientation);
	view.TranslateGL(position.XYZ());

	return view;
}

Matrix Matrix::CameraViewGL(const Matrix lens, const Float4 orientation, const Float4 position)
{
	Matrix view = lens;
	view.Rotate(orientation);
	view.TranslateGL(position.XYZ());

	return view;
}

Matrix Matrix::CameraViewDX(const float left, const float right, const float top, const float bottom, const float near, const float far, const Float4 orientation, const Float4 position)
{
	Matrix view = Matrix::PerspectiveViewDX(left, right, top, bottom, near, far);
	view.Rotate(orientation);
	view.TranslateGL(position.XYZ());

	return view;
}

Matrix Matrix::CameraViewDX(const Matrix lens, const Float4 orientation, const Float4 position)
{
	Matrix view = lens;
	view.Rotate(orientation);
	view.TranslateDX(position.XYZ());

	return view;
}

float Matrix::Determinant() const
{
	float determinant = 0.0f;

	/* If matrix A = |a b c d|
					 |e f g h|
					 |i j k l|
					 |m n o p|

	Then its determinant is a subset of any row or column in A and the determinant sum of the remaining 3x3 matrices.
	For example. if we take row 1, we get: determinant =  |f g h|    |e g h|	|e f h|	   |e f g|
														 a|j k l| - b|i k l| + c|i j l| - d|i j k|
														  |n o p|	 |m o p|	|m n p|	   |m n o|
	The results should be the same regardless of which row or column we choose.*/

	// a*(fkp + gln + hjo - flo - gjp - hkn)
	determinant = a00() * ((a11() * a22() * a33()) + (a12() * a23() * a31()) +
		(a13() * a21() * a32()) - (a11() * a23() * a32()) -
		(a12() * a21() * a33()) - (a13() * a22() * a31()));

	// b*(ekp + glm + hio - elo - gip - hkm)
	determinant -= a01() * ((a10() * a22() * a33()) + (a12() * a23() * a30()) +
		(a13() * a20() * a32()) - (a10() * a23() * a32()) -
		(a12() * a20() * a33()) - (a13() * a22() * a30()));

	// c*(ejp + flm + hin - eln - fip - hjm)
	determinant += a02() * ((a10() * a21() * a33()) + (a11() * a23() * a30()) +
		(a13() * a20() * a31()) - (a10() * a23() * a31()) -
		(a11() * a20() * a33()) - (a13() * a21() * a30()));

	// d*(ejo + fkm + gin - ekn - fio - gjm)
	determinant -= a03() * ((a10() * a21() * a32()) + (a11() * a22() * a30()) +
		(a12() * a20() * a31()) - (a10() * a22() * a31()) -
		(a11() * a20() * a32()) - (a12() * a21() * a30()));

	return determinant;
}

Float4 Matrix::operator*(const Float4 vector) const
{
	Float4 result;
	float element = 0.0f;
	
	// Treat the vector as a column
	for (unsigned short row = 0; row < 4; row++)
	{
		for (unsigned short col = 0; col < 4; col++)
			element += mMatrix[col + (row * 4)] * vector[col];

		result.Set(row, element);
		element = 0.0f;
	}

	return result;
}
