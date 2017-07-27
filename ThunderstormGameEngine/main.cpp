/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-05
****************************************************************/
#include "stdafx.h"
#include "GameManager.h"

using namespace ts;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	// Get the game manager instance.
	std::unique_ptr<GameManager>& gm = GameManager::GetSingeltonPtr();
	bool result;

	// Initialize and run the system object.
	result = gm->Initialize(L"Thunderstorm Game Engine");
	if (result)
	{
		gm->Run();
	}

	// Shutdown and release the system object.
	gm->Shutdown();

	return 0;
}