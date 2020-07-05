#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include <QDir>
#include <QTextStream>

#include <iostream>

#include "/home/carmenballester/Escritorio/Practica2/OpenNN/opennn/opennn.h"
#include "/home/carmenballester/Escritorio/Practica2/OpenNN/opennn/data_set.h"
#include "/home/carmenballester/Escritorio/Practica2/OpenNN/opennn/neural_network.h"
#include "/home/carmenballester/Escritorio/Practica2/OpenNN/opennn/training_strategy.h"

using namespace OpenNN;
using namespace std;


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
    void generateDataset();
    void trainNetwork();
    void testNetwork();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
