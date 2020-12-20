#include "stdafx.h"
#include "ProofTreeBonX.h"

//********************************************************************************
// returns dst ProofTreeBON::Sentences
//********************************************************************************
std::multiset<ProofTreeBON::Sentence> ProofTreeBON::ConnectiveImpl::getConnectionDsts()
{
	std::multiset<ProofTreeBON::Sentence> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			ProofTreeBON::Sentence dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src ProofTreeBON::Sentences
//********************************************************************************
std::multiset<ProofTreeBON::Sentence> ProofTreeBON::ConnectiveImpl::getConnectionSrcs()
{
	std::multiset<ProofTreeBON::Sentence> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			ProofTreeBON::Sentence dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<ProofTreeBON::Connection> ProofTreeBON::ConnectiveImpl::getInConnectionLinks()
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
std::set<ProofTreeBON::Connection> ProofTreeBON::ConnectiveImpl::getOutConnectionLinks()
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


