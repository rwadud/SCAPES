#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "repositoryimplementor.h"
#include <QString>

// Storage Layer uses Bridge Design Pattern
// Interface Class
class Repository
{
public:
    Repository(RepositoryImplementor *imp);
    bool getSourceData(QString filename, QString *outData, QString *outErrTxt);
    bool setSourceData(QString filename, QString *inData, QString *outErrTxt);

private:
    RepositoryImplementor   *imp;
};

#endif // REPOSITORY_H
