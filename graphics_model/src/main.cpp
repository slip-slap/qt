#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QFile style_sheet_file("resource/stylesheet/Geoo.qss");
    style_sheet_file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(style_sheet_file.readAll());
    QApplication a(argc, argv);
    a.setStyleSheet(style_sheet);
    MainWindow w;
    w.show();
    return a.exec();
}
