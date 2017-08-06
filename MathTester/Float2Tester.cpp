/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-08-06
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#include "Float2Tester.h"

using namespace ts::math;
using namespace std;

// A test of all constructors.
bool tester::Float2Tester::Constructors()
{
	bool success = true;

	Float2 u;
	Float2 v(1.0f);
	Float2 w(0.5f, 1.0f);

	// Test the constructors.
	if (Compare(u.X(), 0.0f) && Compare(u.Y(), 0.0f) && Compare(u[0], 0.0f) && Compare(u[1], 0.0f))
	{
		cout << "Default constructor passed." << endl;
	}
	else
	{
		cout << "Default constructor failed!" << endl;
		success = false;
	}

	if (Compare(v.X(), 1.0f) && Compare(v.Y(), 1.0f) && Compare(v[0], 1.0f) && Compare(v[1], 1.0f))
	{
		cout << "One value constructor passed." << endl;
	}
	else
	{
		cout << "One value constructor failed!" << endl;
		success = false;
	}

	if (Compare(w.X(), 0.5f) && Compare(w.Y(), 1.0f) && Compare(w[0], 0.5f) && Compare(w[1], 1.0f))
	{
		cout << "Two values constructor passed." << endl;
	}
	else
	{
		cout << "Two values constructor failed!" << endl;
		success = false;
	}

	return success;
}

// A test of all operators.
bool tester::Float2Tester::Operators()
{
	bool success = true;

	Float2 u(1.0f);
	Float2 v(0.5f);

	if (u == u && !(u == v))
	{
		cout << "Operator == passed." << endl;
	}
	else
	{
		cout << "Operator == failed!" << endl;
		success = false;
	}

	if (u != v && !(u != u))
	{
		cout << "Operator != passed." << endl;
	}
	else
	{
		cout << "Operator != failed!" << endl;
		success = false;
	}

	if (v * 2.0f == u && 2.0f * v == u)
	{
		cout << "Operator * passed." << endl;
	}
	else
	{
		cout << "Operator * failed!" << endl;
		success = false;
	}

	if (u / 2.0f == v)
	{
		cout << "Operator / passed." << endl;
	}
	else
	{
		cout << "Operator / failed!" << endl;
		success = false;
	}

	v *= 2.0f;
	if (v == u)
	{
		cout << "Operator *= passed." << endl;
	}
	else
	{
		cout << "Operator *= failed!" << endl;
		success = false;
	}

	v /= 2.0f;
	if (v == u / 2.0f)
	{
		cout << "Operator /= passed." << endl;
	}
	else
	{
		cout << "Operator /= failed!" << endl;
		success = false;
	}

	if (v + v == u)
	{
		cout << "Operator + passed." << endl;
	}
	else
	{
		cout << "Operator + failed!" << endl;
		success = false;
	}

	if (u - v == v)
	{
		cout << "Operator - passed." << endl;
	}
	else
	{
		cout << "Operator - failed!" << endl;
		success = false;
	}

	v += v;
	if (v == u)
	{
		cout << "Operator += passed" << endl;
	}
	else
	{
		cout << "Operator += failed!" << endl;
		success = false;
	}

	v -= u;
	if (v == Float2())
	{
		cout << "Operator -= passed." << endl;
	}
	else
	{
		cout << "Operator -= failed!" << endl;
		success = false;
	}

	return success;
}

// A test of all length and normalization operations.
bool tester::Float2Tester::LengthAndNormalization()
{
	bool success = true;

	Float2 u(1.0f);
	Float2 v(0.2f, 0.5f);

	float uLength = roundf(u.Length() * 100.0f) / 100.0f;
	float vLength = roundf(v.Length() * 100.0f) / 100.0f;

	if (Compare(uLength, 1.41f) && Compare(vLength, 0.54f))
	{
		cout << "Length calculation passed." << endl;
	}
	else
	{
		cout << "Length calculation failed!" << endl;
		success = false;
	}

	Float2 un = u.Normalized();
	Float2 vn = v.Normalized();

	float uNormLength = roundf(u.Normalize() * 100.0f) / 100.0f;
	float vNormLength = roundf(v.Normalize() * 100.0f) / 100.0f;
	
	if (Compare(uNormLength, uLength) && Compare(vNormLength, vLength))
	{
		cout << "Normalize length passed." << endl;
	}
	else
	{
		cout << "Normalize length failed!" << endl;
		success = false;
	}

	if (u == un && v == vn)
	{
		cout << "Normalization passed." << endl;
	}
	else
	{
		cout << "Normalization failed!" << endl;
		success = false;
	}

	return success;
}

// A test of the Dot product.
bool tester::Float2Tester::DotProduct()
{
	bool success = true;

	Float2 u(0.5f, 0.7f);
	Float2 v(0.3f, 0.9f);

	float dot = roundf(u.Dot(v) * 100.0f) / 100.0f;

	if (Compare(dot, 0.78f))
	{
		cout << "Dot product passed." << endl;
	}
	else
	{
		cout << "Dot product failed!" << endl;
		success == false;
	}

	return success;
}

// Run the series of tests. 
bool tester::Float2Tester::RunTests()
{
	cout << "Performing tests on Float2..." << endl;

	if(!Constructors() || !Operators() || !LengthAndNormalization() || !DotProduct())
		return false;

	cout << "All Float2 tests passed." << endl;

	return true;
}
