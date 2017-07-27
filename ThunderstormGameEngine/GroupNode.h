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
		class ProcessVisitor;

		class GroupNode : public SceneGraphNode
		{
		protected:
			std::vector<std::shared_ptr<SceneGraphNode>> mChildren;
			unsigned int mNextChildIndex;

		public:
			GroupNode();

			GroupNode(unsigned int iNumber);

			GroupNode(std::string iName);

			void AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor);

			/** Get the specified child node. **/
			std::shared_ptr<SceneGraphNode> GetChild(unsigned int index);

			/** Look for a node by the given name. **/
			std::shared_ptr<SceneGraphNode> GetNamedNode(std::string name);

			/** Get the next child node. **/
			std::shared_ptr<SceneGraphNode> GetNextChild();

			/** Reset child counter. **/
			void ResetChildCounter();
		};
	}
}