/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#include "stdafx.h"

using namespace ts::scene;
using namespace ts::math;

TransformNode::TransformNode() :
	GroupNode("Transform")
{
	// Create a clean identity matrix as no transformation has taken place yet.
	mTransformMatrix = Matrix::Identity();
}

TransformNode::TransformNode(std::string name) :
	GroupNode(name)
{
	// Create a clean identity matrix as no transformation has taken place yet.
	mTransformMatrix = Matrix::Identity();
}

void TransformNode::AcceptVisitor(std::shared_ptr<NodeVisitor> visitor)
{
	visitor->ProcessTransformNode((std::shared_ptr<TransformNode>)this);

	// The group node will update the child nodes.
	GroupNode::AcceptVisitor(visitor);
}

Matrix TransformNode::GetTransform()
{
	return mTransformMatrix;
}

void TransformNode::Translate(Float3 translation)
{
	mTransformMatrix.TranslateDX(translation);
}

void TransformNode::Rotate(Float4 rotation)
{
	mTransformMatrix.Rotate(rotation);
}

void TransformNode::Scale(Float3 scale)
{
	mTransformMatrix.Scale(scale);
}



