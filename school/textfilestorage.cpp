#include "textfilestorage.h"
#include "studentclass.h"
#include <QFile>

TextFileStorage::TextFileStorage(
        const std::string &filePath) : IDataRepository(filePath) {

}

IStudentClass *TextFileStorage::read(
        size_t maxStudentCount,
        size_t maxGradesCount) {
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
