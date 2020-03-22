#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include <QDir>
#include <QTextStream>

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
    //Cargar la carpeta donde estan las imagenes
    QString datasetDir = QString(QFileDialog::getExistingDirectory(this, "Select dataset folder"));
    QString csvDir = datasetDir + "/dataset.csv";

    //Abrir el fichero csv donde vamos a guardar los datos y crear el objeto para poder escribir en él
    QFile dataset(csvDir);
    QTextStream imageData(&dataset);
    if(!dataset.open(QIODevice::WriteOnly | QIODevice::Text)) {
        exit(-1);
    }

    //Crear un vector con los nombres de las tres carpetas que tenemos
    vector<QString> strV(3);
    strV[0] = "/hombre/";
    strV[1] = "/mujer/";
    strV[2] = "/sin-persona/";

    //Para cada carpeta del dataset
    for(size_t k=0; k<strV.size(); k++) {
        QString str = strV[k];
        QDir folder = datasetDir + str;
        qDebug() << folder;

        // Listar los nombres de todas las imagenes (.jpg) dentro de la carpeta
        QStringList filters;
        filters << "*.jpg";
        folder.setNameFilters(filters);
        QStringList filenames = folder.entryList();
        qDebug() << filenames;

        // Leer cada una de las imágenes del dataset y guardarla en el archivo .csv
        for(int i=0; i<filenames.size(); i++) {
            QImage image;
            QString info;
            QString path = datasetDir + str + filenames[i];

            //Cargar la imagen y escalarla a 50x50
            image.load(path);
            QImage scaledImage = image.scaled(50,50);

            //Guardar el valor de cada pixel de la imagen
            for(int i=0; i<scaledImage.width(); i++) {
                for(int j=0; j<scaledImage.height(); j++) {
                    info += info.number(qGray(image.pixel(i,j))) + " ";
                }
            }

            // Asignar la clase de la imagen
            imageData << info;
            switch (k) {
                case 0: imageData << "0";
                        break;
                case 1: imageData << "1";
                        break;
                case 2: imageData << "2";
                        break;
            }
            imageData << "\n";
        }
    }

    // Cerrar el fichero csv
    dataset.close();
    qDebug() << "Dataset generado";
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

