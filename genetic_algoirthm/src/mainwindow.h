#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qcustomplot.h"
#include "crowdingga.h"
#include "nsga.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_nsga_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    CrowdingGA* ga;
    NSGA* nsga;
    QVector<QColor> m_color_qvec;
};
#endif // MAINWINDOW_H
