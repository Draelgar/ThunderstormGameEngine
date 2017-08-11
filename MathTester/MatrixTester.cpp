/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-08-09
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#include "MatrixTester.h"
#include <iostream>

using namespace ts::math;
using namespace std;

bool tester::MatrixTester::TransposeTest()
{
	bool success = true;
	Matrix identity = Matrix::Identity();

	Matrix matrixA(1.0f, 2.0f, 3.0f, 4.0f,
					0.0f, 1.0f, 2.0f, 3.0f,
					0.0f, 0.0f, 1.0f, 2.0f,
					0.0f, 0.0f, 0.0f, 1.0f);

	Matrix matrixB(1.0f, 0.0f, 0.0f, 0.0f,
					2.0f, 1.0f, 0.0f, 0.0f,
					3.0f, 2.0f, 1.0f, 0.0f,
					4.0f, 3.0f, 2.0f, 1.0f);
	
	matrixA.Transpose();

	// Was the transpose of the identity matrix unchanged?
	if (identity.GetTranspose() == identity && matrixA == matrixB)
	{
		cout << "The transpose passed." << endl;
	}
	else
	{
		cout << "The transpose failed!" << endl;
		success = false;
	}

	return success;
}

bool tester::MatrixTester::OperatorsTest()
{
	bool success = true;

	Matrix identity = Matrix::Identity();
	Matrix matrixA(1.0f, 0.5f, 0.5f, 0.0f,
					0.5f, 1.0f, 0.5f, 0.0f,
					0.5f, 0.5f, 1.0f, 0.0f,
					5.0f, 3.0f, 7.0f, 1.0f);

	Matrix matrixB(1.0f, 0.3f, 0.4f, 0.0f,
					0.5f, 1.0f, 0.7f, 0.0f,
					0.1f, 0.6f, 1.0f, 0.0f,
					3.0f, 1.0f, 8.0f, 1.0f);

	Matrix matrixC(1.3f, 1.1f, 1.25f, 0.0f,
					1.05f, 1.45f, 1.4f, 0.0f,
					0.85f, 1.25f, 1.55f, 0.0f,
					10.2f, 9.7f, 19.1f, 1.0f);

	Matrix sum1 = identity * identity;
	Matrix sum2 = matrixA * matrixB;

	if (sum1 == identity && sum2 == matrixC)
	{
		cout << "Matrix - matrix multiplication passed." << endl;
	}
	else
	{
		cout << "Matrix - matrix multiplication failed!" << endl;
		success = false;
	}

	sum1 = matrixA - matrixB;
	Matrix matrixD(0.0f, 0.2f, 0.1f, 0.0f,
					0.0f, 0.0f, -0.2f, 0.0f,
					0.4f, -0.1f, 0.0f, 0.0f,
					2.0f, 2.0f, -1.0f, 0.0f);

	if (sum1 == matrixD)
	{
		cout << "Matrix - matrix subtraction passed." << endl;
	}
	else
	{
		cout << "Matrix - matrix subtraction failed!" << endl;
		success = false;
	}

	sum1 = matrixD + matrixB;
	if (sum1 == matrixA)
	{
		cout << "Matrix - matrix addition passed." << endl;
	}
	else
	{
		cout << "Matrix - matrix addition failed!" << endl;
		success = false;
	}

	Float4 vector(1.0f, 0.5f, 0.3f, 0.2f);
	Float4 sum5 = matrixB * vector;
	Float4 expected(1.27f, 1.21f, 0.7f, 6.1f);

	if (sum5 == expected)
	{
		cout << "Matrix - vector multiplication passed." << endl;
	}
	else
	{
		cout << "Matrix - vector multiplication failed!" << endl;
		success = false;
	}

	sum1 = matrixB * 2.0f;
	sum2 = 2.0f * matrixB;
	Matrix matrixE(2.0f, 0.6f, 0.8f, 0.0f,
					1.0f, 2.0f, 1.4f, 0.0f,
					0.2f, 1.2f, 2.0f, 0.0f,
					6.0f, 2.0f, 16.0f, 2.0f);

	if (sum1 == sum2 && sum1 == matrixE)
	{
		cout << "Matrix - scalar multiplication passed." << endl;
	}
	else
	{
		cout << "Matrix - scalar multiplication failed!" << endl;
		success = false;
	}

	sum1 = matrixE / 2.0f;
	if (sum1 == matrixB)
	{
		cout << "Matrix - scalar division passed." << endl;
	}
	else
	{
		cout << "Matrix - scalar division failed!" << endl;
		success = false;
	}

	return success;
}

bool tester::MatrixTester::DeterminantTest()
{
	bool success = true;

	Matrix matrixB(1.0f, 0.3f, 0.4f, 0.0f,
					0.5f, 1.0f, 0.7f, 0.0f,
					0.1f, 0.6f, 1.0f, 0.0f,
					3.0f, 1.0f, 8.0f, 1.0f);

	float determinant = matrixB.Determinant();
	float expected = 0.531f;

	if (fabsf(determinant - expected) < MATH_FLOAT_PRECISION)
	{
		cout << "Determinant passed." << endl;
	}
	else
	{
		cout << "Determinant failed!" << endl;
		success = false;
	}

	return success;
}

bool tester::MatrixTester::TraceTest()
{
	bool success = true;
	cout << "Trace Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::InverseTest()
{
	bool success = true;
	cout << "Inverse Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::OrthonormalizationTest()
{
	bool success = true;
	cout << "Orthonormalize Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::TranslationTest()
{
	bool success = true;
	Matrix translationMatrix = Matrix::Identity();
	translationMatrix.E30(3.0f);
	translationMatrix.E31(6.0f);
	translationMatrix.E32(1.0f);

	Matrix identity = Matrix::Identity();
	identity.TranslateGL(Float3(3.0f, 6.0f, 1.0f));

	if (identity == translationMatrix && Matrix::TranslationGL(Float3(3.0f, 6.0f, 1.0f)) == translationMatrix)
	{
		cout << "Translation passed." << endl;
	}
	else
	{
		cout << "Translation failed!" << endl;
		success = false;
	}

	return success;
}

bool tester::MatrixTester::RotationTest()
{
	bool success = true;
	cout << "Rotation Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::ScaleTest()
{
	bool success = true;
	cout << "Scale Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::ShearTest()
{
	bool success = true;
	cout << "Shear Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::QuaternionConversionTest()
{
	bool success = true;
	cout << "Quaternion conversion Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::PerspectiveViewTest()
{
	bool success = true;
	cout << "Perspective view Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::CameraViewTest()
{
	bool success = true;
	cout << "Camera view Test not created yet!" << endl;
	return success;
}

bool tester::MatrixTester::RunTests()
{
	if(!TransposeTest() || !OperatorsTest() || !DeterminantTest() || !TraceTest() ||
		!InverseTest() || !OrthonormalizationTest() || !TranslationTest() || !RotationTest() ||
		!ScaleTest() || !ShearTest() || !QuaternionConversionTest() || !PerspectiveViewTest() ||
		!CameraViewTest())
		return false;
	
	return true;
}
