#include "studentfactory.h"
#include "student.h"
#include "personaldata.h"
#include "grades.h"

Student* StudentFactory::create(
        unsigned ID,
        const std::string &firstName,
        const std::string &lastName,
        Gender gender,
        const std::vector<double> &grades) {
    Student *student = new Student(ID);

    std::unique_ptr<IGrades> studentGrades(new Grades(grades.size()));
    for(auto grade : grades) {
        studentGrades->add(grade);
    }

    student->setPersonalData(PersonalData(firstName, lastName, gender));
    student->setGrades(*studentGrades);
    return student;
}
