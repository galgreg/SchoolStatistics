#include "datarepositorymock.h"
#include "studentfactory.h"

DataRepositoryMock::DataRepositoryMock(const QString &repositoryPath) :
    IDataRepository(repositoryPath) {

}

std::unique_ptr<IStudentClass> DataRepositoryMock::read(
        size_t maxStudentCount,
        size_t maxGradesCount) {
    std::unique_ptr<IStudentClass> classFromFile(
            new StudentClass(maxStudentCount));
    for (size_t i = 0; i < maxStudentCount && i < mStudentClass.count(); ++i) {
        std::unique_ptr<IStudent> studentCopy(
                StudentFactory::copy(mStudentClass.getStudent(i)));
        std::unique_ptr<IGrades> studentGrades(new Grades(maxGradesCount));
        for (unsigned k = 0; k < maxGradesCount; ++k) {
            studentGrades->add(studentCopy->getGrades().getGrade(k));
        }
        studentCopy->setGrades(*studentGrades);
        classFromFile->addStudent(std::move(studentCopy));
    }
    return classFromFile;
}

void DataRepositoryMock::write(const IStudentClass &studentClass) {
    mStudentClass.removeAll();
    for (size_t i = 0; i < studentClass.count(); ++i) {
        const IStudent& tempStudent = studentClass.getStudent(i);
        std::unique_ptr<IStudent> studentCopy(
                StudentFactory::copy(tempStudent));
        mStudentClass.addStudent(std::move(studentCopy));
    }
}

bool DataRepositoryMock::exist() {
    return true;
}
