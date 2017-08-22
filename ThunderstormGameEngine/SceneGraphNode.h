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
		class NodeVisitor;

		/** This is the base of a scene graph node. **/
		class SceneGraphNode
		{
		protected:
			std::string mName; // Name of the node.

			explicit SceneGraphNode(std::string name);

		public:

			/** Accept a visitor and pass it onto its children, if any.**/
			virtual void AcceptVisitor(std::shared_ptr<NodeVisitor> visitor) = 0;

			/** Look for a node by the given name. **/
			virtual std::shared_ptr<SceneGraphNode> Find(std::string name) = 0;

		};
	}
}