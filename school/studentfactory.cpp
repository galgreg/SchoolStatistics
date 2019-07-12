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

Student *StudentFactory::copy(const IStudent &studentToCopy) {
    unsigned studentID = studentToCopy.getID();
    std::string studentFirstName = studentToCopy.getPersonalData().getFirstName();
    std::string studentLastName = studentToCopy.getPersonalData().getLastName();
    Gender studentGender = studentToCopy.getPersonalData().getGender();

    std::vector<double> studentGrades;
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
