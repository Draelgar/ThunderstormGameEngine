// MathTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

#include <iostream>

using namespace ts::math;
using namespace std;

int main()
{
	Matrix matrix = Matrix::Identity();
	cout << matrix.Determinant() << endl;
	matrix.Rotate(Float4(Float3(0.1f, 0.6f, 0.3f).Normalized(), 1.5f));

	matrix.TranslateGL(Float3(5.0f, 6.0f, 0.1f));
	matrix = matrix * matrix;
	matrix = matrix * matrix;
	matrix = matrix * matrix;
	matrix = matrix * matrix;

	// Roundup errors here and onwards! Check determinant every 5 multiplications.
	matrix = matrix * matrix;
	matrix = matrix * matrix;
	matrix = matrix * matrix;
	matrix = matrix * matrix;
	matrix = matrix * matrix;
	matrix = matrix * matrix;

	matrix.Orthonormalize();

	cout << matrix.Determinant() << endl;

	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			cout << matrix.Get(i, j) << ", ";
		}

		cout << endl;
	}

    return 0;
}

