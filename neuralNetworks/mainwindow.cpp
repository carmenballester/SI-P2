#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect button signal to appropriate slot
    connect(ui->createDataset, SIGNAL(released()), this, SLOT(generateDataset()));
    connect(ui->trainNet, SIGNAL(released()), this, SLOT(trainNetwork()));
    connect(ui->testNet, SIGNAL(released()), this, SLOT(testNetwork()));

    connect(this, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
}

void MainWindow::generateDataset()
{
    qDebug() << "Generate Dataset";
    QString datasetDir = QString(QFileDialog::getExistingDirectory(this, "Select dataset folder"));
}

void MainWindow::trainNetwork()
{
    qDebug() << "Train Network";
}

void MainWindow::testNetwork()
{
    qDebug() << "Test Network";
}

MainWindow::~MainWindow()
{
    delete ui;
}

