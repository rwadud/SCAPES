#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
using namespace std;

class Statement
{
private:
    /* data */
public:
    Statement(/* args */);
    ~Statement();
    void compile(string);
    void run();
};


#endif