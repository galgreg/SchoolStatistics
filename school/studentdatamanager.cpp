#include "studentdatamanager.h"
#include <QFile>
StudentDataManager::StudentDataManager(
        QString fileName) : mFileName(fileName) {

}

QList<StudentInterface*> StudentDataManager::read() const {
    QList<StudentInterface*> students;
    QFile file(mFileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream inputStream(&file);
        while (!inputStream.atEnd()) {
            Student tempStudent;
            inputStream >> tempStudent;
            StudentInterface *student = new Student(std::move(tempStudent));
            students.push_back(student);
        }
        file.close();
    }
    return students;
}

QTextStream &operator>>(QTextStream &stream, Student &student)
{
    QString firstName, lastName;
    Gender gender;
    stream >> firstName >> lastName;
    char genderSign = ' ';
    stream >> genderSign;

    if (genderSign == 'F') {
        gender = FEMALE;
    } else if (genderSign == 'M') {
        gender = MALE;
    } else {
        gender = UNKNOWN;
    }
    student = Student(firstName, lastName, gender);

    while (!stream.atEnd()) {
        double grade;
        stream >> grade;
        student.addGrade(grade);
    }
    return stream;
}

void StudentDataManager::write(const QList<StudentInterface*> &students) {
    QFile file(mFileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outputStream(&file);
        for(auto student : students) {
            outputStream << *student << "\n";
        }
        file.close();
    }
}

QTextStream &operator<<(QTextStream &stream, const StudentInterface &student)
{
    stream << student.getFullName() << ' ';
    if (student.getGender() == FEMALE) {
        stream << 'F' << ' ';
    } else if (student.getGender() == MALE) {
        stream << 'M' << ' ';
    } else {
        stream << 'U' << ' ';
    }
    auto grades = student.getGrades();

    while(grades.first != grades.second) {
        stream << *grades.first++ << ' ';
    }
    stream << '\n';
    return stream;
}
