#include "stdafx.h"
#include "ProofTreeBonX.h"

//********************************************************************************
// returns dst ProofTreeBON::Operators
//********************************************************************************
std::multiset<ProofTreeBON::Connective> ProofTreeBON::SentenceImpl::getConnectionDsts()
{
	std::multiset<ProofTreeBON::Connective> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ProofTreeBON::Connective dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ProofTreeBON::Operators
//********************************************************************************
std::multiset<ProofTreeBON::Connective> ProofTreeBON::SentenceImpl::getConnectionSrcs()
{
	std::multiset<ProofTreeBON::Connective> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ProofTreeBON::Connective dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ProofTreeBON::Connection> ProofTreeBON::SentenceImpl::getInConnectionLinks()
{
	std::set<ProofTreeBON::Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ProofTreeBON::Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ProofTreeBON::Connection> ProofTreeBON::SentenceImpl::getOutConnectionLinks()
{
	std::set<ProofTreeBON::Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		ProofTreeBON::Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
bool ProofTreeBON::SentenceImpl::isIsNegated() 
{
	return FCOImpl::getAttribute("IsNegated")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void ProofTreeBON::SentenceImpl::setIsNegated( bool val)
{
	FCOImpl::getAttribute("IsNegated")->setBooleanValue( val);
}


