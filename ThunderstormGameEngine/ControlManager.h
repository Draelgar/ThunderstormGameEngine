/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-08
** Version 1.0.0
****************************************************************/
#pragma once

#include "Timer.h"

namespace ts
{
	/** Keeps track of the controls that are being used. **/
	class ControlManager
	{
		private:
			bool mKeysPressed[256];
			Timer mTimers[256];

		public:
			/** Create a new controll manager. **/
			ControlManager() { for (unsigned int i = 0; i < 256; i++) mKeysPressed[i] = false; };

			/** Register a key being pressed. **/
			inline void KeyDown(unsigned int id) 
			{ 
				mKeysPressed[id] = true;
				mTimers[id].Reset();
			};

			/** Register a key being released. **/
			inline void KeyUp(unsigned int id) { mKeysPressed[id] = false; };

			/** Check weather a key is pressed. **/
			inline bool IsKeyDown(unsigned int id) { return mKeysPressed[id]; };

			/** Check for how long a key was held down. Does not take into account weather the key has been released or not. **/
			inline Duration heldDuration(unsigned int id) { return mTimers[id].TimeElapsed(NOW); };
	};
}