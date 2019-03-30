#ifndef STUDENTANALYZER_H
#define STUDENTANALYZER_H
#include "studentinterface.h"
#include "studentinfo.h"

class StatisticsGenerator
{
public:
    explicit StatisticsGenerator(const QList<StudentInterface*> &inputList);
    double getAverageForStudent(int whichStudent) const;
    double getAverageOfWholeClass() const;
    StudentInfo* getInfoAboutStudent(int whichStudent) const;
private:
    QList<StudentInterface*> students;
};

#endif // STUDENTANALYZER_H
