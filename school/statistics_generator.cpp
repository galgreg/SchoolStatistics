#include "statistics_generator.h"

StatisticsGenerator::StatisticsGenerator(QString fileName)
{

}

double StatisticsGenerator::getAverageForStudent(int whichStudent) const
{
    return students.at(whichStudent).getGradesAverage();
}

double StatisticsGenerator::getAverageOfWholeClass() const
{
    int numberOfStudents = students.size();
    double sumOfIndividualAverages = 0.0;

    for (auto student : students) {
        sumOfIndividualAverages += student.getGradesAverage();
    }

    return sumOfIndividualAverages / numberOfStudents;
}

StudentInfo *StatisticsGenerator::getInfoAboutStudent(int whichStudent) const
{
    const auto &student = students.at(whichStudent);
    unsigned studentID = student.getID();
    QString studentName = student.getFullName();
    Gender studentGender = student.getGender();
    return new StudentInfo(studentID, studentName, studentGender);
}
