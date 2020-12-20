#include "StdAfx.h"
#include "TableauxRenderer.h"

std::string Tableaux::TableauxRenderer::_renderHTML(Tableaux* parent)
{
	std::stringstream ss;
	std::vector<ProofTreeAST::Sentence*>* sentences = parent->getSentences();
	ss << "<table align='center'><tr><td colspan='2' nowrap='nowrap'>";
	ss << "<table align='center'>";
	for (std::vector<ProofTreeAST::Sentence*>::iterator it = sentences->begin(); it != sentences->end(); it++)
	{
		ProofTreeAST::Sentence* sentence = *it;
		ss << "<tr>";
		if (sentence->isComplex()&& sentence->Id > 0)
		{
			ss << "<td>" << sentence->Id << ".&nbsp" << "</td>";
		}
		else
		{
			ss << "<td>&nbsp</td>";
		}
		ss << "<td nowrap='nowrap' align='center'><span style='font:20px bold;'>";
		ss << sentence->toString();
		ss << "</span></td></tr>";
	}
	ss << "</table>";
	ss << "</td></tr>";
	std::vector<Tableaux*>* nodes = parent->getChildNodes();
	if (nodes->size() == 0)
	{
		if (parent->isClosed())
		{
			ss << "<tr><td align='center' valign='top'><span style='font:15px bold; color:red'>X</span></td></tr>";
		}
		else
		{
			ss << "<tr><td valign='top'><span style='font:15px bold; color:green'>O</span></td></tr>";
		}
	}
	if (nodes->size() == 1)
	{
		Tableaux* node = *nodes->begin();
		ss << "<tr class='singleBranch'><td style='font-size:20px;font-weight:3px' colspan='2' align='center'>|</td></tr><tr><td>";
		ss << _renderHTML(node);
		ss << "</td></tr>";
	}
	else if (nodes->size() > 1)
	{
		ss << "<tr><td>";
		ss << "<table><tr><td align='center' valign='top' nowrap='nowrap' colspan='2'>";
		ss << "<table cellspacing='0' cellpadding='5' class='singleBranch'><tr class='singleBranch'><td style='text-align:right;' width='50%'><span style='font:30px bold;'>&#47</span></td><td style='text-align:left;' width='50%'><span style='font:30px bold;'>&#92</span></td></tr></tr></table>";
		ss << "</td></tr><tr>";
		for (std::vector<Tableaux*>::iterator it = nodes->begin(); it != nodes->end(); it++)
		{
			Tableaux* node = *it;
			ss << "<td valign='top' nowrap='nowrap'>";
			ss << _renderHTML(node);
			ss << "</td>";
		}
		ss << "</tr></table>";
		ss << "</td></tr>";
	}
	ss << "</table>";
	return ss.str();
}

std::string Tableaux::TableauxRenderer::renderHTML(Tableaux* parent, std::set<Tableaux*>* openBranches)
{
	std::stringstream ss;
	ss << "<!DOCTYPE html><html><head><title>Proof Tree</title></head><body>";
	ss << "<p style='font:30px bold' align='center'>Tableaux</p>";
	ss << _renderHTML(parent);
	ss << "<p style='font:30px bold' align='center'>Models</p>";
	ss << renderInterpretations(openBranches);
	ss << "</body></html>";
	return ss.str();
}

std::string Tableaux::TableauxRenderer::renderXML(Tableaux* parent)
{
	std::stringstream ss;
	ss << "<?xml version='1.0' encoding='utf-8'?><tree>";
	ss << _renderXML(parent);
	ss << "</tree>";
	return ss.str();
}

std::string Tableaux::TableauxRenderer::_renderXML(Tableaux* parent)
{
	std::stringstream ss;
	std::vector<ProofTreeAST::Sentence*>* sentences = parent->getSentences();
	ss << "<node>";
	ss << "<sentences>";
	for (std::vector<ProofTreeAST::Sentence*>::iterator it = sentences->begin(); it != sentences->end(); it++)
	{
		ss << "<sentence>";
		ss << renderXML(*it);
		ss << "</sentence>";
	}
	ss << "</sentences>";
	ss << "<nodes>";
	std::vector<Tableaux*>* nodes = parent->getChildNodes();
	for (std::vector<Tableaux*>::iterator it = nodes->begin(); it != nodes->end(); it++)
	{
		ss << _renderXML(*it);
	}
	ss << "</nodes>";
	ss << "</node>";
	return ss.str();
}

