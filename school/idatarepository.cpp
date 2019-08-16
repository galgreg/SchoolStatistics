#include "idatarepository.h"

IDataRepository::IDataRepository(
            const QString &repositoryPath) noexcept :
                mRepositoryPath(repositoryPath) {

}

QString IDataRepository::getPath() noexcept {
    return mRepositoryPath;
}
