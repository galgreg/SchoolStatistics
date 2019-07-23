#include "idatarepository.h"

IDataRepository::IDataRepository(
            const QString &repositoryPath) :
                mRepositoryPath(repositoryPath) {

}

IDataRepository::~IDataRepository() {

}

QString IDataRepository::getPath() {
    return mRepositoryPath;
}


