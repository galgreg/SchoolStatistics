#include "student.h"
#include "idgenerator.h"

Student::Student() :
        ID(0),
        hisFirstName(""),
        hisLastName(""),
        hisGender(UNKNOWN) {

}

Student::Student(
        QString firstName,
        QString lastName,
        Gender gender) :
            hisFirstName(firstName),
            hisLastName(lastName),
            hisGender(gender) {
    ID = IDGenerator::instance()->next();
}

unsigned Student::getID() const {
    return ID;
}

QString Student::getFullName() const {
    QString fullName = QString("%1 %2").arg(hisFirstName).arg(hisLastName);
    return fullName.trimmed();
}

Gender Student::getGender() const {
    return hisGender;
}

Student::GradesRange Student::getGrades() const
{
    auto begin = hisGrades.cbegin();
    auto end = hisGrades.cend();
    return std::make_pair(begin, end);
}

double Student::getGradesAverage() const {
    int howMuchGrades = hisGrades.size();
    if (howMuchGrades == 0) {
        return 0.0;
    }
    double sum = 0.0;

    for(auto grade : hisGrades) {
        sum += grade;
    }
    return sum / howMuchGrades;
}

void Student::addGrade(double grade)
{
    hisGrades.push_back(grade);
}

void Student::editGrade(int whichGrade, double newGrade) {
    hisGrades.replace(whichGrade, newGrade);
}

void Student::removeGrade(int whichGrade) {
    hisGrades.removeAt(whichGrade);
}

