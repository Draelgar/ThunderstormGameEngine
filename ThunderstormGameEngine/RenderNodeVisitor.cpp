/***************************************************************
** Author: Peter Hultgren
** Date: 2018-09-23
****************************************************************/
#include "stdafx.h"
#include "RenderNodeVisitor.h"

using namespace ts;
using namespace ts::graphics;
using namespace ts::scene;

void ts::graphics::RenderNodeVisitor::ProcessTransformNode(std::shared_ptr<ts::scene::TransformNode> transformNode)
{
	math::Matrix top = mTransformStack.top();
	mTransformStack.push(top * transformNode->GetTransform());
}
