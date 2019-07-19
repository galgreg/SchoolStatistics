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

std::unique_ptr<IStudentClass> TextFileStorage::read(
        size_t maxStudentCount,
        size_t maxGradesCount) {
    if (!exist()) {
        throw std::ios_base::failure("TextFileStorage::read() error: "
                "Cannot open file " + getPath() +
                " (file does not exist)");
    }
    QFile textFile(QString::fromStdString(getPath()));
    if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::unique_ptr<IStudentClass> studentClass(
                    new StudentClass(maxStudentCount));
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

            std::vector<double> grades;
            while (!words.empty() && maxGradesPerStudent > 0) {
                QString gradeString = words.takeFirst();
                double newGrade = gradeString.toDouble();
                grades.push_back(newGrade);
                --maxGradesPerStudent;
            }
            std::unique_ptr<IStudent> newStudent(StudentFactory::create(
                    studentID,
                    firstName.toStdString(),
                    lastName.toStdString(),
                    gender,
                    grades));
            studentClass->addStudent(std::move(newStudent));
        }
        return studentClass;
    } else {
        return nullptr;
    }
}

void TextFileStorage::write(const IStudentClass& studentClass) {
    QFile fileStorage(QString::fromStdString(getPath()));
    if (fileStorage.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outputStream(&fileStorage);
        for (size_t i = 0; i < studentClass.count(); ++i) {
            const auto& student = studentClass.getStudent(i);
            const auto& studentPersonalData = student.getPersonalData();
            const auto& studentGrades = student.getGrades();

            QString studentFirstName =
                    QString::fromStdString(studentPersonalData.getFirstName());
            QString studentLastName =
                    QString::fromStdString(studentPersonalData.getLastName());
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
    QString filePath = QString::fromStdString(getPath());
    QFile tempFile(filePath);
    return tempFile.exists();
}
