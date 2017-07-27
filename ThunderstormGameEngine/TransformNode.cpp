/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#include "stdafx.h"
using namespace DirectX;
using namespace ts::scene;

TransformNode::TransformNode() :
	GroupNode()
{
	// Create a clean identity matrix as no transformation has taken place yet.
	mTransformMatrix = XMMatrixIdentity();
	mName = "TranslationNode";
}

TransformNode::TransformNode(unsigned int index) :
	GroupNode()
{
	// Create a clean identity matrix as no transformation has taken place yet.
	mTransformMatrix = XMMatrixIdentity();
	mName = "TranslationNode " + index;
}

TransformNode::TransformNode(std::string name) :
	GroupNode()
{
	// Create a clean identity matrix as no transformation has taken place yet.
	mTransformMatrix = XMMatrixIdentity();
	mName = name;
}

void TransformNode::AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor)
{
	iVisitor->ProcessTransformNode((std::shared_ptr<TransformNode>)this);
}

DirectX::XMMATRIX TransformNode::GetTransform()
{
	return mTransformMatrix;
}

void TransformNode::Translate(XMFLOAT3 translation)
{
	mTransformMatrix = XMMatrixTranslation(translation.x, translation.y, translation.z);
}

void TransformNode::Rotate(XMVECTOR quaternion)
{
	mTransformMatrix = XMMatrixRotationQuaternion(quaternion);
}

void TransformNode::Scale(XMFLOAT3 scale)
{
	mTransformMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);
}



