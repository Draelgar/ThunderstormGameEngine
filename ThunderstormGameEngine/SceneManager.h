/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-08
****************************************************************/
#pragma once

#include "GraphicsManager.h"

namespace ts
{
	namespace scene
	{
		class SceneManager
		{
		private:
			graphics::GraphicsManager mGraphicsMng;

		public:
			SceneManager();

			bool Initialize(int iWidth, int iHeight, HWND iHwnd);
			void Shutdown();
			bool Frame();
		};
	}
}