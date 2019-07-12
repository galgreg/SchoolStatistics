#include "istudent.h"

bool IStudent::operator==(const IStudent& studentToCompare) const {
    return this->getID() == studentToCompare.getID() &&
            this->getPersonalData() == studentToCompare.getPersonalData() &&
            this->getGrades() == studentToCompare.getGrades();
}
bool IStudent::operator!=(const IStudent& studentToCompare) const {
    return !(*this == studentToCompare);
}
