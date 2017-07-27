/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
****************************************************************/
#pragma once

#include <directxmath.h>

namespace ts
{
	namespace graphics
	{
		/** This class represents a camera for the scene. **/
		class Camera
		{
		private:
			DirectX::XMFLOAT3 mUpVec;
			DirectX::XMFLOAT3 mLookAtVec;

			DirectX::XMMATRIX mViewMatrix;

		public:
			Camera();

			void UpdateViewMatrix(DirectX::XMMATRIX transformMatrix);
			void GetViewMatrix(DirectX::XMMATRIX&);
		};
	}
}