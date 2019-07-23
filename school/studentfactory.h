#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H
#include "gender.h"
#include "student.h"
#include <memory>
#include <QList>
#include <QString>


class StudentFactory
{
public:
    static std::unique_ptr<Student> create(
        unsigned ID,
        const QString &firstName,
        const QString &lastName,
        Gender gender,
        const QList<double> &grades);
    static std::unique_ptr<Student> copy(const IStudent &studentToCopy);
};

#endif // STUDENTFACTORY_H
