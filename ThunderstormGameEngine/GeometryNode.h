/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/
#pragma once

#include "BaseGeometry.h"
#include "SceneGraphNode.h"

namespace ts
{
	class BaseGeometry;

	namespace scene
	{
		/** This class handles the actual geometry of a 3D object. **/
		class GeometryNode : public SceneGraphNode
		{
		private:
			/** The actual geometry of this node. **/
			std::shared_ptr<BaseGeometry> mGeometry;

			// TODO: Add material as well.

		public:
			/** Create a new geometry node with the default name "Geometry". **/
			GeometryNode();

			/** Create a new geometry node with the given name. **/
			explicit GeometryNode(std::string name);

			/** Accept a visitor.**/
			void AcceptVisitor(std::shared_ptr<NodeVisitor> visitor);

			/** Return this node if it has the same name, else Null. **/
			std::shared_ptr<SceneGraphNode> Find(std::string name);
		};
	}
}