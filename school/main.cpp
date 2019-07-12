#include <QApplication>
#include <QDir>
#include "mainwindow.h"
#include "textfilestorage.h"
#include "studentclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir tempDir;
    QString fileStorageDirLocation = tempDir.absolutePath() + "/../school/";
    const QString PATH_TO_STORAGE = fileStorageDirLocation + "students.txt";
    MainWindow w(new TextFileStorage(PATH_TO_STORAGE.toStdString()));
    w.show();
    return a.exec();
}
