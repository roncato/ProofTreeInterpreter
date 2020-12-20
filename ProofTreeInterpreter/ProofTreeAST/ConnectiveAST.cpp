#include "StdAfx.h"
#include "Connective.h"

ProofTreeAST::Connective::Connective()
{
}

ProofTreeAST::Connective::Connective(ProofTreeAST::ConnectiveType type)
{
	Type = type;
}

std::string ProofTreeAST::Connective::toString()
{
	std::string str;
	switch (Type)
	{
	case ProofTreeAST::ConnectiveType::Conjunction:
		str = "&";
		break;
	case ProofTreeAST::ConnectiveType::Disjunction:
		str = "|";
		break;
	case ProofTreeAST::ConnectiveType::Conditional:
		str = "=>";
		break;
	case ProofTreeAST::ConnectiveType::BiConditional:
		str = "<=>";
		break;
	}
	return str;
}

ProofTreeAST::Connective* ProofTreeAST::Connective::clone()
{
	ProofTreeAST::Connective* clone = new ProofTreeAST::Connective();
	clone->Type = Type;
	return clone;
}