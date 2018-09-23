/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#pragma once

#include "stdafx.h"

namespace ts
{
	namespace scene
	{
		class TransformNode;
		class CameraNode;
		class GeometryNode;

		/** A base class for all visitor objects that will process the data of the scene graph nodes. **/
		class NodeVisitor
		{
		public:
			/** Process a node containing geometric data of a graphical object. **/
			virtual void ProcessGeometryNode(std::shared_ptr<GeometryNode> geometryNode) = 0;
			/** Process a node containing a transformation matrix. **/
			virtual void ProcessTransformNode(std::shared_ptr<TransformNode> transformNode) = 0;
			/** Process a node containing camera data. **/
			virtual void ProcessCameraNode(std::shared_ptr<CameraNode> cameraNode) = 0;
		};
	}
}