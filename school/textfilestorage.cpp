#include "textfilestorage.h"
#include <QFile>

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
    QString filePath = QString::fromStdString(getPath());
    QFile tempFile(filePath);
    return tempFile.exists();
}