std::string Tableaux::TableauxRenderer::renderXML(ProofTreeAST::AtomicFormula* formula)
{
	std::stringstream ss;
	ss << "<proposition name='" << formula->Name << "'></proposition>";
	return ss.str();
}

std::string Tableaux::TableauxRenderer::renderXML(ProofTreeAST::BinaryFormula* formula)
{
	std::stringstream ss;
	switch (formula->Connective->Type)
	{
	case ProofTreeAST::Conjunction:
		ss << "<conjunction>" << renderXML(formula->Left) << renderXML(formula->Right) << "</conjunction>";
		break;
	case ProofTreeAST::Disjunction:
		ss << "<disjunction>" << renderXML(formula->Left) << renderXML(formula->Right) << "</disjunction>";
		break;
	case ProofTreeAST::Conditional:
		ss << "<conditional>" << "<antecedent>" << renderXML(formula->Left) << "</antecedent>" << "<conclusion>" << renderXML(formula->Right) << "</conclusion>" << "</conditional>";
		break;
	case ProofTreeAST::BiConditional:
		ss << "<biconditional>" << renderXML(formula->Left) << renderXML(formula->Right) << "</biconditional>";
		break;
	}
	return ss.str();
}

std::string Tableaux::TableauxRenderer::renderXML(ProofTreeAST::Sentence* sentence)
{
	std::stringstream ss;
	if (sentence->IsNegated)
	{
		ss << "<negation>";
	}
	if (sentence->isComplex())
	{
		ss << renderXML((ProofTreeAST::BinaryFormula*)sentence);
	}
	else
	{
		ss << renderXML((ProofTreeAST::AtomicFormula*)sentence);
	}
	if (sentence->IsNegated)
	{
		ss << "</negation>";
	}
	return ss.str();
}

std::string Tableaux::TableauxRenderer::renderInterpretations(std::set<Tableaux*>* branches)
{
	std::stringstream ss;
	ss << "<table cellspacing='0' cellpadding='5' class='interpretations' align='center' border='1'>";
	std::vector<ProofTreeAST::AtomicFormula*>* atoms;
	int i = 1;
	for (std::set<Tableaux*>::iterator it = branches->begin(); it != branches->end(); it++)
	{
		Tableaux* branch = *it;
		if (i == 1)
		{
			atoms = branch->getBranchAtoms();
			ss << "<tr><th>Model</th>";
			for (std::vector<ProofTreeAST::AtomicFormula*>::iterator it = atoms->begin(); it != atoms->end(); it++)
			{
				ProofTreeAST::AtomicFormula* atom = *it;
				ss << "<th>";
				bool isNegated = atom->IsNegated;
				atom->IsNegated = false;
				ss << atom->toString();
				atom->IsNegated = isNegated;
				ss << "</th>";
			}
			ss << "</tr>";
		}
		ss << "<tr>";
		ss << "<td>" << i << "</td>";
		ss << renderInterpretations(atoms, branch);
		ss << "</tr>";
		i++;
	}
	ss << "</table>";
	return ss.str();
}

std::string Tableaux::TableauxRenderer::renderInterpretations(std::vector<ProofTreeAST::AtomicFormula*>* atoms, Tableaux* branch)
{
	std::stringstream ss;
	std::vector<ProofTreeAST::AtomicFormula*>* interpreations = branch->getBranchAtoms();
	for (std::vector<ProofTreeAST::AtomicFormula*>::iterator it = atoms->begin(); it != atoms->end(); it++)
	{
		ProofTreeAST::AtomicFormula* atom = *it;
		for (std::vector<ProofTreeAST::AtomicFormula*>::iterator it = interpreations->begin(); it != interpreations->end(); it++)
		{
			ProofTreeAST::AtomicFormula* interpretation = *it;
			if (atom->equals(interpretation) || atom->isNegation(interpretation))
			{
				ss << "<td>" << !interpretation->IsNegated << "</td>";
				break;
			}
		}
	}
	return ss.str();
}