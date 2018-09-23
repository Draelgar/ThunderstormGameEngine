/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
****************************************************************/

#include "stdafx.h"
#include "Camera.h"

using namespace ts::graphics;
using namespace ts;

Camera::Camera()
{
	mViewMatrix = math::Matrix::OrthogonalViewDX(1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 1.0f);
}

Camera::Camera(const math::Matrix viewMatrix)
{
	mViewMatrix = viewMatrix;
}

void Camera::SetViewMatrix(const math::Matrix viewMatrix)
{
	mViewMatrix = viewMatrix;
}

void ts::graphics::Camera::SetupPerspectiveViewGL(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane)
{
	mViewMatrix = math::Matrix::PerspectiveViewGL(left, right, top, bottom, nearPlane, farPlane);
}

void ts::graphics::Camera::SetupPerspectiveView(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane)
{
	mViewMatrix = math::Matrix::PerspectiveViewDX(left, right, top, bottom, nearPlane, farPlane);
}

void ts::graphics::Camera::SetupOrthogonalViewGL(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane)
{
	mViewMatrix = math::Matrix::OrthogonalViewGL(left, right, top, bottom, nearPlane, farPlane);
}

void ts::graphics::Camera::SetupOrthogonalView(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane)
{
	mViewMatrix = math::Matrix::OrthogonalViewDX(left, right, top, bottom, nearPlane, farPlane);
}

ts::math::Matrix Camera::GetViewMatrix() const
{
	return mViewMatrix;
}
