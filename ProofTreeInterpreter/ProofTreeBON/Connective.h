#ifndef PROOFTREEBONOperator_H
#define PROOFTREEBONOperator_H

#include "ProofTreeBonX.h"

namespace ProofTreeBON
{
//*******************************************************************
//   C  L  A  S  S   OperatorImpl
//*******************************************************************
class ConnectiveImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::multiset<ProofTreeBON::Sentence>     getConnectionDsts();
	virtual std::multiset<ProofTreeBON::Sentence>     getConnectionSrcs();
	virtual std::set<ProofTreeBON::Connection>        getInConnectionLinks();
	virtual std::set<ProofTreeBON::Connection>        getOutConnectionLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
