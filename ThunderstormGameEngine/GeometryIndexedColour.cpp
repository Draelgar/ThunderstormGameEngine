/***************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-02-09
****************************************************************/

#include "stdafx.h"
#include "GeometryIndexedColour.h"

using namespace ts::graphics;
using namespace ts::math;
using namespace DirectX;

bool GeometryIndexedColour::InitializeBuffers(ID3D11Device * device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;

	// Set the number of vertices in the vertex array.
	mVertexCount = 3;

	// Set the number of indices in the index array.
	mIndexCount = 3;

	// Create the vertex array.
	vertices = new VertexType[mVertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[mIndexCount];
	if (!indices)
	{
		return false;
	}

	// Load the vertex array with data.
	vertices[0].position = Float3(-1.0f, -1.0f, 0.0f);  // Bottom left.
	vertices[0].color = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[1].position = Float3(0.0f, 1.0f, 0.0f);  // Top middle.
	vertices[1].color = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[2].position = Float3(1.0f, -1.0f, 0.0f);  // Bottom right.
	vertices[2].color = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	// Load the index array with data.
	indices[0] = 0;  // Bottom left.
	indices[1] = 1;  // Top middle.
	indices[2] = 2;  // Bottom right

					 // Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * mVertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &mVertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * mIndexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &mIndexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}

void GeometryIndexedColour::ShutdownBuffers()
{

	// Release the index buffer.
	if (mIndexBuffer)
	{
		mIndexBuffer->Release();
		mIndexBuffer = NULL;
	}

	// Release the vertex buffer.
	if (mVertexBuffer)
	{
		mVertexBuffer->Release();
		mVertexBuffer = NULL;
	}
}

void GeometryIndexedColour::RenderBuffers(ID3D11DeviceContext * devCon)
{
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	devCon->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	devCon->IASetIndexBuffer(mIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	devCon->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

GeometryIndexedColour::GeometryIndexedColour()
{
	mVertexBuffer = NULL;
	mIndexBuffer = NULL;
}

GeometryIndexedColour::~GeometryIndexedColour()
{

}

bool GeometryIndexedColour::Initialize(ID3D11Device * device)
{
	// Initialize the vertex and index buffers.
	if (!InitializeBuffers(device))
	{
		return false;
	}

	return true;
}

void GeometryIndexedColour::Shutdown()
{
	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	return;
}

void GeometryIndexedColour::Render(ID3D11DeviceContext * devCon)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(devCon);

	return;
}

int GeometryIndexedColour::GetIndexCount()
{
	return mIndexCount;
}
