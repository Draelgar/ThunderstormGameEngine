/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#include "stdafx.h"
#include "GroupNode.h"

using namespace ts::scene;

GroupNode::GroupNode()
{
	mChildren = std::vector<std::shared_ptr<SceneGraphNode>>();
}

GroupNode::GroupNode(unsigned int iNumber) :
	SceneGraphNode()
{
	mChildren = std::vector<std::shared_ptr<SceneGraphNode>>();
	mName = "GroupNode " + iNumber;
	mNextChildIndex = 0;
}

GroupNode::GroupNode(std::string iName) :
	SceneGraphNode(iName)
{
	mChildren = std::vector<std::shared_ptr<SceneGraphNode>>();
	mNextChildIndex = 0;
}

void GroupNode::AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor)
{
	// Group nodes are not to be processed as they do not contain any real data, just a list of child nodes.
}

std::shared_ptr<SceneGraphNode> GroupNode::GetChild(unsigned int index)
{
	if (mChildren.size() > index)
		return mChildren[index];

	return NULL;
}

std::shared_ptr<SceneGraphNode> GroupNode::GetNamedNode(std::string name)
{
	// Is this the node we are looking for?
	if (mName == name)
	{
		return (std::shared_ptr<SceneGraphNode>)this;
	}
	else if (mChildren.size() > 0)
	{
		std::shared_ptr<SceneGraphNode> nodePtr;

		// Loop through all child nodes.
		for (unsigned int i = 0; i < mChildren.size(); i++)
		{
			nodePtr = mChildren[i]->GetNamedNode(name);
			if (nodePtr != NULL)
				return nodePtr;
		}
	}

	// No nodes could be found by that name, return NULL.
	return NULL;
}

std::shared_ptr<SceneGraphNode> GroupNode::GetNextChild()
{
	if (mChildren.size() >= 0)
	{
		if (mNextChildIndex >= mChildren.size())
			mNextChildIndex = 0;

		return mChildren[mNextChildIndex];
	}
	else
		return NULL;
}

void GroupNode::ResetChildCounter()
{
	mNextChildIndex = 0;
}
