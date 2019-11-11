#include "statementlist.h"

StatementList::StatementList()
{

}

StatementList::~StatementList(){

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
