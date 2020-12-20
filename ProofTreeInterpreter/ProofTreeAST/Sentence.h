#ifndef SENTENCE_H
#define SENTENCE_H

#include "AbstractSyntaxTree.h"
#include <sstream>
#include <string>

namespace ProofTreeAST
{
	class Sentence : public AbstractSyntaxTree
	{
	public:
		bool IsNegated;
		int Id;
		bool isComplex();
		virtual Sentence* clone() = 0;
		virtual std::string toString() = 0;
		virtual bool equals(ProofTreeAST::Sentence*) = 0;
		virtual bool isNegation(ProofTreeAST::Sentence*) = 0;
	protected:
		bool _isComplex;
	};
}

#endif