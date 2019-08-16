#include "igrades.h"

bool IGrades::operator==(const IGrades &gradesToCompare) const noexcept {
    bool comparisonResult = true;
    bool maxAllowedCountIsTheSame =
            this->maxAllowedCount() == gradesToCompare.maxAllowedCount();
    comparisonResult = (comparisonResult && maxAllowedCountIsTheSame);
    bool gradesCountIsTheSame =
            this->count() == gradesToCompare.count();
    comparisonResult = (comparisonResult && gradesCountIsTheSame);

    if(comparisonResult) {
        for (unsigned i = 0; i < this->count(); ++i) {
            bool gradeIsTheSame =
                    this->getGrade(i) == gradesToCompare.getGrade(i);
            comparisonResult = (comparisonResult && gradeIsTheSame);
        }
    }
    return comparisonResult;
}
