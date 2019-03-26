#include "student.h"
#include "idgenerator.h"

Student::Student(
        QString firstName,
        QString lastName,
        Gender gender) : hisFirstName(firstName), hisLastName(lastName), hisGender(gender)
{
    ID = IDGenerator::instance()->next();
}
