#include "repository.h"

// The concrete Implementor(e.g. FlatFile) object is bound to the interface
// (Repositority) object

Repository::Repository(RepositoryImplementor *impRef)
{
    imp = impRef;
}

// GetSourceData and SetSourceData operations are delegated to the Concrete
// Implementor object, which does the actual work.

bool Repository::getSourceData(QString filename, QString *outData, QString *outErrTxt)
{
    return imp->getSourceData(filename, outData, outErrTxt);
}
bool Repository::setSourceData(QString filename, QString *inData, QString *outErrTxt)
{
    return imp->setSourceData(filename, inData, outErrTxt);
}
