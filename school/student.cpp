#include "student.h"
#include "idgenerator.h"

Student::Student() : hisFirstName(""), hisLastName(""), hisGender(UNKNOWN) {

}

Student::Student(
        QString firstName,
        QString lastName,
        Gender gender) :
            hisFirstName(firstName),
            hisLastName(lastName),
            hisGender(gender),
            hisFinalGrade(0.0)
{
    ID = IDGenerator::instance()->next();
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

Student::GradesRange Student::getGrades() const
{
    auto begin = hisGrades.cbegin();
    auto end = hisGrades.cend();
    return std::make_pair(begin, end);
}

double Student::getGradesAverage() const {
    int howMuchGrades = hisGrades.size();
    double sum = 0.0;

    for(auto grade : hisGrades) {
        sum += grade;
    }
    return sum / howMuchGrades;
}

QString Student::getFullName() const {
    return QString("%1 %2").arg(hisFirstName).arg(hisLastName);
}

Gender Student::getGender() const {
    return hisGender;
}

unsigned Student::getID() const {
    return ID;
}
