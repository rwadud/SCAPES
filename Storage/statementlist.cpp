#include "statementlist.h"

StatementList::StatementList()
{

}

StatementList::~StatementList(){
    for(int i=0; i<statements.size(); ++i){
        delete statements[i];
    }
}

Statement* StatementList::operator[](int i){
    return statements[i];
}

Statement* StatementList::get(int i){
    return statements[i];
}

void  StatementList::add(Statement* stmt){
    statements.push_back(stmt);
}

int StatementList::size(){
    return statements.size();
}
