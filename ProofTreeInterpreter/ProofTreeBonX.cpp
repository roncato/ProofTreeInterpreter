#include "stdafx.h"
#include "ProofTreeBonX.h"
#include "ProofTreeVisitor.h"


namespace BON
{

IMPLEMENT_ABSTRACT_BONEXTENSION( ProofTreeBON::Sentence );
IMPLEMENT_BONEXTENSION( ProofTreeBON::Formula, "Formula" );
IMPLEMENT_BONEXTENSION( ProofTreeBON::Proposition, "Proposition" );
IMPLEMENT_BONEXTENSION( ProofTreeBON::Tree, "Tree" );
IMPLEMENT_ABSTRACT_BONEXTENSION( ProofTreeBON::Connective );
IMPLEMENT_BONEXTENSION( ProofTreeBON::BiConditional, "BiConditional" );
IMPLEMENT_BONEXTENSION( ProofTreeBON::Conditional, "Conditional" );
IMPLEMENT_BONEXTENSION( ProofTreeBON::Conjunction, "Conjunction" );
IMPLEMENT_BONEXTENSION( ProofTreeBON::Disjunction, "Disjunction" );
IMPLEMENT_BONEXTENSION( ProofTreeBON::Connection, "Connection" );


} // namespace BON

