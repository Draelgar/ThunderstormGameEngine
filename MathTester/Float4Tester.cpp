/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-08-06
** � 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#include "Float4Tester.h"

using namespace ts::math;
using namespace std;

// A test of all constructors.
bool tester::Float4Tester::Constructors()
{
	bool success = true;

	Float4 u;
	Float4 v(1.0f);
	Float4 w(0.5f, 1.0f, 0.3f, 0.1f);

	// Test the constructors.
	if (Compare(u.X(), 0.0f) && Compare(u.Y(), 0.0f) && Compare(u.Z(), 0.0f) && Compare(u.W(), 0.0f) &&
		Compare(u[0], 0.0f) && Compare(u[1], 0.0f) && Compare(u[2], 0.0f) && Compare(u[3], 0.0f))
	{
		cout << "Default constructor passed." << endl;
	}
	else
	{
		cout << "Default constructor failed!" << endl;
		success = false;
	}

	if (Compare(v.X(), 1.0f) && Compare(v.Y(), 1.0f) && Compare(v.Z(), 1.0f) && Compare(v.W(), 1.0f) &&
		Compare(v[0], 1.0f) && Compare(v[1], 1.0f) && Compare(v[2], 1.0f) && Compare(v[2], 1.0f))
	{
		cout << "One value constructor passed." << endl;
	}
	else
	{
		cout << "One value constructor failed!" << endl;
		success = false;
	}

	if (Compare(w.X(), 0.5f) && Compare(w.Y(), 1.0f) && Compare(w.Z(), 0.3f) && Compare(w.W(), 0.1f) &&
		Compare(w[0], 0.5f) && Compare(w[1], 1.0f) && Compare(w[2], 0.3f) && Compare(w[3], 0.1f))
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
bool tester::Float4Tester::Operators()
{
	bool success = true;

	Float4 u(1.0f);
	Float4 v(0.5f);

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
	if (v == Float4())
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
bool tester::Float4Tester::LengthAndNormalization()
{
	bool success = true;

	Float4 u(1.0f);
	Float4 v(0.2f, 0.5f, 0.3f, 0.4f);

	float uLength = roundf(u.Length() * 100.0f) / 100.0f;
	float vLength = roundf(v.Length() * 100.0f) / 100.0f;

	if (Compare(uLength, 2.0f) && Compare(vLength, 0.73f))
	{
		cout << "Length calculation passed." << endl;
	}
	else
	{
		cout << "Length calculation failed!" << endl;
		success = false;
	}

	Float4 un = u.Normalized();
	Float4 vn = v.Normalized();

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
bool tester::Float4Tester::DotProduct()
{
	bool success = true;

	Float4 u(0.5f, 0.7f, 0.4f, 0.9f);
	Float4 v(0.3f, 0.9f, 0.6f, 0.2f);

	float dot = roundf(u.Dot(v) * 100.0f) / 100.0f;

	if (Compare(dot, 1.2f))
	{
		cout << "Dot product passed." << endl;
	}
	else
	{
		cout << "Dot product failed!" << endl;
		success = false;
	}

	return success;
}

// A test of the Cross product.
bool tester::Float4Tester::CrossProduct()
{
	bool success = true;

	Float4 u(0.5f, 0.7f, 0.4f, 0.2f);
	Float4 v(0.3f, 0.9f, 0.6f, 0.2f);
	Float4 w(-0.3f, 0.02f, 0.15f, -0.09f);

	if (u.Cross(v) == w)
	{
		cout << "Cross product passed." << endl;
	}
	else
	{
		cout << "Cross product failed!" << endl;
		success = false;
	}

	return success;
}

// Run the series of tests. 
bool tester::Float4Tester::RunTests()
{
	cout << "Performing tests on Float4..." << endl;

	if (!Constructors() || !Operators() || !LengthAndNormalization() || !DotProduct() || !CrossProduct())
		return false;

	cout << "All Float4 tests passed." << endl;

	return true;
}
