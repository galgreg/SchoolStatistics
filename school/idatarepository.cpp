#include "idatarepository.h"

IDataRepository::IDataRepository(
            const QString &repositoryPath) :
                mRepositoryPath(repositoryPath) {

}

QString IDataRepository::getPath() {
    return mRepositoryPath;
}
