#include "textfilestorage.h"
#include "studentclass.h"
#include "student.h"
#include "studentfactory.h"
#include <QFile>
#include <QString>
#include <QTextStream>

TextFileStorage::TextFileStorage(
        const QString &filePath) : IDataRepository(filePath) {

}

std::unique_ptr<IStudentClass> TextFileStorage::read(
        size_t maxStudentCount,
        size_t maxGradesCount) {
    if (!exist()) {
        QString errorMessage =
                QString("TextFileStorage::read() error: "
                        "Cannot open file %1 (file does not exist)")
                        .arg(getPath());

        throw std::ios_base::failure(errorMessage.toStdString());
    }
    QFile textFile(getPath());
    if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        auto studentClass = std::make_unique<StudentClass>(maxStudentCount);
        QTextStream textStream(&textFile);
        QString line;
        while (textStream.readLineInto(&line)) {
            size_t maxGradesPerStudent = maxGradesCount;
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

            QList<double> grades;
            while (!words.empty() && maxGradesPerStudent > 0) {
                QString gradeString = words.takeFirst();

                bool conversionSucceed = false;
                double newGrade = gradeString.toDouble(&conversionSucceed);

                if (conversionSucceed) {
                    grades.push_back(newGrade);
                    --maxGradesPerStudent;
                }
            }
            std::unique_ptr<IStudent> newStudent(
                    StudentFactory::create(
                            studentID,
                            firstName,
                            lastName,
                            gender,
                            grades));
            studentClass->addStudent(std::move(newStudent));
        }
        return std::move(studentClass);
    } else {
        return nullptr;
    }
}

void TextFileStorage::write(const IStudentClass& studentClass) {
    QFile fileStorage(getPath());
    if (fileStorage.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outputStream(&fileStorage);
        for (size_t i = 0; i < studentClass.count(); ++i) {
            const auto& student = studentClass.getStudent(i);
            const auto& studentPersonalData = student.getPersonalData();
            const auto& studentGrades = student.getGrades();

            QString studentFirstName = studentPersonalData.getFirstName();
            QString studentLastName = studentPersonalData.getLastName();
            Gender studentGender = studentPersonalData.getGender();
            QString studentGenderSymbol;

            if (studentGender == MALE) {
                studentGenderSymbol = "M";
            } else if (studentGender == FEMALE) {
                studentGenderSymbol = "F";
            } else {
                studentGenderSymbol = "U";
            }

            QString studentGradeList = "";
            for (unsigned k = 0; k < studentGrades.count(); ++k) {
                studentGradeList +=
                        QString::number(studentGrades.getGrade(k), 'f', 1) + " ";
            }

            QString outputLine = QString("%1 %2 %3 %4 %5\n")
                    .arg(student.getID())
                    .arg(studentFirstName)
                    .arg(studentLastName)
                    .arg(studentGenderSymbol)
                    .arg(studentGradeList);
            outputStream << outputLine;
        }
    }
}

bool TextFileStorage::exist() {
    QFile tempFile(getPath());
    return tempFile.exists();
}
