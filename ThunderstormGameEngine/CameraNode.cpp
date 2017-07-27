/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-14
****************************************************************/
#include "stdafx.h"
#include "CameraNode.h"

using namespace ts::scene;

CameraNode::CameraNode(bool orthogonal) :
	GroupNode()
{
	// TODO: allow the camera to setup orthogonal view!
	mName = "Camera";
}

CameraNode::CameraNode(std::string iName, bool orthogonal)
{
	// TODO: allow the camera to setup orthogonal view!
	mName = iName;
}

void CameraNode::AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor)
{
	// Instruct the visitor on how to treat this object.
	iVisitor->ProcessCameraNode(std::shared_ptr<CameraNode>(this));
}
