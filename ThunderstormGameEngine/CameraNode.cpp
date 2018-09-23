/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/
#include "stdafx.h"
#include "CameraNode.h"

using namespace ts::scene;

CameraNode::CameraNode(std::string name, ts::graphics::Camera camera) :
	SceneGraphNode(name)
{
	mCamera = camera;
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
