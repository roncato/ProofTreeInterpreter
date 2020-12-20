#include "StdAfx.h"
#include "BinaryFormula.h"

ProofTreeAST::BinaryFormula::BinaryFormula()
{
	IsNegated = false;
}

ProofTreeAST::BinaryFormula::BinaryFormula(ProofTreeAST::Sentence* left, ProofTreeAST::Sentence* right, ProofTreeAST::Connective* connective)
{
	Left = left;
	Right = right;
	Connective = connective;
	IsNegated = false;
}

std::string ProofTreeAST::BinaryFormula::toString()
{
	std::stringstream ss;
	if (IsNegated)
	{
		ss << "~";
	}
	ss << "(" << Left->toString() << " " << Connective->toString() << " " << Right->toString() << ")";
	return ss.str();
}

ProofTreeAST::Sentence* ProofTreeAST::BinaryFormula::clone()
{
	ProofTreeAST::BinaryFormula* clone = new ProofTreeAST::BinaryFormula();
	clone->Left = this->Left->clone();
	clone->Right = this->Right->clone();
	clone->Connective = this->Connective->clone();
	clone->IsNegated = this->IsNegated;
	return clone;
}

bool ProofTreeAST::BinaryFormula::equals(ProofTreeAST::Sentence* that)
{
	bool equals = false;
	if (that->isComplex())
	{
		BinaryFormula* formula = (BinaryFormula*)that;
		equals = this->Connective->Type == formula->Connective->Type
			&& this->IsNegated == formula->IsNegated;
		if (equals)
		{
			equals &= this->Left->equals(formula->Left);
			if (equals)
			{
				equals &= this->Right->equals(formula->Right);
			}
		}
	}
	return equals;
}

bool ProofTreeAST::BinaryFormula::isNegation(ProofTreeAST::Sentence* that)
{
	bool negation = false;
	if (that->isComplex())
	{
		BinaryFormula* formula = (BinaryFormula*)that;
		negation = this->Connective->Type == formula->Connective->Type
			&& this->IsNegated != formula->IsNegated;
		if (negation)
		{
			negation &= this->Left->equals(formula->Left);
			if (negation)
			{
				negation &= this->Right->equals(formula->Right);
			}
		}
	}
	return negation;
}