#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "student.h"
#include "studentdatamanager.h"
#include <QList>

class StudentList
{
public:
    explicit StudentList(const QString &fileName);

private:
    StudentDataManager mDataManager;
    QList<Student> mStudents;
};

#endif // STUDENTLIST_H
