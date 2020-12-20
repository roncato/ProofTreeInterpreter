#ifndef PROOFTREEBONFORMULA_H
#define PROOFTREEBONFORMULA_H

#include "ProofTreeBonX.h"

namespace ProofTreeBON
{
//*******************************************************************
//   C  L  A  S  S   FormulaImpl
//*******************************************************************
class FormulaImpl :
	  virtual public BON::ModelImpl
	  , public SentenceImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// kind and role getters
	virtual std::set<ProofTreeBON::BiConditional>     getBiConditional();
	virtual std::set<ProofTreeBON::Conditional>       getConditional();
	virtual std::set<ProofTreeBON::Conjunction>       getConjunction();
	virtual std::set<ProofTreeBON::Connection>        getConnection();
	virtual std::set<ProofTreeBON::Connective>        getConnective();
	virtual std::set<ProofTreeBON::Disjunction>       getDisjunction();
	virtual std::set<ProofTreeBON::Formula> getFormula();
	virtual std::set<ProofTreeBON::Proposition>       getProposition();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
