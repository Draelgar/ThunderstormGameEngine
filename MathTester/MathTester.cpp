// MathTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

#include "Float2Tester.h"
#include "Float3Tester.h"
#include "Float4Tester.h"

#include <iostream>

using namespace tester;
using namespace ts::math;
using namespace std;

int main()
{
	unsigned int passed = 0;
	unsigned int failed = 0;

	Float2Tester float2Tester;
	Float3Tester float3Tester;
	Float4Tester float4Tester;

	if (float2Tester.RunTests())
		passed++;
	else
		failed++;

	cout << "-----------------------------------------------" << endl;

	if (float3Tester.RunTests())
		passed++;
	else
		failed++;

	cout << "-----------------------------------------------" << endl;

	if (float4Tester.RunTests())
		passed++;
	else
		failed++;

	cout << "-----------------------------------------------\nTests Passed: " << 
		passed << "\nTests Failed: " << failed << endl;

	system("pause");
    return 0;
}

