/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#pragma once

#include "stdafx.h"

namespace ts
{
	namespace scene
	{
		class ProcessVisitor;

		/** This node contains a matrix representing the translation of all chils nodes. **/
		class TransformNode : public GroupNode
		{
		protected:
			DirectX::XMMATRIX mTransformMatrix;

		public:
			TransformNode();
			TransformNode(unsigned int index);
			TransformNode(std::string name);

			void AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor) override;

			DirectX::XMMATRIX GetTransform();

			void Translate(DirectX::XMFLOAT3 translation);

			void Rotate(DirectX::XMVECTOR rotation);

			void Scale(DirectX::XMFLOAT3 scale);

		};
	}
}