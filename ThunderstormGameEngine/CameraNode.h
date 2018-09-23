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
		class CameraNode : public scene::SceneGraphNode
		{
		private:
			graphics::Camera mCamera;

		public:
			/** Create a new camera node with the given name. **/
			explicit CameraNode(std::string name, graphics::Camera camera);

			/** Accept a visitor.**/
			void AcceptVisitor(std::shared_ptr<scene::NodeVisitor> visitor);

			/** Look for a node by the given name. **/
			std::shared_ptr<SceneGraphNode> Find(std::string name);
		};
	}
}