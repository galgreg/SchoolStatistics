#include "studentfactory.h"
#include "grades.h"
#include "personaldata.h"

std::unique_ptr<Student> StudentFactory::create(
        unsigned ID,
        const QString &firstName,
        const QString &lastName,
        Gender gender,
        const QList<double> &grades) {
    std::unique_ptr<Student> student(new Student(ID));
    std::unique_ptr<IGrades> studentGrades(
            new Grades(static_cast<size_t>(grades.size())));

    for (int i = 0; i < grades.size(); ++i) {
        studentGrades->add(grades.at(i));
    }

    student->setPersonalData(PersonalData(firstName, lastName, gender));
    student->setGrades(*studentGrades);
    return student;
}

std::unique_ptr<Student> StudentFactory::copy(const IStudent &studentToCopy) {
    unsigned studentID = studentToCopy.getID();
    QString studentFirstName = studentToCopy.getPersonalData().getFirstName();
    QString studentLastName = studentToCopy.getPersonalData().getLastName();
    Gender studentGender = studentToCopy.getPersonalData().getGender();

    QList<double> studentGrades;
    const IGrades& gradesToCopy = studentToCopy.getGrades();
    for (unsigned i = 0; i < gradesToCopy.count(); ++i) {
        studentGrades.push_back(gradesToCopy.getGrade(i));
    }

    return StudentFactory::create(
            studentID,
            studentFirstName,
            studentLastName,
            studentGender,
            studentGrades);
}
