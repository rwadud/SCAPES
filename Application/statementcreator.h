#include "creator.h"
#include "dcistatement.h"
#include "dcastatement.h"
#include "rdistatement.h"
#include "addstatement.h"
#include "jmpstatement.h"
#include "jmrstatement.h"
#include "jlsstatement.h"
#include "jeqstatement.h"
#include "endstatement.h"
#include "cmpstatement.h"
#include "movstatement.h"
#include "prtstatement.h"


//Concrete factory method implementor
class StatementCreator: public Creator
{
public:
    virtual Statement* Create(QString &instr); //create appropriate statements based on instruction
};

