// MathTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

#include <iostream>

using namespace ts::math;
using namespace std;

// TODO: Test the new comparer for all vectors and make sure to swap all float comparrisions to the function below!
bool compare(const float a, const float b)
{
	const float limit = 1.0e-07f;
	return fabsf(a - b) < limit;
}

bool Float2Test()
{
	cout << "Begining tests of Float2." << endl;

	Float2 u;
	Float2 v(1.0f);
	Float2 w(0.5f, 1.0f);

	unsigned int testsCompleted = 0;
	unsigned int numTests = 13;

	// Test the constructors.
	if (u.X() == 0.0f && u.Y() == 0.0f && u[0] == 0.0f && u[1] == 0.0f)
	{
		testsCompleted++;
		cout << "Default constructor works." << endl;
	}
	else return false;
	if (v.X() == 1.0f && v.Y() == 1.0f && v[0] == 1.0f && v[1] == 1.0f)
	{
		testsCompleted++;
		cout << "One value constructor works." << endl;
	}
	else return false;
	if (w.X() == 0.5f && w.Y() == 1.0f && w[0] == 0.5f && w[1] == 1.0f)
	{
		testsCompleted++;
		cout << "Two values constructor works & getters works." << endl;
	}
	else return false;

	// Test setters.
	u.set(0, 0.3f);
	u.set(1, 0.5f);
	if (u.X() == 0.3f && u.Y() == 0.5f && u[0] == 0.3f && u[1] == 0.5f)
	{
		testsCompleted++;
		cout << "Set via array index works." << endl;
	}
	else return false;

	v.X(0.7f);
	v.Y(0.3f);
	if (v.X() == 0.7f && v.Y() == 0.3f && v[0] == 0.7f && v[1] == 0.3f)
	{
		testsCompleted++;
		cout << "Set components directly works." << endl;
	}
	else return false;
	
	// Test length.
	w.set(4.0f);
	float wLength = roundf(w.Length() * 100.0f) / 100.0f;
	float uLength = roundf(u.Length() * 100.0f) / 100.0f;
	float vLength = roundf(v.Length() * 100.0f) / 100.0f;

	if (wLength == 5.66f && uLength == 0.58f && vLength == 0.76f)
	{
		testsCompleted++;
		cout << "Length calculation is correct." << endl;
	}
	else return false;

	// Test multiplication by scalar.
	w = w * 2.0f;
	if (w.X() == 8.0f && w.Y() == 8.0f)
	{
		testsCompleted++;
		cout << "Correctly handles multiplication by right hand scalar." << endl;
	}
	else return false;

	w = 0.25f * w;
	if (w.X() == 2.0f && w.Y() == 2.0f)
	{
		testsCompleted++;
		cout << "Correctly handles multiplication by left hand scalar." << endl;
	}
	else return false;

	// Test division by scalar.
	w = w / 2.0f;
	if (w.X() == 1.0f && w.Y() == 1.0f)
	{
		testsCompleted++;
		cout << "Correctly handles division by scalar." << endl;
	}
	else return false;

	// Test addition.
	w = v + u;
	if (w.X() == 1.0f && w.Y() == 0.8f)
	{
		testsCompleted++;
		cout << "Correctly handles addition." << endl;
	}
	else return false;

	// Test subtraction.
	w = w - v;
	if (w.X() == 0.3f && w.Y() == 0.5f)
	{
		testsCompleted++;
		cout << "Correctly handles subtraction." << endl;
	}
	else return false;

	// Test normalization.
	w.Normalize();
	v.Normalize();
	u = u.Normalized();

	uLength = roundf(u.Length() * 1000.0f) / 1000.0f;
	vLength = roundf(v.Length() * 1000.0f) / 1000.0f;
	wLength = roundf(w.Length() * 1000.0f) / 1000.0f;

	if (uLength == 1.0f && vLength == 1.0f && wLength == 1.0f)
	{
		testsCompleted++;
		cout << "Correctly handles normalization." << endl;
	}
	else return false;

	u.X(1.0f);
	u.Y(0.5f);
	v.X(0.3f);
	v.Y(0.8f);
	// Test dot product.
	float dot = roundf(u.Dot(v) * 100.0f) / 100.0f;
	if (dot == 0.7f)
	{
		testsCompleted++;
		cout << "Dot product works." << endl;
	}
	else return false;


	cout << testsCompleted << " out of " << numTests << " tests of Float2 completed." << endl;
	return true;
}

