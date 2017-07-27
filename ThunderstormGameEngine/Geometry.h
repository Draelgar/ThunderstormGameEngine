/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
****************************************************************/
#pragma once
#include <d3d11.h>
#include <directxmath.h>

namespace ts
{
	namespace graphics
	{
		/** This class is intended as base class for different types of geometries. **/
		class Geometry
		{
		private:
			struct VertexType
			{
				DirectX::XMFLOAT3 position;
				DirectX::XMFLOAT4 color;
			};

			ID3D11Buffer *mVertexBuffer, *mIndexBuffer;
			int mVertexCount, mIndexCount;

		private:
			bool InitializeBuffers(ID3D11Device* device);
			void ShutdownBuffers();
			void RenderBuffers(ID3D11DeviceContext* devCon);

		public:
			Geometry();
			Geometry(const Geometry& geometry);
			~Geometry();

			bool Initialize(ID3D11Device* device);
			void Shutdown();
			void Render(ID3D11DeviceContext* devCon);

			int GetIndexCount();
		};
	}
}