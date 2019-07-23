#ifndef GRADES_H
#define GRADES_H

#include "igrades.h"
#include <QList>

class Grades : public IGrades
{
public:
    Grades(const IGrades &);
    explicit Grades(
        size_t maximumCount = 3,
        const QList<double> &grades = {});

    void add(double grade) override;
    void remove(size_t whichGrade) override;
    void edit(size_t whichGrade, double newValue) override;
    size_t count() const override;
    double getGrade(size_t whichGrade) const override;
    size_t maxAllowedCount() const override;
private:
    QList<double> mGrades;
    const size_t mMaxCount;
};

#endif // GRADES_H
