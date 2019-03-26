#include "student.h"
#include "idgenerator.h"

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

double Student::getAverage()
{
    int howMuchGrades = hisGrades.size();
    double sum = 0.0;

    for(auto grade : hisGrades) {
        sum += grade;
    }
    return sum / howMuchGrades;
}
