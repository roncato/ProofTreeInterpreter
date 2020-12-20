#ifndef Connective_H
#define Connective_H

#include "AbstractSyntaxTree.h"

namespace ProofTreeAST
{
	enum ConnectiveType
	{
		Conjunction,
		Disjunction,
		Conditional,
		BiConditional
	};
	class Connective : public AbstractSyntaxTree
	{
	public:
		Connective();
		Connective(ConnectiveType);
		ConnectiveType Type;
		std::string toString();
		Connective* clone();
	};
}

#endif