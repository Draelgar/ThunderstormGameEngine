/***************************************************************
** Author: Peter Hultgren
** Date: 2017-02-11
****************************************************************/
#pragma once

#include "stdafx.h"
#include "ProcessVisitor.h"

namespace ts
{
	namespace scene
	{
		class ProcessVisitor;

		/** This is the base of a scene graph node. **/
		class SceneGraphNode
		{
		protected:
			std::string mName; // Name of the node.

			/** Default Constructor, can not initialize an object of this type! **/
			SceneGraphNode();

			SceneGraphNode(std::string iName);

		public:

			/** Accept a visitor.**/
			virtual void AcceptVisitor(std::shared_ptr<ProcessVisitor> iVisitor) = 0;

			/** Get the specified child node. **/
			virtual std::shared_ptr<SceneGraphNode> GetChild(unsigned int index) = 0;

			/** Look for a node by the given name. **/
			virtual std::shared_ptr<SceneGraphNode> GetNamedNode(std::string name) = 0;

			/** Get the next child node. **/
			virtual std::shared_ptr<SceneGraphNode> GetNextChild() = 0;

			/** Reset child counter. **/
			virtual void ResetChildCounter() = 0;

		};
	}
}