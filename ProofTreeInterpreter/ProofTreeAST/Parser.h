#ifndef PARSER_H
#define PARSER_H

#include "ProofTreeBonX.h"
#include "AbstractSyntaxTree.h"
#include "ProofTreeBON\Tree.h"
#include "ProofTreeBON\BONNode.h"
#include "Connective.h"
#include <Console.h>

namespace ProofTreeAST
{
	class Parser
	{
	public:
		AbstractSyntaxTree* parse(ProofTreeBON::Tree* tree);
	private:
		AbstractSyntaxTree* parseSentence(ProofTreeBON::Sentence&);
		AbstractSyntaxTree* parseFormula(ProofTreeBON::Formula&);
		AbstractSyntaxTree* parseProposition(ProofTreeBON::Proposition&);
		AbstractSyntaxTree* parseConnective(ProofTreeBON::Connective&);
		ProofTreeBON::BONNode* getInitial(std::set<ProofTreeBON::Proposition>& set);
		ProofTreeBON::BONNode* getInitial(std::set<ProofTreeBON::Formula>& set);
	};
}

#endif