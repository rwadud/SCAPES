#ifndef FLATFILEIMP_H
#define FLATFILEIMP_H

#include "repositoryimplementor.h"
#include <QObject>

class FlatFileImp : public RepositoryImplementor
{
public:
    FlatFileImp();
    ~FlatFileImp();
    bool getSourceData(QString filename, QString *inData, QString *outErrTxt);
    bool setSourceData(QString filename, QString *outData, QString *outErrTxt);
};

#endif // FLATFILEIMP_H
