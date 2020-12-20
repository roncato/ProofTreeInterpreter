#ifndef TABLEAUX_H
#define TABLEAUX_H

#include "ProofTreeAST\Sentence.h"
#include "ProofTreeAST\AtomicFormula.h"
#include <vector>

namespace Tableaux
{
	class Tableaux
	{
	public:
		Tableaux(Tableaux* parent);
		~Tableaux();
		std::vector<Tableaux*>* getChildNodes();
		std::vector<ProofTreeAST::Sentence*>* getSentences();
		std::vector<ProofTreeAST::AtomicFormula*>* getBranchAtoms();
		bool isClosed();
		void close();
		Tableaux* getParent();
		void setParent(Tableaux* parent);
		std::string toString();

	private:
		std::vector<Tableaux*>* _childNodes;
		std::vector<ProofTreeAST::Sentence*>* _sentences;
		bool _isClosed;
		Tableaux* _parent;
		void getBranchAtoms(std::vector<ProofTreeAST::AtomicFormula*>*);
		bool isContained(std::vector<ProofTreeAST::AtomicFormula*>* atoms, ProofTreeAST::AtomicFormula* atom);
	};
}
#endif