/***************************************************************
** Author: Peter Hultgren
** Date: 2018-09-23
****************************************************************/

#pragma once

#include <stack>

#include "NodeVisitor.h" 
#include "GeometryNode.h"
#include "TransformNode.h"
#include "CameraNode.h"

namespace ts
{
	namespace graphics
	{
		class RenderNodeVisitor: public ts::scene::NodeVisitor
		{
		protected:
			std::stack<ts::math::Matrix> mTransformStack;

		public:
			/** Process a node containing geometric data of a graphical object. **/
			void ProcessGeometryNode(std::shared_ptr<ts::scene::GeometryNode> geometryNode);
			/** Process a node containing a transformation matrix. **/
			void ProcessTransformNode(std::shared_ptr<ts::scene::TransformNode> transformNode);
			/** Process a node containing camera data. **/
			void ProcessCameraNode(std::shared_ptr<ts::scene::CameraNode> cameraNode);
		};
	}
}