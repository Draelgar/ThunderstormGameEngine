/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/
#pragma once

#include "GroupNode.h"
#include "Camera.h"

namespace ts
{
	namespace scene
	{
		/** This node contains the information required by a camera.
			At least 1 node is required within the scene graph and
			any additional ones will cause the scene to draw once again
			for each addidional camera. **/
		class CameraNode : public scene::GroupNode
		{
		private:
			graphics::Camera mCamera;

		public:
			CameraNode(bool orthogonal = false);

			CameraNode(std::string iName, bool orthogonal = false);

			/** Accept a visitor.**/
			void AcceptVisitor(std::shared_ptr<scene::ProcessVisitor> iVisitor) override;

		};
	}
}