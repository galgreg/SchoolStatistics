#ifndef STUDENTANALYZER_H
#define STUDENTANALYZER_H
#include "student.h"
#include "studentinfo.h"

class StatisticsGenerator
{
public:
    explicit StatisticsGenerator(const QList<Student> &inputList);
    double getAverageForStudent(int whichStudent) const;
    double getAverageOfWholeClass() const;
    StudentInfo* getInfoAboutStudent(int whichStudent) const;
private:
    QList<Student> students;
};

#endif // STUDENTANALYZER_H
