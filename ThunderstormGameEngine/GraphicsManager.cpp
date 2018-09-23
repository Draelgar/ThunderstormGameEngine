/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-08
****************************************************************/
#include "stdafx.h"
#include "GraphicsManager.h"

using namespace DirectX;
using namespace ts::graphics;

bool GraphicsManager::Render()
{
	/*XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;

	// Clear the buffers to begin the scene.
	mDX3D11Rend.BeginScene(0.4f, 0.4f, 0.8f, 1.0f);

	// Generate the view matrix based on the camera's position.
	XMMATRIX transform = DirectX::XMMatrixTranslation(0.0f, 0.0f, -5.0f);

	mCamera->UpdateViewMatrix(transform);

	// Get the world, view, and projection matrices from the camera and d3d objects.
	mDX3D11Rend.GetWorldMatrix(worldMatrix);
	mCamera->GetViewMatrix(viewMatrix);
	mDX3D11Rend.GetProjectionMatrix(projectionMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	mGeometry->Render(mDX3D11Rend.GetDeviceContext());

	// Render the model using the color shader.
	result = mShader->Render(mDX3D11Rend.GetDeviceContext(), mGeometry->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	mDX3D11Rend.EndScene();*/

	return true;
}

GraphicsManager::GraphicsManager()
{
	mFullscreen = false;
	mVSyncEnabled = true;
	mViewFarPlane = 1000.0f;
	mViewNearPlane = 0.1f;

	mGeometry = NULL;
	mCamera = NULL;
	mShader = NULL;
}

bool GraphicsManager::Initialize(int iWidth, int iHeight, HWND iHwnd)
{
	bool result;

	// Initialize the Direct3D object.
	result = mDX3D11Rend.Initialize(iWidth, iHeight, mVSyncEnabled, iHwnd, mFullscreen, mViewFarPlane, mViewNearPlane);
	if (!result)
	{
		MessageBox(iHwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	mCamera = std::unique_ptr<Camera>(new Camera);
	if (!mCamera)
	{
		return false;
	}

	// Create the model object.
	mGeometry = std::unique_ptr<GeometryIndexedColour>(new GeometryIndexedColour);
	if(!mGeometry)
	{
		return false;
	}

	// Initialize the model object.
	if (!mGeometry->Initialize(mDX3D11Rend.GetDevice()))
	{
		MessageBox(iHwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the color shader object.
	mShader = std::unique_ptr<Shader>(new Shader);
	if (!mShader)
	{
		return false;
	}

	// Initialize the color shader object.
	if (!mShader->Initialize(mDX3D11Rend.GetDevice(), iHwnd))
	{
		MessageBox(iHwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	return true;
}

void GraphicsManager::Shutdown()
{
	// Release the color shader object.
	if (mShader)
		mShader->Shutdown();

	// Release the model object.
	if (mGeometry)
		mGeometry->Shutdown();

	// Release the Direct3D object.
	mDX3D11Rend.Shutdown();
}

bool GraphicsManager::Frame()
{
	bool result;

	// Render the graphics scene.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}
