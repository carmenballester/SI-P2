/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *createDataset;
    QPushButton *trainNet;
    QPushButton *testNet;
    QLabel *image;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        createDataset = new QPushButton(centralwidget);
        createDataset->setObjectName(QString::fromUtf8("createDataset"));
        createDataset->setGeometry(QRect(70, 70, 151, 71));
        trainNet = new QPushButton(centralwidget);
        trainNet->setObjectName(QString::fromUtf8("trainNet"));
        trainNet->setGeometry(QRect(330, 70, 151, 71));
        testNet = new QPushButton(centralwidget);
        testNet->setObjectName(QString::fromUtf8("testNet"));
        testNet->setGeometry(QRect(580, 70, 151, 71));
        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(70, 190, 661, 321));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        createDataset->setText(QApplication::translate("MainWindow", "Crear Dataset", nullptr));
        trainNet->setText(QApplication::translate("MainWindow", "Entrenar Red", nullptr));
        testNet->setText(QApplication::translate("MainWindow", "Evaluar Red", nullptr));
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
