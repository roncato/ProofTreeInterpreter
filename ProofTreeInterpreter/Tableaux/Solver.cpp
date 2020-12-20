#include "StdAfx.h"
#include "Solver.h"

Tableaux::Solver::Solver()
{
	_unprocessedFormulae = new std::queue<ProofTreeAST::BinaryFormula*>();
	_unprocessedNodes = new std::set<Tableaux*>();
	_openBranches = new std::set<Tableaux*>();
	_root = new Tableaux(NULL);
	_currrentStep = 1;
}

Tableaux::Solver::~Solver()
{
	delete _unprocessedFormulae;
	delete _unprocessedNodes;
}

Tableaux::Tableaux* Tableaux::Solver::solve(ProofTreeAST::Sentence* root)
{
	_root->getSentences()->push_back(root);
	process(root, _root);
	while (_unprocessedFormulae->size() > 0)
	{
		ProofTreeAST::BinaryFormula* formula = _unprocessedFormulae->front();
		_unprocessedFormulae->pop();
		formula->Id = _currrentStep++;
		std::vector<Tableaux*>* nodes = getBelongingBranches(formula);
		for (std::vector<Tableaux*>::iterator it = nodes->begin(); it != nodes->end(); it++)
		{
			Tableaux* node = *it;
			_unprocessedNodes->erase(node);
			process(formula, node);
		}
	}
	
	return _root;
}

bool Tableaux::Solver::process(ProofTreeAST::Sentence* root, Tableaux* parent)
{
	if (root->isComplex())
	{
		return process((ProofTreeAST::BinaryFormula*)root, parent);
	}
	else
	{
		return process((ProofTreeAST::AtomicFormula*)root, parent);
	}
}

bool Tableaux::Solver::process(ProofTreeAST::AtomicFormula* atom, Tableaux* node)
{
	if (hasContradition(atom, node))
	{
		node->close();
	}
	else if (node->getSentences()->size() > 0)
	{
		_openBranches->insert(node);
	}
	return node->isClosed();
}

bool Tableaux::Solver::process(ProofTreeAST::BinaryFormula* formula, Tableaux* parent)
{
	if (!formula->IsNegated)
	{
		switch (formula->Connective->Type)
		{
		case ProofTreeAST::ConnectiveType::Conjunction:
			{
				Tableaux* child = new Tableaux(parent);
				ProofTreeAST::Sentence* left = formula->Left->clone();
				ProofTreeAST::Sentence* right = formula->Right->clone();
				child->getSentences()->push_back(left);
				child->getSentences()->push_back(right);
				parent->getChildNodes()->push_back(child);
				markForProcessing(child);
			}
			break;
		case ProofTreeAST::ConnectiveType::Disjunction:
			{
				Tableaux* leftChild = new Tableaux(parent);
				Tableaux* rightChild = new Tableaux(parent);
				ProofTreeAST::Sentence* left = formula->Left->clone();
				ProofTreeAST::Sentence* right = formula->Right->clone();				
				leftChild->getSentences()->push_back(left);
				rightChild->getSentences()->push_back(right);
				parent->getChildNodes()->push_back(leftChild);
				parent->getChildNodes()->push_back(rightChild);
				markForProcessing(leftChild);
				markForProcessing(rightChild);
			}
			break;
		case ProofTreeAST::ConnectiveType::Conditional:
			{
				Tableaux* leftChild = new Tableaux(parent);
				Tableaux* rightChild = new Tableaux(parent);
				ProofTreeAST::Sentence* antecendent = formula->Left->clone();
				ProofTreeAST::Sentence* conclusion = formula->Right->clone();				
				antecendent->IsNegated = !formula->Left->IsNegated;
				leftChild->getSentences()->push_back(antecendent);
				rightChild->getSentences()->push_back(conclusion);
				parent->getChildNodes()->push_back(leftChild);
				parent->getChildNodes()->push_back(rightChild);
				markForProcessing(leftChild);
				markForProcessing(rightChild);
			}
			break;
		case ProofTreeAST::ConnectiveType::BiConditional:
			{
				Tableaux* leftChild = new Tableaux(parent);
				Tableaux* rightChild = new Tableaux(parent);
				ProofTreeAST::Sentence* leftLeft = formula->Left->clone();
				ProofTreeAST::Sentence* leftRight = formula->Right->clone();
				ProofTreeAST::Sentence* rightLeft = formula->Left->clone();
				ProofTreeAST::Sentence* rightRight = formula->Right->clone();
				rightLeft->IsNegated = !formula->Left->IsNegated;
				rightRight->IsNegated = !formula->Right->IsNegated;
				leftChild->getSentences()->push_back(leftLeft);
				leftChild->getSentences()->push_back(leftRight);
				rightChild->getSentences()->push_back(rightLeft);
				rightChild->getSentences()->push_back(rightRight);
				parent->getChildNodes()->push_back(leftChild);
				parent->getChildNodes()->push_back(rightChild);
				markForProcessing(leftChild);
				markForProcessing(rightChild);
			}
			break;
		}
	}
	else
	{
		switch (formula->Connective->Type)
		{
		case ProofTreeAST::ConnectiveType::Conjunction:
			{
				Tableaux* leftChild = new Tableaux(parent);
				Tableaux* rightChild = new Tableaux(parent);
				ProofTreeAST::Sentence* left = formula->Left->clone();
				ProofTreeAST::Sentence* right = formula->Right->clone();
				left->IsNegated = !formula->Left->IsNegated;
				right->IsNegated = !formula->Right->IsNegated;
				leftChild->getSentences()->push_back(left);
				rightChild->getSentences()->push_back(right);
				parent->getChildNodes()->push_back(leftChild);
				parent->getChildNodes()->push_back(rightChild);
				markForProcessing(leftChild);
				markForProcessing(rightChild);
			}
			break;
		case ProofTreeAST::ConnectiveType::Disjunction:
			{
				Tableaux* child = new Tableaux(parent);
				ProofTreeAST::Sentence* left = formula->Left->clone();
				ProofTreeAST::Sentence* right = formula->Right->clone();
				left->IsNegated = !formula->Left->IsNegated;
				right->IsNegated = !formula->Right->IsNegated;
				child->getSentences()->push_back(left);
				child->getSentences()->push_back(right);
				parent->getChildNodes()->push_back(child);
				markForProcessing(child);
			}
			break;
		case ProofTreeAST::ConnectiveType::Conditional:
			{
				Tableaux* child = new Tableaux(parent);
				ProofTreeAST::Sentence* antecedent = formula->Left->clone();
				ProofTreeAST::Sentence* conclusion = formula->Right->clone();
				conclusion->IsNegated = !formula->Right->IsNegated;
				child->getSentences()->push_back(antecedent);
				child->getSentences()->push_back(conclusion);
				parent->getChildNodes()->push_back(child);
				markForProcessing(child);
			}
			break;
		case ProofTreeAST::ConnectiveType::BiConditional:
			{
				Tableaux* leftChild = new Tableaux(parent);
				Tableaux* rightChild = new Tableaux(parent);
				ProofTreeAST::Sentence* leftLeft = formula->Left->clone();
				ProofTreeAST::Sentence* leftRight = formula->Right->clone();
				ProofTreeAST::Sentence* rightLeft = formula->Left->clone();
				ProofTreeAST::Sentence* rightRight = formula->Right->clone();
				leftRight->IsNegated = !formula->Left->IsNegated;
				rightLeft->IsNegated = !formula->Right->IsNegated;
				leftChild->getSentences()->push_back(leftLeft);
				leftChild->getSentences()->push_back(leftRight);
				rightChild->getSentences()->push_back(rightLeft);
				rightChild->getSentences()->push_back(rightRight);
				parent->getChildNodes()->push_back(leftChild);
				parent->getChildNodes()->push_back(rightChild);
				markForProcessing(leftChild);
				markForProcessing(rightChild);
			}
			break;
		}
		return false;
	}
}

