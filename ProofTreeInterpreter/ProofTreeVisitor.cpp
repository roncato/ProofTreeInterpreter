#include "stdafx.h"
#include "ProofTreeVisitor.h"


namespace ProofTreeBON
{

ProofTreeVisitor::ProofTreeVisitor()  { }

ProofTreeVisitor::~ProofTreeVisitor() { }

void* ProofTreeVisitor::visitBiConditional(const ProofTreeBON::BiConditional& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitConditional(const ProofTreeBON::Conditional& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitConjunction(const ProofTreeBON::Conjunction& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitConnective(const ProofTreeBON::Connective& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitDisjunction(const ProofTreeBON::Disjunction& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitProposition(const ProofTreeBON::Proposition& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitFormula(const ProofTreeBON::Formula& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitTree(const ProofTreeBON::Tree& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitConnection(const ProofTreeBON::Connection& object)
{
	return NULL;
}


void* ProofTreeVisitor::visitSentence(const ProofTreeBON::Sentence& object)
{
	return NULL;
}



} // namespace

