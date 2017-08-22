/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-09
****************************************************************/
#pragma once
#include "BaseGeometry.h"

#include <d3d11.h>
#include "Float4.h"

namespace ts
{
	namespace graphics
	{
		/** This class defines a geometry of indexed and coloured vertices. **/
		class GeometryIndexedColour : public BaseGeometry
		{
		private:
			struct VertexType
			{
				math::Float3 position;
				math::Float4 color;
			};

			ID3D11Buffer *mVertexBuffer, *mIndexBuffer;
			int mVertexCount, mIndexCount;

		private:
			bool InitializeBuffers(ID3D11Device* device);
			void ShutdownBuffers();
			void RenderBuffers(ID3D11DeviceContext* devCon);

		public:
			GeometryIndexedColour();
			~GeometryIndexedColour();

			bool Initialize(ID3D11Device* device);
			void Shutdown();
			void Render(ID3D11DeviceContext* devCon);

			int GetIndexCount();
		};
	}
}