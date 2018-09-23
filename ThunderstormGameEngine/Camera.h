/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
****************************************************************/
#pragma once

#include "Matrix.h"

namespace ts
{
	namespace graphics
	{
		/** This class represents a camera for the scene. **/
		class Camera
		{
		private:
			math::Matrix mViewMatrix;

		public:
			/** Setup a camera with a basic orthogonal view matrix. **/
			Camera();
			/** Setup a camera with the given view matrix. **/
			Camera(const math::Matrix viewMatrix);

			/** Set the camera view matrix directly **/
			void SetViewMatrix(const math::Matrix viewMatrix);

			/** Setup a camera with a perspective view matrix.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing a perspective view projection.**/
			void SetupPerspectiveViewGL(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane);
			/** Setup a camera with a perspective view matrix.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing a perspective view projection.**/
			void SetupPerspectiveView(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane);
			/** Setup a camera with an orthogonal view matrix for openGL.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing an orthogonal view projection. **/
			void SetupOrthogonalViewGL(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane);
			/** Setup a camera with an orthogonal view matrix for direct3D.
			*	\param left -The left plane.
			*	\param right -The right plane.
			*	\param top -The top plane.
			*	\param bottom -The bottom plane.
			*	\param near -The near plane.
			*	\param far -The far plane.
			*	\return A matrix representing an orthogonal view projection. **/
			void SetupOrthogonalView(const float left, const float right, const float top, const float bottom, const float nearPlane, const float farPlane);

			/** Get the view matrix of the camera. **/
			math::Matrix GetViewMatrix() const;
		};
	}
}