/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
****************************************************************/
#pragma once

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <d3d11.h>
#include <directxmath.h>

#include "stdafx.h"

namespace ts
{
	namespace graphics
	{
		class DX3D11Renderer
		{
		private:
			bool mVsync_enabled;
			int mVideoCardMemory;
			char mVideoCardDescription[128];
			IDXGISwapChain* mSwapChainPtr;
			ID3D11Device* mDevicePtr;
			ID3D11DeviceContext* mDeviceContextPtr;
			ID3D11RenderTargetView* mRenderTargetViewPtr;
			ID3D11Texture2D* mDepthStencilBufferPtr;
			ID3D11DepthStencilState* mDepthStencilStatePtr;
			ID3D11DepthStencilView* mDepthStencilViewPtr;
			ID3D11RasterizerState* mRasterStatePtr;
			DirectX::XMMATRIX mProjectionMatrix;
			DirectX::XMMATRIX mWorldMatrix;
			DirectX::XMMATRIX mOrthoMatrix;

			int mWinSize[2];

		public:
			DX3D11Renderer();
			bool Initialize(int, int, bool, HWND, bool, float, float);
			void Shutdown();

			void BeginScene(float, float, float, float);
			void EndScene();

			ID3D11Device* GetDevice();
			ID3D11DeviceContext* GetDeviceContext();

			void GetProjectionMatrix(DirectX::XMMATRIX&);
			void GetWorldMatrix(DirectX::XMMATRIX&);
			void GetOrthoMatrix(DirectX::XMMATRIX&);

			void GetVideoCardInfo(char*, int&);
		};
	}
}
