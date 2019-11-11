#ifndef FLATFILEIMP_H
#define FLATFILEIMP_H

#include "repositoryimplementor.h"
#include <QObject>

// Concrete Implementor
// Currently only FlatFile implementation is done.
// NOTE: In future, other concrete implementors will be added.

class FlatFileImp : public RepositoryImplementor
{
public:
    FlatFileImp();
    ~FlatFileImp();
    bool getSourceData(QString filename, QString *inData, QString *outErrTxt);
    bool setSourceData(QString filename, QString *outData, QString *outErrTxt);
};

#endif // FLATFILEIMP_H
