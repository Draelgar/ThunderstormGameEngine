/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/

#include "stdafx.h"
#include "GeometryNode.h"

using namespace ts::scene;

void GeometryNode::AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor)
{
}

std::shared_ptr<SceneGraphNode> GeometryNode::GetChild(unsigned int index)
{
	return NULL;
}

std::shared_ptr<SceneGraphNode> GeometryNode::GetNamedNode(std::string name)
{
	return NULL;
}

std::shared_ptr<SceneGraphNode> GeometryNode::GetNextChild()
{
	return NULL;
}

void GeometryNode::ResetChildCounter()
{
}
