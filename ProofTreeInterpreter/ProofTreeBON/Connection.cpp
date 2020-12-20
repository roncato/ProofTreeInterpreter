#include "stdafx.h"
#include "ProofTreeBonX.h"

//********************************************************************************
// getDst() return value is a ConnectionEnd casted to ProofTreeBON::Connective
//********************************************************************************
ProofTreeBON::Connective ProofTreeBON::ConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	ProofTreeBON::Connective sp( ce);
	if ( sp)
		return sp;

	ProofTreeBON::Connective empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to ProofTreeBON::Sentence
//********************************************************************************
ProofTreeBON::Sentence ProofTreeBON::ConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	ProofTreeBON::Sentence sp( ce);
	if ( sp)
		return sp;

	ProofTreeBON::Sentence empty;
	return empty;
}
