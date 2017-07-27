#include "Quaternion.h"

using namespace ts::math;

Quaternion Quaternion::operator*(const Quaternion quaternion) const
{
	Float3 imaginaryOther = quaternion.Imaginary();
	Float3 imaginaryOwn = Imaginary();

	float realOther = quaternion.Real();
	float realOwn = Real();

	Float3 imaginaryPart = imaginaryOwn.Cross(imaginaryOther);
	imaginaryPart += imaginaryOwn * realOther;
	imaginaryPart += imaginaryOther * realOwn;

	float realPart = (realOwn * realOther) - imaginaryOwn.Dot(imaginaryOther);

	Quaternion result(imaginaryPart, realPart);

	return result;
}

void Quaternion::operator*=(const Quaternion quaternion)
{
	Float3 imaginaryOther = quaternion.XYZ();
	Float3 imaginaryOwn = XYZ();

	float realOther = quaternion.W();
	float realOwn = W();

	Imaginary(imaginaryOwn.Cross(imaginaryOther) + (imaginaryOwn * realOther) + (imaginaryOther * realOwn));
	Real((realOwn * realOther) - imaginaryOwn.Dot(imaginaryOther));
}
