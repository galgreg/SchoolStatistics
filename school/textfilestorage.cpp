#include "textfilestorage.h"
#include "studentclass.h"
#include "student.h"
#include "studentfactory.h"
#include <QFile>
#include <QString>
#include <QTextStream>

TextFileStorage::TextFileStorage(
        const std::string &filePath) : IDataRepository(filePath) {

}

IStudentClass *TextFileStorage::read(
        size_t maxStudentCount,
        size_t maxGradesCount) {
    if (!exist()) {
        throw std::ios_base::failure("Cannot open file " + getPath());
    }
    QFile textFile(QString::fromStdString(getPath()));
    if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        IStudentClass *studentClass = new StudentClass(maxStudentCount);
        QTextStream textStream(&textFile);
        QString line;
        while (textStream.readLineInto(&line)) {
            unsigned maxGradesPerStudent = maxGradesCount;
            QStringList words = line.split(" ");
            unsigned studentID = words.takeFirst().toUInt();
            QString firstName = words.takeFirst();
            QString lastName = words.takeFirst();

            Gender gender;
            QString genderSymbol = words.takeFirst();
            if (genderSymbol == "M") {
                gender = MALE;
            } else if (genderSymbol == "F") {
                gender = FEMALE;
            } else if (genderSymbol == "U") {
                gender = UNKNOWN;
            } else {
                throw std::invalid_argument("TextFileStorage::read() error: "
                        "invalid value for student gender!");
            }

            std::vector<double> grades;
            while (!words.empty() && maxGradesPerStudent > 0) {
                QString gradeString = words.takeFirst();
                double newGrade = gradeString.toDouble();
                grades.push_back(newGrade);
                --maxGradesPerStudent;
            }
            IStudent *newStudent = StudentFactory::create(
                    studentID,
                    firstName.toStdString(),
                    lastName.toStdString(),
                    gender,
                    grades);
            studentClass->addStudent(newStudent);
            ++studentID;
        }
        return studentClass;
    } else {
        return nullptr;
    }
}

void TextFileStorage::write(const IStudentClass& /* studentClass */) {

}

bool TextFileStorage::exist() {
    QString filePath = QString::fromStdString(getPath());
    QFile tempFile(filePath);
    return tempFile.exists();
}
