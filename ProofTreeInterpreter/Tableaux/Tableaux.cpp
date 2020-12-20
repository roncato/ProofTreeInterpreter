#include "StdAfx.h"
#include "Tableaux.h"

Tableaux::Tableaux::Tableaux(Tableaux* parent)
{
	_childNodes = new std::vector<Tableaux*>();
	_sentences = new std::vector<ProofTreeAST::Sentence*>();
	_isClosed = false;
	_parent = parent;
}

Tableaux::Tableaux::~Tableaux()
{
	//delete _childNodes;
	//delete _sentences;
}

bool Tableaux::Tableaux::isClosed()
{
	return _isClosed;
}

void Tableaux::Tableaux::close()
{
	_isClosed = true;
}

Tableaux::Tableaux* Tableaux::Tableaux::getParent()
{
	return _parent;
}

void Tableaux::Tableaux::setParent(Tableaux* parent)
{
	_parent = parent;
}

std::vector<Tableaux::Tableaux*>* Tableaux::Tableaux::getChildNodes()
{
	return _childNodes;
}

std::vector<ProofTreeAST::Sentence*>* Tableaux::Tableaux::getSentences()
{
	return _sentences;
}

std::string Tableaux::Tableaux::toString()
{
	std::stringstream ss;
	int i = 0;
	std::vector<ProofTreeAST::Sentence*>* sentences = getSentences();
	ss << "(";
	for (std::vector<ProofTreeAST::Sentence*>::iterator it = sentences->begin(); it != sentences->end(); it++)
	{
		ProofTreeAST::Sentence* sentence = *it;
		ss << sentence->toString();
		if (i < sentences->size() - 1)
		{
			ss << " & ";
		}
		i++;
	}
	ss << ")";
	ss << "\n";
	i = 0;
	std::vector<Tableaux*>* nodes = getChildNodes();
	for (std::vector<Tableaux*>::iterator it = nodes->begin(); it != nodes->end(); it++)
	{
		Tableaux* node = *it;
		if (nodes->size() == 1)
		{
			ss << "|";
			ss << "\n";
		}
		if (i == 0)
		{
			ss << "/";
			ss << "\n";
		}
		else
		{
			ss << "\\";
			ss << "\n";
		}
		ss << node->toString();
		i++;
	}
	return ss.str();
}

std::vector<ProofTreeAST::AtomicFormula*>* Tableaux::Tableaux::getBranchAtoms()
{
	std::vector<ProofTreeAST::AtomicFormula*>* atoms = new std::vector<ProofTreeAST::AtomicFormula*>();
	this->getBranchAtoms(atoms);
	return atoms;
}

void Tableaux::Tableaux::getBranchAtoms(std::vector<ProofTreeAST::AtomicFormula*>* atoms)
{
	std::vector<ProofTreeAST::Sentence*>* sentences = getSentences();
	for (std::vector<ProofTreeAST::Sentence*>::iterator it = sentences->begin(); it != sentences->end(); it++)
	{
		ProofTreeAST::Sentence* sentence = *it;
		if (!sentence->isComplex() && !isContained(atoms, (ProofTreeAST::AtomicFormula*)sentence))
		{
			atoms->push_back((ProofTreeAST::AtomicFormula*)sentence);
		}
	}
	if (_parent != NULL)
	{
		_parent->getBranchAtoms(atoms);
	}
}

bool Tableaux::Tableaux::isContained(std::vector<ProofTreeAST::AtomicFormula*>* atoms, ProofTreeAST::AtomicFormula* atom)
{
	bool isContained = false;
	for (std::vector<ProofTreeAST::AtomicFormula*>::iterator it = atoms->begin(); it != atoms->end(); it++)
	{
		ProofTreeAST::AtomicFormula* a = *it;
		if (atom->equals(a))
		{
			isContained = true;
			break;
		}
	}
	return isContained;
}