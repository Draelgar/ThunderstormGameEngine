/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/
#pragma once

#include "SceneGraphNode.h"
#include "Geometry.h"

namespace ts
{
	namespace scene
	{
		/** This class handles the actual geometry of a 3D object. **/
		class GeometryNode : public SceneGraphNode
		{
		private:

		public:
			/** Accept a visitor.**/
			void AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor);

			/** Inherited interface function, returns NULL as this class has no child nodes. **/
			std::shared_ptr<SceneGraphNode> GetChild(unsigned int index);

			/** Inherited interface function, returns NULL as this class has no child nodes. **/
			std::shared_ptr<SceneGraphNode> GetNamedNode(std::string name);

			/** Inherited interface function, returns NULL as this class has no child nodes. **/
			std::shared_ptr<SceneGraphNode> GetNextChild();

			/** Inherited interface function, does nothing as this class has no child nodes. **/
			void ResetChildCounter();
		};
	}
}