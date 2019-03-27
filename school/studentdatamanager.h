#ifndef STUDENTDATAMANAGER_H
#define STUDENTDATAMANAGER_H

#include "student.h"
#include <QList>
#include <QString>
#include <QTextStream>

class StudentDataManager
{
public:
    StudentDataManager(QString fileName);
    QList<Student> read();
    void write(const QList<Student> &students);
private:
    QString mFileName;
};

QTextStream& operator<<(QTextStream &stream, const Student &student);
QTextStream& operator>>(QTextStream &stream, Student &student);

#endif // STUDENTDATAMANAGER_H
