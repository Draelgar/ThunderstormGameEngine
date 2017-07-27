/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-05
** Version 1.0.0
****************************************************************/
#include "stdafx.h"
#include "GameManager.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace ts;

std::unique_ptr<GameManager> GameManager::mGMInstancePtr = NULL;

GameManager::GameManager()
{
	bool configFileExist = mIniFile.Load("../Content/engine.ini");

	if (configFileExist)
	{
		file::ini::Section& sectionRef = mIniFile.Get("system");

		std::istringstream stringStream(sectionRef.GetValue("fullscreen").c_str());
		stringStream >> std::boolalpha >> mWinFullscreen;

		stringStream.str(sectionRef.GetValue("winSizeX").c_str());
		stringStream.clear();
		stringStream >> mWinSize[0];

		stringStream.str(sectionRef.GetValue("winSizeY").c_str());
		stringStream.clear();
		stringStream >> mWinSize[1];

		stringStream.str(sectionRef.GetValue("winPosX").c_str());
		stringStream.clear();
		stringStream >> mWinPos[0];

		stringStream.str(sectionRef.GetValue("winPosY").c_str());
		stringStream.clear();
		stringStream >> mWinPos[1];
	}
	else
	{
		// TODO add a proper error log...
		mIniFile.Save("../Content/error.ini");

		mWinFullscreen = false;
		mWinSize[0] = 800;
		mWinSize[1] = 600;
		mWinPos[0] = 0;
		mWinPos[1] = 0;
	}
}

std::unique_ptr<GameManager>& GameManager::GetSingeltonPtr()
{
	// Make sure the instance exist before returning it!
	if (mGMInstancePtr != NULL)
		return mGMInstancePtr;
	else
	{
		mGMInstancePtr = std::unique_ptr<GameManager>(new GameManager());
		return mGMInstancePtr;
	}

}

bool GameManager::Frame()
{
	bool result;

	// Check if the user pressed escape and wants to exit the application.
	// TODO move all key mappings onto a script (lua or python).
	if (mControlMng.IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	// Do the frame processing for the graphics object.
	result = mSceneMng.Frame();
	if (!result)
	{
		return false;
	}

	return true;
}

void GameManager::InitializeWindows()
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;

	// Get the instance of this application.
	mHinstance = GetModuleHandle(NULL);

	// Give the application a name.
	mWinTitle = L"Engine";

	// Setup the windows class with default settings.
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = mHinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = mWinTitle;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register the window class.
	RegisterClassEx(&wc);

	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if (mWinFullscreen)
	{
		// Determine the resolution of the clients desktop screen.
		mWinSize[0] = GetSystemMetrics(SM_CXSCREEN);
		mWinSize[1] = GetSystemMetrics(SM_CYSCREEN);

		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)mWinSize[0];
		dmScreenSettings.dmPelsHeight = (unsigned long)mWinSize[1];
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		mWinPos[0] = mWinPos[1] = 0;
	}
	else
	{
		// Place the window in the middle of the screen.
		mWinPos[0] = (GetSystemMetrics(SM_CXSCREEN) - mWinSize[0]) / 2;
		mWinPos[1] = (GetSystemMetrics(SM_CYSCREEN) - mWinSize[1]) / 2;
	}

	// Create the window with the screen settings and get the handle to it.
	mHwnd = CreateWindowEx(WS_EX_APPWINDOW, mWinTitle, mWinTitle,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
		mWinPos[0], mWinPos[1], mWinSize[0], mWinSize[1], NULL, NULL, mHinstance, NULL);

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(mHwnd, SW_SHOW);
	SetForegroundWindow(mHwnd);
	SetFocus(mHwnd);

	// Hide the mouse cursor.
	ShowCursor(false);

	return;
}

void GameManager::ShutdownWindows()
{
	// Show the mouse cursor.
	ShowCursor(true);

	// Fix the display settings if leaving full screen mode.
	if (mWinFullscreen)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// Remove the window.
	DestroyWindow(mHwnd);
	mHwnd = NULL;

	// Remove the application instance.
	UnregisterClass(mWinTitle, mHinstance);
	mHinstance = NULL;

	return;
}

bool GameManager::Initialize(std::wstring title)
{
	mWinTitle = title.c_str();

	bool result;

	// Initialize the windows api.
	InitializeWindows();

	// Initialize the graphics object.
	result = mSceneMng.Initialize(mWinSize[0], mWinSize[1], mHwnd);
	if (!result)
	{
		return false;
	}

	return true;
}

void GameManager::Run()
{
	MSG msg;
	bool done, result;

	// Initialize the message structure.
	ZeroMemory(&msg, sizeof(MSG));

	// Loop until there is a quit message from the window or the user.
	done = false;
	while (!done)
	{
		// Handle the windows messages.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// If windows signals to end the application then exit out.
		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// Otherwise do the frame processing.
			result = Frame();
			if (!result)
			{
				done = true;
			}
		}

	}

	return;
}

void GameManager::Shutdown()
{
	// Release the graphics object.
	mSceneMng.Shutdown();

	// Shutdown the window.
	ShutdownWindows();

	return;
}

LRESULT GameManager::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
		// Check if a key has been pressed on the keyboard.
		case WM_KEYDOWN:
		{
			// If a key is pressed send it to the input object so it can record that state.
			mControlMng.KeyDown((unsigned int)wparam);
			return 0;
		}

		// Check if a key has been released on the keyboard.
		case WM_KEYUP:
		{
			// If a key is released then send it to the input object so it can unset the state for that key.
			mControlMng.KeyUp((unsigned int)wparam);
			return 0;
		}

		// Any other messages send to the default message handler as our application won't make use of them.
		default:
		{
			return DefWindowProc(hwnd, umsg, wparam, lparam);
		}
	}
}

LRESULT CALLBACK GameManager::WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
		// Check if the window is being destroyed.
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}

		// Check if the window is being closed.
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}

		// All other messages pass to the message handler in the system class.
		default:
		{
			return mGMInstancePtr->MessageHandler(hwnd, umessage, wparam, lparam);
		}
	}
}
