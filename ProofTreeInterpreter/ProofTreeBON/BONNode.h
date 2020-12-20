#ifndef BON_NODE_H
#define BON_NODE_H

#include "ProofTreeBonX.h"

namespace ProofTreeBON
{
	class BONNode
	{
	public:
		BONNode();
		BONNode(BON::FCO Value);
		BON::FCO Value;
	};
}

#endif