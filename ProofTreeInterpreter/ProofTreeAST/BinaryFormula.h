#ifndef BINARY_FORMULA_H
#define BINARY_FORMULA_H

#include <sstream>
#include "Sentence.h"
#include "Connective.h"

namespace ProofTreeAST
{
	class BinaryFormula : public Sentence
	{
	public:
		BinaryFormula();
		BinaryFormula(Sentence*, Sentence*, Connective*);
		Sentence* Left;
		Sentence* Right;
		Connective* Connective;
		virtual std::string toString();
		virtual Sentence* clone();
		virtual bool equals(ProofTreeAST::Sentence*);
		virtual bool isNegation(ProofTreeAST::Sentence*);
	};
}

#endif