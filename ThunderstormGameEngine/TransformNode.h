/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#pragma once

#include "stdafx.h"
#include "Matrix.h"

namespace ts
{
	namespace scene
	{
		class NodeVisitor;

		/** This node contains a matrix representing the translation of all chils nodes. **/
		class TransformNode : public GroupNode
		{
		protected:
			 math::Matrix mTransformMatrix;

		public:
			/** Create a new transform node with the name "Transform" **/
			TransformNode();

			/** Create a new transform node with the given name. **/
			explicit TransformNode(std::string name);

			/** Accept a node visitor. **/
			void AcceptVisitor(std::shared_ptr<NodeVisitor> visitor) override;

			/** Get the transformmatrix. **/
			math::Matrix GetTransform();

			/** Translate the transformmatrix. **/
			void Translate(math::Float3 translation);

			/** Rotate the transformmatrix. **/
			void Rotate(math::Float4 rotation);

			/** Scale the transformmatrix. **/
			void Scale(math::Float3 scale);

		};
	}
}