void Tableaux::Solver::markForProcessing(Tableaux* node)
{
	_unprocessedNodes->insert(node);
	std::vector<ProofTreeAST::Sentence*>* sentences = node->getSentences();
	for (std::vector<ProofTreeAST::Sentence*>::iterator it = sentences->begin(); it != sentences->end(); it++)
	{
		ProofTreeAST::Sentence* sentence = *it;
		if (sentence->isComplex())
		{
			_unprocessedFormulae->push((ProofTreeAST::BinaryFormula*)sentence);
		}
		else
		{
			process(sentence, node);
		}
	}
}

bool Tableaux::Solver::hasContradition(ProofTreeAST::AtomicFormula* atom, Tableaux* parent)
{
	bool contradicts = false;
	while (parent != NULL)
	{
		for (std::vector<ProofTreeAST::Sentence*>::iterator it = parent->getSentences()->begin(); it != parent->getSentences()->end(); it++)
		{
			ProofTreeAST::Sentence* sentence = *it;
			if (!sentence->isComplex())
			{
				contradicts = atom->isNegation(sentence);
				if (contradicts)
				{
					break;
				}
			}
		}
		if (contradicts)
		{
			break;
		}
		parent = parent->getParent();
	}
	return contradicts;
}

bool Tableaux::Solver::belongsToBranch(ProofTreeAST::Sentence* sentence, Tableaux* node)
{
	bool belongs = false;
	while (node != NULL)
	{
		for (std::vector<ProofTreeAST::Sentence*>::iterator it = node->getSentences()->begin(); it != node->getSentences()->end(); it++)
		{
			ProofTreeAST::Sentence* s = *it;
			belongs = s == sentence;
			if (belongs)
			{
				break;
			}
		}
		if (belongs)
		{
			break;
		}
		node = node->getParent();
	}
	return belongs;
}

std::vector<Tableaux::Tableaux*>* Tableaux::Solver::getBelongingBranches(ProofTreeAST::Sentence* sentence)
{
	std::vector<Tableaux*>* nodes = new std::vector<Tableaux*>();
	for (std::set<Tableaux*>::iterator it = _unprocessedNodes->begin(); it != _unprocessedNodes->end(); it++)
	{
		Tableaux* branch = *it;
		if (!branch->isClosed() && belongsToBranch(sentence, branch))
		{
			nodes->push_back(branch);
		}
	}
	return nodes;
}

std::set<Tableaux::Tableaux*>* Tableaux::Solver::getOpenBranches()
{
	std::set<Tableaux*>* openBranches = new std::set<Tableaux*>();
	for (std::set<Tableaux*>::iterator it = _openBranches->begin(); it != _openBranches->end(); it++)
	{
		Tableaux* branch = *it;
		if (branch->getChildNodes()->size() == 0 && !branch->isClosed())
		{
			openBranches->insert(branch);
		}
	}
	return openBranches;
}