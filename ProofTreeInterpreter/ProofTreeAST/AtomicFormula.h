#ifndef ATOMIC_FORMULA_H
#define ATOMIC_FORMULA_H

#include <string>
#include <sstream>
#include "ProofTreeAST\Sentence.h"

namespace ProofTreeAST
{
	class AtomicFormula : public Sentence
	{
	public:
		AtomicFormula();
		std::string Name;
		virtual std::string toString();
		virtual Sentence* clone();
		virtual bool equals(ProofTreeAST::Sentence*);
		virtual bool isNegation(ProofTreeAST::Sentence*);
	};
}

#endif