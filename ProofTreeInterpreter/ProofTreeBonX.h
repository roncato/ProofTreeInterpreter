#ifndef PROOFTREEBONX_H
#define PROOFTREEBONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

///BUP
// add your include files/class definitions here
///EUP

namespace ProofTreeBON { class ProofTreeVisitor; }
namespace ProofTreeBON {    DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, SentenceImpl, Sentence ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION2( BON::Model, Sentence, FormulaImpl, Formula ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION2( BON::Atom, Sentence, PropositionImpl, Proposition ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION( BON::Model, TreeImpl, Tree ); }
namespace ProofTreeBON {    DECLARE_ABSTRACT_BONEXTENSION( BON::Atom, ConnectiveImpl, Connective ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION( Connective, BiConditionalImpl, BiConditional ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION( Connective, ConditionalImpl, Conditional ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION( Connective, ConjunctionImpl, Conjunction ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION( Connective, DisjunctionImpl, Disjunction ); }
namespace ProofTreeBON {    DECLARE_BONEXTENSION( BON::Connection, ConnectionImpl, Connection ); }


#include "ProofTreeBON/Sentence.h"
#include "ProofTreeBON/Formula.h"
#include "ProofTreeBON/Proposition.h"
#include "ProofTreeBON/Tree.h"
#include "ProofTreeBON/Connective.h"
#include "ProofTreeBON/BiConditional.h"
#include "ProofTreeBON/Conditional.h"
#include "ProofTreeBON/Conjunction.h"
#include "ProofTreeBON/Disjunction.h"
#include "ProofTreeBON/Connection.h"

#include "ProofTreeVisitor.h"

///BUP
// add your additional class definitions here
///EUP

#endif // PROOFTREEBONX_H
