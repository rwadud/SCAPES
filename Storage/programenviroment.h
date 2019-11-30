#ifndef PROGRAMENVIROMENT_H
#define PROGRAMENVIROMENT_H

#include <QHash>
#include "identifier.h"

//Provides an encapsulated QHashmap used to store program identifiers. Provides flags for jumps.
class ProgramEnviroment
{

private:
    QHash<QString, Identifier*> hash;
    int jmpFlag;
    int currStmtIndex;

public:
    ProgramEnviroment();
    ~ProgramEnviroment();
    void insert(QString &key, Identifier* id);
    void add(QString &key, Identifier* id);
    Identifier* get(QString &key);
    Identifier* find(QString &key);
    bool contains(QString &key);
    void setJmpFlag(int f);
    void setCurrStmtIndex(int i);
    int getJmpFlag();
    int getCurrStmtIndex();

};

#endif // PROGRAMENVIROMENT_H
