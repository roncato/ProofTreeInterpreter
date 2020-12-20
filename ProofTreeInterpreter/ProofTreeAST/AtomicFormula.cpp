#include "StdAfx.h"
#include "AtomicFormula.h"

ProofTreeAST::AtomicFormula::AtomicFormula()
{
	_isComplex = false;
	IsNegated = false;
}

std::string ProofTreeAST::AtomicFormula::toString()
{
	std::stringstream ss;
	if (IsNegated)
	{
		ss << "~";
	}
	ss << Name;
	return ss.str();
}

ProofTreeAST::Sentence* ProofTreeAST::AtomicFormula::clone()
{
	AtomicFormula* clone = new AtomicFormula();
	clone->IsNegated = this->IsNegated;
	clone->Name = this->Name;
	return clone;
}

bool ProofTreeAST::AtomicFormula::equals(ProofTreeAST::Sentence* that)
{
	bool equals = false;
	if (!that->isComplex())
	{
		AtomicFormula* formula = (AtomicFormula*)that;
		if (this->IsNegated == formula->IsNegated)
		{
			equals = this->Name.compare(formula->Name) == 0;
		}
	}
	return equals;
}

bool ProofTreeAST::AtomicFormula::isNegation(ProofTreeAST::Sentence* that)
{
	bool negation = false;
	if (!that->isComplex())
	{
		AtomicFormula* formula = (AtomicFormula*)that;
		if (this->IsNegated != formula->IsNegated)
		{
			negation = this->Name.compare(formula->Name) == 0;
		}
	}
	return negation;
}