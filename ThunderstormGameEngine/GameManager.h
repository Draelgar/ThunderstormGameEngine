/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-05
** Version 1.0.0
****************************************************************/
#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "stdafx.h"

#include <IniFile.h>
#include "ControlManager.h"
#include "SceneManager.h"

namespace ts
{
	/** This class will handle communication between controlls and the game itself, as well as handling the actual window frame. **/
	class GameManager
	{
		private:
			file::IniFile mIniFile;
			int mWinSize[2];
			int mWinPos[2];

			bool mWinFullscreen;

			LPCWSTR mWinTitle;
			HINSTANCE mHinstance;
			HWND mHwnd;

			static std::unique_ptr<GameManager> mGMInstancePtr; // The one and only existing instance of this class.

			ControlManager mControlMng;
			scene::SceneManager mSceneMng;

		private:
			GameManager();

			bool Frame();
			void InitializeWindows();
			void ShutdownWindows();

		public:
			/** Get a pointer to the instance of this object. **/
			static std::unique_ptr<GameManager>& GetSingeltonPtr();

			/** Initialize the game engine. **/
			bool Initialize(std::wstring title);
			/** Run the game engine. **/
			void Run();
			/** Shutdown the game engine and free allocated memory. **/
			void Shutdown();

			static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

			LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

	};

}