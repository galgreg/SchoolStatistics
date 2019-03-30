#ifndef STUDENTDATAMANAGER_H
#define STUDENTDATAMANAGER_H

#include "studentdatamanagerinterface.h"
#include "student.h"
#include <QList>
#include <QString>
#include <QTextStream>

class StudentDataManager : public StudentDataManagerInterface
{
public:
    explicit StudentDataManager(QString fileName);
    QList<StudentInterface*> read() const override;
    void write(const QList<StudentInterface*> &students) override;
private:
    QString mFileName;
};

QTextStream& operator>>(QTextStream &stream, Student &student);
QTextStream& operator<<(QTextStream &stream, const StudentInterface &student);

#endif // STUDENTDATAMANAGER_H
