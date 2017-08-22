/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/
#include "stdafx.h"
#include "CameraNode.h"

using namespace ts::scene;

CameraNode::CameraNode(bool orthogonal) :
	SceneGraphNode("Camera")
{
	// TODO: allow the camera to setup orthogonal view!
}

CameraNode::CameraNode(std::string name, bool orthogonal) :
	SceneGraphNode(name)
{
	// TODO: allow the camera to setup orthogonal view!
}

void CameraNode::AcceptVisitor(std::shared_ptr<NodeVisitor> visitor)
{
	// Instruct the visitor on how to treat this object.
	visitor->ProcessCameraNode(std::shared_ptr<CameraNode>(this));
}

std::shared_ptr<SceneGraphNode> ts::scene::CameraNode::Find(std::string name)
{
	if (mName == name)
		return std::shared_ptr<SceneGraphNode>(this);

	return NULL;
}
