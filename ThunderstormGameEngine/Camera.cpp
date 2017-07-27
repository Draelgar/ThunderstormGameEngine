/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
****************************************************************/

#include "stdafx.h"
#include "Camera.h"

using namespace ts::graphics;
using namespace DirectX;

Camera::Camera()
{
	mUpVec.x = 0.0f;
	mUpVec.y = 1.0f;
	mUpVec.z = 0.0f;

	mLookAtVec.x = 0.0f;
	mLookAtVec.y = 0.0f;
	mLookAtVec.z = 1.0f;
}

void Camera::UpdateViewMatrix(DirectX::XMMATRIX transformMatrix)
{
	XMVECTOR rotQuat, upVector, positionVector, lookAtVector, scaleVector;
	XMMATRIX rotationMatrix;

	(void)XMMatrixDecompose(&scaleVector, &rotQuat, &positionVector, transformMatrix);

	// Load it into a XMVECTOR structure.
	upVector = XMLoadFloat3(&mUpVec);

	// Load it into a XMVECTOR structure.
	lookAtVector = XMLoadFloat3(&mLookAtVec);

	// Create the rotation matrix from the yaw, pitch, and roll values.
	rotationMatrix = XMMatrixRotationQuaternion(rotQuat);

	// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
	lookAtVector = XMVector3TransformCoord(lookAtVector, rotationMatrix);
	upVector = XMVector3TransformCoord(upVector, rotationMatrix);

	// Translate the rotated camera position to the location of the viewer.
	lookAtVector = XMVectorAdd(positionVector, lookAtVector);

	// Finally create the view matrix from the three updated vectors.
	mViewMatrix = XMMatrixLookAtLH(positionVector, lookAtVector, upVector);
}

void Camera::GetViewMatrix(DirectX::XMMATRIX & viewMatrix)
{
	viewMatrix = mViewMatrix;
}
