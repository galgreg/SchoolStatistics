#include "confirmdialog.h"
#include "mainwindow.h"
#include "studentclass.h"
#include "studentdatawindow.h"
#include "textfilestorage.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir tempDir;
    QString fileStorageDirLocation = tempDir.absolutePath() + "/../school/";
    const QString PATH_TO_STORAGE = fileStorageDirLocation + "students.txt";
    MainWindow w(
            new TextFileStorage(PATH_TO_STORAGE.toStdString()),
            new StudentDataWindow,
            new ConfirmDialog);
    w.show();
    return a.exec();
}
