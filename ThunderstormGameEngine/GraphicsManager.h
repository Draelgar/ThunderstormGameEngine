/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-08
****************************************************************/
#pragma once

#include "DX3D11Renderer.h"
#include "Camera.h"
#include "Geometry.h"
#include "Shader.h"

namespace ts
{
	namespace graphics
	{
		class GraphicsManager
		{
		private:
			bool mFullscreen;
			bool mVSyncEnabled;
			float mViewFarPlane;
			float mViewNearPlane;

			DX3D11Renderer mDX3D11Rend;
			std::unique_ptr<Camera> mCamera;
			std::unique_ptr<Geometry> mGeometry;
			std::unique_ptr<Shader> mShader;

		private:
			bool Render();

		public:
			GraphicsManager();

			bool Initialize(int iWidth, int iHeight, HWND iHwnd);
			void Shutdown();
			bool Frame();
		};
	}
}