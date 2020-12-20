#ifndef PROOFTREEVISITOR_H
#define PROOFTREEVISITOR_H

#include "ProofTreeAST\AbstractSyntaxTree.h"
#include "ProofTreeAST\Connective.h"
#include "ProofTreeAST\Sentence.h"
#include "ProofTreeAST\AtomicFormula.h"
#include "ProofTreeAST\BinaryFormula.h"

namespace ProofTreeAST
{

	class ProofTreeVisitor
	{
		public :
			virtual void* visitConnective(const ProofTreeAST::Connective object) = 0;
			virtual void* visitSentence(const ProofTreeAST::Sentence& object) = 0;
			virtual void* visitAtomicFormula(const ProofTreeAST::AtomicFormula& object) = 0;
			virtual void* visitBinaryFormula(const ProofTreeAST::BinaryFormula& object) = 0;
	};

}

#endif]
