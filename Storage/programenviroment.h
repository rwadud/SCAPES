#ifndef PROGRAMENVIROMENT_H
#define PROGRAMENVIROMENT_H

#include <QHash>
#include "identifier.h"
#include "cmpflag.h"

//Provides an encapsulated QHashmap used to store program identifiers. Provides flags for jumps.
class ProgramEnviroment
{

private:
    QHash<QString, Identifier*> hash;
    CmpFlag flag = NONE;
    int jmpIndex;
    bool terminated = false;

public:
    ProgramEnviroment();
    ~ProgramEnviroment();
    void insert(QString &key, Identifier* id);
    void add(QString &key, Identifier* id);
    Identifier* get(QString &key);
    Identifier* find(QString &key);
    bool contains(QString &key);
    CmpFlag getCmpFlag();
    void setCmpFlag(CmpFlag state);
    void clearCmpFlag();
    void setJmpIndex(int i);
    int getJmpIndex();
    bool isTerminated();
    void terminate();

};

#endif // PROGRAMENVIROMENT_H
