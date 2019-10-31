#ifndef REPOSITORYIMPLEMENTOR_H
#define REPOSITORYIMPLEMENTOR_H
#include <QString>

class RepositoryImplementor
{
public:
    RepositoryImplementor();
    virtual bool getSourceData(QString filename, QString *outData, QString *outErrTxt) = 0;
    virtual bool setSourceData(QString filename, QString *inData, QString *outErrTxt) = 0;
};

#endif // REPOSITORYIMPLEMENTOR_H
