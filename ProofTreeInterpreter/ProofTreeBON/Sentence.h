#ifndef PROOFTREEBONSENTENCE_H
#define PROOFTREEBONSENTENCE_H

#include "ProofTreeBonX.h"

namespace ProofTreeBON
{
//*******************************************************************
//   C  L  A  S  S   SentenceImpl
//*******************************************************************
class SentenceImpl :
	virtual public BON::FCOImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::multiset<ProofTreeBON::Connective>   getConnectionDsts();
	virtual std::multiset<ProofTreeBON::Connective>   getConnectionSrcs();
	virtual std::set<ProofTreeBON::Connection>        getInConnectionLinks();
	virtual std::set<ProofTreeBON::Connection>        getOutConnectionLinks();
	//
	// attribute getters and setters
	virtual bool        isIsNegated() ;
	virtual void        setIsNegated( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
