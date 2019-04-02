#include "idatarepository.h"

IDataRepository::IDataRepository(
            const std::string &repositoryPath) :
                mRepositoryPath(repositoryPath) {

}

IDataRepository::~IDataRepository() {

}

std::string IDataRepository::getPath() {
    return mRepositoryPath;
}


