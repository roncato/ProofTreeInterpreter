#ifndef SOLVER_H
#define SOLVE_H

#include "Tableaux.h"
#include "ProofTreeAST\Sentence.h"
#include "ProofTreeAST\BinaryFormula.h"
#include "ProofTreeAST\AtomicFormula.h"
#include <queue>

namespace Tableaux
{
	class Solver
	{
	public:
		Solver();
		~Solver();
		Tableaux* solve(ProofTreeAST::Sentence*);
		std::vector<Tableaux*>* getBelongingBranches(ProofTreeAST::Sentence*);
		std::set<Tableaux*>* getOpenBranches();
	private:
		std::queue<ProofTreeAST::BinaryFormula*>* _unprocessedFormulae;
		std::set<Tableaux*>* _unprocessedNodes;
		std::set<Tableaux*>* _openBranches;
		void expand(ProofTreeAST::Sentence*);
		bool process(ProofTreeAST::BinaryFormula* formula, Tableaux* parent);
		bool process(ProofTreeAST::AtomicFormula* atom, Tableaux* parent);
		bool process(ProofTreeAST::Sentence* root, Tableaux* parent);
		bool hasContradition(ProofTreeAST::AtomicFormula* atom, Tableaux* parent);
		bool belongsToBranch(ProofTreeAST::Sentence* sentence, Tableaux* node);
		void markForProcessing(Tableaux* node);
		Tableaux* _root;
		int _currrentStep;
	};
}

#endif