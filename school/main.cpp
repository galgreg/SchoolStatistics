#include <QApplication>
#include "mainwindow.h"
#include "textfilestorage.h"
#include "studentclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const std::string PATH_TO_STORAGE = "students.txt";
    MainWindow w(new TextFileStorage(PATH_TO_STORAGE), new StudentClass);
    w.show();
    return a.exec();
}
