#include "stdafx.h"
#include "ProofTreeBonX.h"

//********************************************************************************
// getter for role "Formula" among "ProofTreeBON::Formula"s
//********************************************************************************
std::set<ProofTreeBON::Formula> ProofTreeBON::TreeImpl::getFormula()
{
	std::set<ProofTreeBON::Formula> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Formula");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProofTreeBON::Formula elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


