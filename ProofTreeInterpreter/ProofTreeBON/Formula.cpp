#include "stdafx.h"
#include "ProofTreeBonX.h"

//********************************************************************************
// getter for role "BiConditional" among "Connective"s and its descendants
//********************************************************************************
std::set<ProofTreeBON::BiConditional> ProofTreeBON::FormulaImpl::getBiConditional()
{
	std::set<ProofTreeBON::BiConditional> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BiConditional");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProofTreeBON::BiConditional elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Conditional" among "Connective"s and its descendants
//********************************************************************************
std::set<ProofTreeBON::Conditional> ProofTreeBON::FormulaImpl::getConditional()
{
	std::set<ProofTreeBON::Conditional> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Conditional");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProofTreeBON::Conditional elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Conjunction" among "Connective"s and its descendants
//********************************************************************************
std::set<ProofTreeBON::Conjunction> ProofTreeBON::FormulaImpl::getConjunction()
{
	std::set<ProofTreeBON::Conjunction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Conjunction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProofTreeBON::Conjunction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Connection" among "ProofTreeBON::Connection"s
//********************************************************************************
std::set<ProofTreeBON::Connection> ProofTreeBON::FormulaImpl::getConnection()
{
	std::set<ProofTreeBON::Connection> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProofTreeBON::Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "ProofTreeBON::" among "ProofTreeBON::Connective"s and its descendants
//********************************************************************************
std::set<ProofTreeBON::Connective> ProofTreeBON::FormulaImpl::getConnective()
{
	std::set<ProofTreeBON::Connective> res;
	const int len = 4;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("BiConditional");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Conditional");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Conjunction");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Disjunction");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			ProofTreeBON::Connective elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Disjunction" among "Connective"s and its descendants
//********************************************************************************
std::set<ProofTreeBON::Disjunction> ProofTreeBON::FormulaImpl::getDisjunction()
{
	std::set<ProofTreeBON::Disjunction> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Disjunction");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProofTreeBON::Disjunction elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Formula" among "ProofTreeBON::Formula"s
//********************************************************************************
std::set<ProofTreeBON::Formula> ProofTreeBON::FormulaImpl::getFormula()
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


//********************************************************************************
// getter for role "Proposition" among "ProofTreeBON::Proposition"s
//********************************************************************************
std::set<ProofTreeBON::Proposition> ProofTreeBON::FormulaImpl::getProposition()
{
	std::set<ProofTreeBON::Proposition> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Proposition");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		ProofTreeBON::Proposition elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


