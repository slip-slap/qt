/********************************************************************************
** Form generated from reading UI file 'fourier.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURIER_H
#define UI_FOURIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Fourier
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QCustomPlot *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Fourier)
    {
        if (Fourier->objectName().isEmpty())
            Fourier->setObjectName(QString::fromUtf8("Fourier"));
        Fourier->resize(800, 600);
        centralwidget = new QWidget(Fourier);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 240, 161, 131));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 120, 241, 211));
        Fourier->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Fourier);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Fourier->setMenuBar(menubar);
        statusbar = new QStatusBar(Fourier);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Fourier->setStatusBar(statusbar);

        retranslateUi(Fourier);

        QMetaObject::connectSlotsByName(Fourier);
    } // setupUi

    void retranslateUi(QMainWindow *Fourier)
    {
        Fourier->setWindowTitle(QCoreApplication::translate("Fourier", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("Fourier", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fourier: public Ui_Fourier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURIER_H
