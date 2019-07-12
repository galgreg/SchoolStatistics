#include "datarepositorymock.h"
#include "studentfactory.h"

DataRepositoryMock::DataRepositoryMock(const std::string &repositoryPath) :
    IDataRepository(repositoryPath) {

}

IStudentClass *DataRepositoryMock::read(
        size_t maxStudentCount,
        size_t maxGradesCount) {
    IStudentClass *classFromFile = new StudentClass(maxStudentCount);
    for (size_t i = 0; i < maxStudentCount; ++i) {
        IStudent *studentCopy
                = StudentFactory::copy(mStudentClass.getStudent(i));
        std::unique_ptr<IGrades> studentGrades(new Grades(maxGradesCount));
        for (unsigned k = 0; k < maxGradesCount; ++k) {
            studentGrades->add(studentCopy->getGrades().getGrade(k));
        }
        studentCopy->setGrades(*studentGrades);
        classFromFile->addStudent(studentCopy);
    }
    return classFromFile;
}

void DataRepositoryMock::write(const IStudentClass &studentClass) {
    for (size_t i = 0; i < studentClass.count(); ++i) {
        const IStudent& tempStudent = studentClass.getStudent(i);
        std::unique_ptr<IStudent> studentCopy(
                StudentFactory::copy(tempStudent));
        mStudentClass.addStudent(studentCopy.release());
    }
}

bool DataRepositoryMock::exist() {
    return true;
}
