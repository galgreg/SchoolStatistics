#include "istudentclass.h"

bool IStudentClass::operator==(const IStudentClass &classToCompare) const noexcept {
    bool comparisonResult =
        (this->count() == classToCompare.count());
    if (comparisonResult) {
        for (size_t i = 0; i < this->count(); ++i) {
            bool tempComparison =
                    this->getStudent(i) == classToCompare.getStudent(i);
            comparisonResult = (comparisonResult && tempComparison);
        }
    }
    return comparisonResult;
}
