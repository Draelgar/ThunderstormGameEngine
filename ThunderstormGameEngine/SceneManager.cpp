/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-08
****************************************************************/
#include "stdafx.h"
#include "SceneManager.h"

using namespace ts::scene;

SceneManager::SceneManager()
{

}

bool SceneManager::Initialize(int iWidth, int iHeight, HWND iHwnd)
{
	// Initialize the graphics manager.
	return mGraphicsMng.Initialize(iWidth, iHeight, iHwnd);
}

void SceneManager::Shutdown()
{
	// Release the allocated memory.
	mGraphicsMng.Shutdown();
}

bool SceneManager::Frame()
{
	return mGraphicsMng.Frame();
}
