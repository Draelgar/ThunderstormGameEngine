/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-08-06
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include <iostream>

#include "Float2.h"

namespace tester
{
	/** A simple class for testing the Float2 vector class. **/
	class Float2Tester
	{
		private:

			/** A function used to compare two floating-point values. **/
			inline bool Compare(float a, float b)
			{
				return fabsf(a - b) < MATH_FLOAT_PRECISION;
			};

			/** A test of all constructors. **/
			bool Constructors();

			/** A test of all operators. **/
			bool Operators();

			/** A test of all length and normalization operations. **/
			bool LengthAndNormalization();

			/** A test of the Dot product. **/
			bool DotProduct();

		public:
			/** Run the series of tests. 
			**	@return True if all tests where passed, otherwise false.**/
			bool RunTests();
	};
}
