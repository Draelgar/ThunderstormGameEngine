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
		class ProcessVisitor
		{
		protected:
			ProcessVisitor();

		public:
			/** Process a node containing geometric data of a graphical object. **/
			virtual void ProcessGeometryNode() = 0;
			/** Process a node containing textures, shaders and other material data for a graphical object. **/
			//virtual void ProcessMaterialNode() = 0;
			/** Process a node containing a transformation matrix. **/
			virtual void ProcessTransformNode(std::shared_ptr<TransformNode> iTransformNode) = 0;
			/** Process a node containing camera data. **/
			virtual void ProcessCameraNode(std::shared_ptr<CameraNode> iCameraNode) = 0;
			/** Process a node containing movement within a scene. This will update following translation node for a continious motion. **/
			//virtual void ProcessMotionNode() = 0;
			/** Process a node containing graphical data for a particle system. **/
			//virtual void ProcessParticleNode() = 0;
			/** Process a node containing bounding volumes and physical data. **/
			//virtual void ProcessPhysObjectNode() = 0;
			/** Process a scene node that contains name tags and file names to tie it to graphical and physical entity nodes. **/
			//virtual void ProcessSceneEntityNode() = 0;
		};
	}
}