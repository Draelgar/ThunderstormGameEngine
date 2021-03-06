/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
****************************************************************/
#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <fstream>

namespace ts
{
	namespace graphics
	{
		/** This class is intended as the base class for various shader programs. **/
		class Shader
		{
		private:
			struct MatrixBufferType
			{
				DirectX::XMMATRIX world;
				DirectX::XMMATRIX view;
				DirectX::XMMATRIX projection;
			};

			ID3D11VertexShader* m_vertexShader;
			ID3D11PixelShader* m_pixelShader;
			ID3D11InputLayout* m_layout;
			ID3D11Buffer* m_matrixBuffer;

		private:
			bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
			void ShutdownShader();
			void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

			bool SetShaderParameters(ID3D11DeviceContext*, DirectX::XMMATRIX, DirectX::XMMATRIX, DirectX::XMMATRIX);
			void RenderShader(ID3D11DeviceContext*, int);

		public:
			Shader();
			Shader(const Shader&);
			~Shader();

			bool Initialize(ID3D11Device*, HWND);
			void Shutdown();
			bool Render(ID3D11DeviceContext*, int, DirectX::XMMATRIX, DirectX::XMMATRIX, DirectX::XMMATRIX);

		};
	}
}