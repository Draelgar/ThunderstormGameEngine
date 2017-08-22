/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/

#include "stdafx.h"
#include "GeometryNode.h"

using namespace ts::scene;

ts::scene::GeometryNode::GeometryNode() :
	SceneGraphNode("Geometry")
{
}

ts::scene::GeometryNode::GeometryNode(std::string name) :
	SceneGraphNode(name)
{
}

void GeometryNode::AcceptVisitor(std::shared_ptr<NodeVisitor> visitor)
{
	visitor->ProcessGeometryNode(std::shared_ptr<GeometryNode>(this));
}

std::shared_ptr<SceneGraphNode> GeometryNode::Find(std::string name)
{
	if (mName == name)
		return std::shared_ptr<SceneGraphNode>(this);

	return NULL;
}
