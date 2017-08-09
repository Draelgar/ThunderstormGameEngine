/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-08-09
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include "Matrix.h"

namespace tester
{
	/** A class for testing my matrix implementation. **/
	class MatrixTester
	{
		private:
			/** Test the transpose. **/
			bool TransposeTest();
			/** Test all overloaded operators. **/
			bool OperatorsTest();
			/** Test the determinant. **/
			bool DeterminantTest();
			/** Test the trace. **/
			bool TraceTest();
			/** Test the inverse. **/
			bool InverseTest();
			/** Test the orthonormalization. **/
			bool OrthonormalizationTest();
			/** Test the translation. **/
			bool TranslationTest();
			/** Test the rotation. **/
			bool RotationTest();
			/** Test the scaling. **/
			bool ScaleTest();
			/** Test the shearing. **/
			bool ShearTest();
			/** Test converting to and from quaternions. **/
			bool QuaternionConversionTest();
			/** Test the perspective views. **/
			bool PerspectiveViewTest();
			/** Test the camera views. **/
			bool CameraViewTest();

		public:
			/** Run all the tests. **/
			bool RunTests();
	};
}