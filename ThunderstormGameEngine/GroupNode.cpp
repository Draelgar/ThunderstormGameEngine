/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#include "stdafx.h"
#include "GroupNode.h"

using namespace ts::scene;

GroupNode::GroupNode() :
	SceneGraphNode("Group")
{
	mChildren = std::vector<std::shared_ptr<SceneGraphNode>>();
}

GroupNode::GroupNode(std::string name) :
	SceneGraphNode(name)
{
	mChildren = std::vector<std::shared_ptr<SceneGraphNode>>();
}

void GroupNode::AcceptVisitor(std::shared_ptr<NodeVisitor> visitor)
{
	// Group nodes are not to be processed as they do not contain any real data, just a list of child nodes.
	// So we'll just update the its children.
	for (unsigned int i = 0; i < mChildren.size(); i++)
	{
		mChildren[i]->AcceptVisitor(visitor);
	}
}

std::shared_ptr<SceneGraphNode> GroupNode::Find(std::string name)
{
	// Is this the node we are looking for?
	if (mName == name)
	{
		return std::shared_ptr<SceneGraphNode>(this);
	}
	else if (mChildren.size() > 0)
	{
		std::shared_ptr<SceneGraphNode> nodePtr;

		// Loop through all child nodes.
		for (unsigned int i = 0; i < mChildren.size(); i++)
		{
			nodePtr = mChildren[i]->Find(name);
			if (nodePtr != NULL)
				return nodePtr;
		}
	}

	// No nodes could be found by that name, return NULL.
	return NULL;
}
