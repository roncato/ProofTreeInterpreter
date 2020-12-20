#include "StdAfx.h"
#include "Parser.h"

 ProofTreeAST::AbstractSyntaxTree* ProofTreeAST::Parser::parse(ProofTreeBON::Tree* tree)
 {

	std::set<ProofTreeBON::Formula> set = (*tree)->getFormula();
	ProofTreeBON::Sentence sentence;
	ProofTreeAST::Sentence* left;
	ProofTreeAST::Sentence* right;

	bool first = true;
	for (std::set<ProofTreeBON::Formula>::iterator it = set.begin(); it != set.end(); it++)
	{
		if (first)
		{
			sentence = *it;

			// Parses First Sentence
			left = (ProofTreeAST::Sentence*)parseSentence(sentence);
			first = false;
		}
		else
		{
			sentence = *it;

			// Parses Right Sentence
			right = (ProofTreeAST::Sentence*)parseSentence(sentence);

			// Creates Binary Sentence
			ProofTreeAST::Connective* connective = new ProofTreeAST::Connective(ConnectiveType::Conjunction);
			left = new ProofTreeAST::BinaryFormula(left, right, connective);
		}
	}
	return left;
 }

ProofTreeAST::AbstractSyntaxTree* ProofTreeAST::Parser::parseSentence(ProofTreeBON::Sentence& sentence)
{
	ProofTreeAST::Sentence* astSentence;
	if (sentence->getFCOMeta().name() == "Formula")
	{
		astSentence = (ProofTreeAST::Sentence*)parseFormula((ProofTreeBON::Formula)sentence);
		std::set<BON::FCO> fcos = ((ProofTreeBON::Formula)sentence)->getChildFCOs();
		if (fcos.size() > 1)
		{
			astSentence->IsNegated = sentence->isIsNegated();
		}
		else
		{
			ProofTreeBON::Sentence child = (ProofTreeBON::Sentence)*fcos.begin();
			astSentence->IsNegated = child->isIsNegated() != sentence->isIsNegated(); 
		}
	}
	else
	{
		astSentence = (ProofTreeAST::Sentence*)parseProposition((ProofTreeBON::Proposition)sentence);
		astSentence->IsNegated = sentence->isIsNegated();
	}
	return astSentence;
}

ProofTreeAST::AbstractSyntaxTree* ProofTreeAST::Parser::parseFormula(ProofTreeBON::Formula& formula)
{

	ProofTreeAST::Sentence* left;
	ProofTreeAST::Sentence* right;
	ProofTreeBON::Sentence sentence;
	ProofTreeBON::BONNode* initial = getInitial(formula->getFormula());

	if (!initial)
	{
		initial = getInitial((formula)->getProposition());
	}

	sentence = initial->Value;	
	// Parses First Sentence
	left = (ProofTreeAST::Sentence*)parseSentence(sentence);
	std::multiset<ProofTreeBON::Connective> Connectives = ((ProofTreeBON::Sentence)initial->Value)->getConnectionDsts();
	
	while (Connectives.size() > 0)
	{
		
		// Parses Connective
		ProofTreeBON::Connective Connective = *Connectives.begin();
		ProofTreeAST::Connective* c = (ProofTreeAST::Connective*)parseConnective(Connective);
		// Gets Next Sentence
		sentence = *Connective->getConnectionDsts().begin();

		// Parses Right Formula
		right = (ProofTreeAST::Sentence*)parseSentence(sentence);

		// Instantiates Binary Formula
		left = new ProofTreeAST::BinaryFormula(left, right, c);

		// Gets Next Connectives
		Connectives = sentence->getConnectionDsts();
	}

	return left;
}

ProofTreeAST::AbstractSyntaxTree* ProofTreeAST::Parser::parseProposition(ProofTreeBON::Proposition& proposition)
{
	ProofTreeAST::AtomicFormula* as = new AtomicFormula();
	as->Name = proposition->getName();
	return as;
}

ProofTreeAST::AbstractSyntaxTree* ProofTreeAST::Parser::parseConnective(ProofTreeBON::Connective& Connective)
{
	ProofTreeAST::Connective* c = new ProofTreeAST::Connective();
	std::string metaName = Connective->getFCOMeta().name();
	if (metaName == "Conjunction")
	{
		c->Type = ProofTreeAST::ConnectiveType::Conjunction;
	}
	else if (metaName == "Disjunction")
	{
		c->Type = ProofTreeAST::ConnectiveType::Disjunction;
	}
	else if (metaName == "Conditional")
	{
		c->Type = ProofTreeAST::ConnectiveType::Conditional;
	}
	else
	{
		c->Type = ProofTreeAST::ConnectiveType::BiConditional;
	}
	return c;
}

ProofTreeBON::BONNode* ProofTreeAST::Parser::getInitial(std::set<ProofTreeBON::Proposition>& set)
{
	ProofTreeBON::BONNode* node = NULL;
	for (std::set<ProofTreeBON::Proposition>::iterator it = set.begin(); it != set.end(); it++)
	{
		if ((*it)->getConnectionSrcs().size() == 0)
		{
			node = new ProofTreeBON::BONNode(*it);
			break;
		}
	}
	return node;
}

ProofTreeBON::BONNode* ProofTreeAST::Parser::getInitial(std::set<ProofTreeBON::Formula>& set)
{
	ProofTreeBON::BONNode* node = NULL;
	for (std::set<ProofTreeBON::Formula>::iterator it = set.begin(); it != set.end(); it++)
	{
		if ((*it)->getConnectionSrcs().size() == 0)
		{
			node = new ProofTreeBON::BONNode(*it);
			break;
		}
	}
	return node;
}