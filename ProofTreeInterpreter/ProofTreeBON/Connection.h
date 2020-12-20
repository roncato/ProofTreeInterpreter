#ifndef PROOFTREEBONCONNECTION_H
#define PROOFTREEBONCONNECTION_H

#include "ProofTreeBonX.h"


namespace ProofTreeBON
{
//*******************************************************************
//   C  L  A  S  S   ConnectionImpl
//*******************************************************************
class ConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual ProofTreeBON::Connective        getDst();
	virtual ProofTreeBON::Sentence          getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
