#ifndef PROOFTREEBONTREE_H
#define PROOFTREEBONTREE_H

#include "ProofTreeBonX.h"

namespace ProofTreeBON
{
//*******************************************************************
//   C  L  A  S  S   TreeImpl
//*******************************************************************
class TreeImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// kind and role getters
	virtual std::set<ProofTreeBON::Formula> getFormula();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