bool Float3Test()
{
	cout << "Begining tests of Float3." << endl;

	Float3 u;
	Float3 v(1.0f);
	Float3 w(0.5f, 1.0f, 0.5f);

	unsigned int testsCompleted = 0;
	unsigned int numTests = 13;

	// Test the constructors.
	if (u.X() == 0.0f && u.Y() == 0.0f && u[0] == 0.0f && u[1] == 0.0f && u.Z() == 0.0f && u[2] == 0.0f)
	{
		testsCompleted++;
		cout << "Default constructor works." << endl;
	}
	else return false;
	if (v.X() == 1.0f && v.Y() == 1.0f && v[0] == 1.0f && v[1] == 1.0f && v.Z() == 1.0f && v[2] == 1.0f)
	{
		testsCompleted++;
		cout << "One value constructor works." << endl;
	}
	else return false;
	if (w.X() == 0.5f && w.Y() == 1.0f && w[0] == 0.5f && w[1] == 1.0f && w.Z() == 0.5f, w[2] == 0.5f)
	{
		testsCompleted++;
		cout << "Two values constructor works & getters works." << endl;
	}
	else return false;

	// Test setters.
	u.set(0, 0.3f);
	u.set(1, 0.5f);
	u.set(2, 0.2f);
	if (u.X() == 0.3f && u.Y() == 0.5f && u[0] == 0.3f && u[1] == 0.5f && u.Z() == 0.2f && u[2] == 0.2f)
	{
		testsCompleted++;
		cout << "Set via array index works." << endl;
	}
	else return false;

	v.X(0.7f);
	v.Y(0.3f);
	v.Z(0.5f);
	if (v.X() == 0.7f && v.Y() == 0.3f && v[0] == 0.7f && v[1] == 0.3f && v.Z() == 0.5f && v[2] == 0.5f)
	{
		testsCompleted++;
		cout << "Set components directly works." << endl;
	}
	else return false;

	// Test length.
	w.set(4.0f);
	float wLength = roundf(w.Length() * 100.0f) / 100.0f;
	float uLength = roundf(u.Length() * 100.0f) / 100.0f;
	float vLength = roundf(v.Length() * 100.0f) / 100.0f;

	if (wLength == 6.93f && uLength == 0.62f && vLength == 0.91f)
	{
		testsCompleted++;
		cout << "Length calculation is correct." << endl;
	}
	else return false;

	// Test multiplication by scalar.
	w = w * 2.0f;
	if (w.X() == 8.0f && w.Y() == 8.0f && w.Z() == 8.0f)
	{
		testsCompleted++;
		cout << "Correctly handles multiplication by right hand scalar." << endl;
	}
	else return false;

	w = 0.25f * w;
	if (w.X() == 2.0f && w.Y() == 2.0f && w.Z() == 2.0f)
	{
		testsCompleted++;
		cout << "Correctly handles multiplication by left hand scalar." << endl;
	}
	else return false;

	// Test division by scalar.
	w = w / 2.0f;
	if (w.X() == 1.0f && w.Y() == 1.0f && w.Z() == 1.0f)
	{
		testsCompleted++;
		cout << "Correctly handles division by scalar." << endl;
	}
	else return false;

	// Test addition.
	w = v + u;
	if (w.X() == 1.0f && w.Y() == 0.8f && w.Z() == 0.7f)
	{
		testsCompleted++;
		cout << "Correctly handles addition." << endl;
	}
	else return false;

	// Test subtraction.
	w = w - v;
	if (w.X() == 0.3f && w.Y() == 0.5f && w.Z() == 0.2f)
	{
		testsCompleted++;
		cout << "Correctly handles subtraction." << endl;
	}
	else return false;

	// Test normalization.
	w.Normalize();
	v.Normalize();
	u = u.Normalized();

	uLength = roundf(u.Length() * 1000.0f) / 1000.0f;
	vLength = roundf(v.Length() * 1000.0f) / 1000.0f;
	wLength = roundf(w.Length() * 1000.0f) / 1000.0f;

	if (uLength == 1.0f && vLength == 1.0f && wLength == 1.0f)
	{
		testsCompleted++;
		cout << "Correctly handles normalization." << endl;
	}
	else return false;

	u.X(1.0f);
	u.Y(0.5f);
	u.Z(0.7f);
	v.X(0.3f);
	v.Y(0.8f);
	v.Z(0.2f);
	// Test dot product.
	float dot = roundf(u.Dot(v) * 100.0f) / 100.0f;
	if (dot == 0.84f)
	{
		testsCompleted++;
		cout << "Dot product works." << endl;
	}
	else return false;


	cout << testsCompleted << " out of " << numTests << " tests of Float3 completed." << endl;
	return true;
}

bool Float4Test()
{
	return true;
}

int main()
{
	unsigned int success = 0;
	unsigned int failure = 0;

	if (Float2Test())
		success++;
	else
		failure++;

	cout << endl;

	if (Float3Test())
		success++;
	else
		failure++;

	cout << endl;

	if (Float4Test())
		success++;
	else
		failure++;

	cout << endl;
	cout << success << " feature tests succeeded, " << failure << " failed." << endl;
	cout << endl;
	system("pause");
    return 0;
}

