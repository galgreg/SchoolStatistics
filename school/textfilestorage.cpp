#include "textfilestorage.h"
#include <fstream>

TextFileStorage::TextFileStorage(
        const std::string &filePath) : IDataRepository(filePath) {

}

IStudentClass *TextFileStorage::read() {
    if (!exist()) {
        throw std::ios_base::failure("Cannot open file " + getPath());
    }
    return nullptr;
}

void TextFileStorage::write(IStudentClass * /* studentClass */) {

}

bool TextFileStorage::exist() {
    return static_cast<bool>(std::ifstream(getPath()));
}
