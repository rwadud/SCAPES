#include "repository.h"

Repository::Repository(RepositoryImplementor *impRef)
{
    imp = impRef;
}

bool Repository::getSourceData(QString filename, QString *outData, QString *outErrTxt)
{
    return imp->getSourceData(filename, outData, outErrTxt);
}
bool Repository::setSourceData(QString filename, QString *inData, QString *outErrTxt)
{
    return imp->setSourceData(filename, inData, outErrTxt);
}
