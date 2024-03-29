#include "confirmdialog.h"
#include "mainwindow.h"
#include "studentclass.h"
#include "studentdataform.h"
#include "studentdatawindow.h"
#include "textfilestorage.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir tempDir;
    QString fileStorageDirLocation = tempDir.absolutePath() + "/../";
    const QString PATH_TO_STORAGE = fileStorageDirLocation + "students.txt";
    auto signalTransmitter = std::make_shared<SignalTransmitter>();
    MainWindow w(
            std::make_unique<TextFileStorage>(PATH_TO_STORAGE),
            std::make_unique<StudentDataWindow>(signalTransmitter),
            std::make_unique<ConfirmDialog>(signalTransmitter),
            std::make_unique<StudentDataForm>(signalTransmitter),
            signalTransmitter);
    w.show();
    return a.exec();
}
