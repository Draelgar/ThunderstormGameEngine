/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#pragma once

#include "SceneGraphNode.h"
#include "stdafx.h"

namespace ts
{
	namespace scene
	{
		class SceneGraphNode;
		class NodeVisitor;

		class GroupNode : public SceneGraphNode
		{
		protected:
			std::vector<std::shared_ptr<SceneGraphNode>> mChildren;

		public:
			/** Create a new group node with the default name "Group". **/
			GroupNode();

			/** Create a new group node with the given name. **/
			explicit GroupNode(std::string iName);

			/** Accept a node visitor. **/
			void AcceptVisitor(std::shared_ptr<NodeVisitor> visitor);

			/** Look for a node by the given name. **/
			std::shared_ptr<SceneGraphNode> Find(std::string name);

		};
	}
}