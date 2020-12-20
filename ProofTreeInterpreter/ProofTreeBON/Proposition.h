#ifndef PROOFTREEBONPROPOSITION_H
#define PROOFTREEBONPROPOSITION_H

#include "ProofTreeBonX.h"


namespace ProofTreeBON
{
//*******************************************************************
//   C  L  A  S  S   PropositionImpl
//*******************************************************************
class PropositionImpl :
	  virtual public BON::AtomImpl
	, public SentenceImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
