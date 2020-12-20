#ifndef TABLEAUX_RENDERER_H
#define TABLEAUX_RENDERER_H

#include "Tableaux.h"
#include "ProofTreeAST\AtomicFormula.h"
#include "ProofTreeAST\BinaryFormula.h"
#include <string>
#include <sstream>
#include <vector>

namespace Tableaux
{
	class TableauxRenderer
	{
	public:
		std::string renderHTML(Tableaux* parent, std::set<Tableaux*>* openBranches);
		std::string renderXML(Tableaux*);
	private:
		std::string renderInterpretations(std::set<Tableaux*>*);
		std::string _renderHTML(Tableaux*);
		std::string _renderXML(Tableaux*);
		std::string renderInterpretations(std::vector<ProofTreeAST::AtomicFormula*>* atoms, Tableaux* branch);
		std::string renderXML(ProofTreeAST::AtomicFormula*);
		std::string renderXML(ProofTreeAST::BinaryFormula*);
		std::string renderXML(ProofTreeAST::Sentence*);

	};
}

#endif