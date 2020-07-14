#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    // Cargar la carpeta donde estan las imagenes
    QString datasetDir = QString(QFileDialog::getExistingDirectory(this, "Select dataset folder"));

    // Abrir el fichero csv donde vamos a guardar los datos y crear el objeto para poder escribir en él
    QString csvDir = datasetDir + "/datasetGray.csv";
    QFile dataset(csvDir);
    QTextStream imageData(&dataset);
    if(!dataset.open(QIODevice::WriteOnly | QIODevice::Text)) {
        exit(-1);
    }

    // Crear un vector con los nombres de las tres carpetas que tenemos
    vector<QString> strV(3);
    strV[0] = "/hombre/";
    strV[1] = "/mujer/";
    strV[2] = "/sin-persona/";

    // Para cada carpeta del dataset
    for(size_t k=0; k<strV.size(); k++) {
        QString str = strV[k];
        QDir folder = datasetDir + str;

        // Listar los nombres de todas las imagenes (.jpg) dentro de la carpeta
        QStringList filters;
        filters << "*.jpg";
        folder.setNameFilters(filters);
        QStringList filenames = folder.entryList();

        // Leer cada una de las imágenes del dataset y guardarla en el archivo .csv
        for(int i=0; i<filenames.size(); i++) {
            QImage image;
            QString info;
            QString path = datasetDir + str + filenames[i];

            // Cargar la imagen y escalarla a 50x50
            image.load(path);
            QImage scaledImage = image.scaled(RESIZE_NN,RESIZE_NN);

            // Guardar el valor de cada pixel de la imagen
            for(int i=0; i<scaledImage.width(); i++) {
                for(int j=0; j<scaledImage.height(); j++) {
                    // Escala de grises
                    info += info.number(qGray(image.pixel(i,j))) + " ";

                    // QColor color = image.pixelColor(i,j);
                    // // Canal R
                    // info += info.number(color.red()) + " ";

                    // // Canal G
                    // info += info.number(color.green()) + " ";

                    // // Canal B
                    // info += info.number(color.blue()) + " ";
                }
            }

            // Asignar la clase de la imagen
            imageData << info;
            switch (k) {
                case 0: imageData << "1 0 0";
                        break;
                case 1: imageData << "0 1 0";
                        break;
                case 2: imageData << "0 0 1";
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
    // DATASET________________________________________________________________________________________________________________________________________________________


    // CREAR el objeto que almacena la información del dataset y especificar el archivo que tiene que cargar y sus carecterísticas
    DataSet dataSet;
    dataSet.set_data_file_name("/home/carmenballester/Escritorio/Practica2/dataset/datasetGray.csv");
    dataSet.set_separator("Space");
    // Cargar la información del dataset en el objeto de clase
    qDebug() << "Cargando el dataset...";
    dataSet.load_data();
    qDebug() << "Dataset cargado";


    // MODIFICAR y visualizar los atributos del dataset
    Variables* variablesPointer = dataSet.get_variables_pointer();
    // Modificar el nombre y la unidad de cada atributo (columna del dataset)
    for(size_t i=0; i<(dataSet.get_data()).get_columns_number(); i++) {
        // Target (valor de la clase a la que pertenece la clase)
        if (i == (dataSet.get_data()).get_columns_number()-1) {
            variablesPointer->set_name(i, "sin-persona");
            variablesPointer->set_units(i, "\t(true,false)");
            variablesPointer->set_use(i, Variables::Target);
        }
        else if (i == (dataSet.get_data()).get_columns_number()-2) {
            variablesPointer->set_name(i, "mujer");
            variablesPointer->set_units(i, "\t\t(true,false)");
            variablesPointer->set_use(i, Variables::Target);
        }
        else if (i == (dataSet.get_data()).get_columns_number()-3) {
            variablesPointer->set_name(i, "hombre");
            variablesPointer->set_units(i, "\t\t(true,false)");
            variablesPointer->set_use(i, Variables::Target);
        }
        // Inputs (valores de intensidad de los píxeles)
        else {
            variablesPointer->set_name(i, "pixel " + to_string(i));
            variablesPointer->set_units(i, "\t\t(intensidad [0,255])");
        }
    }

    // Obtener la información de las variables y mostrarlas por pantalla
    const Matrix<std::string> inputsInformation = variablesPointer->arrange_inputs_information();
    const Matrix<std::string> targetsInformation = variablesPointer->arrange_targets_information();
//    cout << "Input information" << endl << inputsInformation << endl;
//    cout << "Target information" << endl << targetsInformation << endl;


    // DIVIDIR los datos para crear los conjuntos de entrenamiento, validación y test
    Instances* instancesPointer = dataSet.get_instances_pointer();
    instancesPointer->split_random_indices(0.7,0.15,0.15);
//    const Vector< Statistics<double> > inputsStatistics = dataset.scale_inputs_minimum_maximum(); -> Por ahora esto no lo uso no sé para qué sirve


    // RED NEURONAL___________________________________________________________________________________________________________________________________________________


    // DEFINIR el número de neuronas de cada capa
    size_t numInputs = dataSet.get_variables().count_inputs_number();
    size_t numOutputs = dataSet.get_variables().count_targets_number();
//    size_t numOcultas = 5;


    // CREAR la red neuronal

    Vector<size_t> arch;
    arch.push_back(numInputs);
//    arch.push_back(7);
//    arch.push_back(3);
    arch.push_back(2);
    arch.push_back(numOutputs);

    NeuralNetwork neuralNetwork(arch);
//    qDebug() << neuralNetwork.get_layers_number();
//    qDebug() << neuralNetwork.arrange_architecture();

    // Asignar la información del dataset a las entradas y las salidas
    Inputs* inputsPointer = neuralNetwork.get_inputs_pointer();
    Outputs* outputsPointer = neuralNetwork.get_outputs_pointer();
    inputsPointer->set_information(inputsInformation);
    outputsPointer->set_information(targetsInformation);


    // DEFINIR la capa de escalado

    const Vector<Statistics<double>> inputsStatistics = dataSet.scale_inputs_minimum_maximum();

    neuralNetwork.construct_scaling_layer();
    ScalingLayer* scalingLayerPtr = neuralNetwork.get_scaling_layer_pointer();
    scalingLayerPtr->set_statistics(inputsStatistics);

    scalingLayerPtr->set_scaling_method(ScalingLayer::NoScaling);
//    scalingLayerPtr->set_scaling_method(ScalingLayer::ScalingMethod::MeanStandardDeviation);
//    scalingLayerPtr->set_scaling_method(ScalingLayer::ScalingMethod::MinimumMaximum);


    // DEFINIR la capa probabilística
    neuralNetwork.construct_probabilistic_layer();
    ProbabilisticLayer* probabilisticLayerPtr = neuralNetwork.get_probabilistic_layer_pointer();
    probabilisticLayerPtr->set_probabilistic_method(ProbabilisticLayer::Softmax);


    // ENTRENAMIENTO__________________________________________________________________________________________________________________________________________________


    // DEFINIR la estrategia de entrenamiento
    LossIndex lossIndex;
    TrainingStrategy trainingStr;

    // Definir la semilla de generación de números aleatorios
    srand(unsigned(28071999));
    void initialize_random(void);

    // Loss index
    lossIndex.set_data_set_pointer(&dataSet);
    lossIndex.set_neural_network_pointer(&neuralNetwork);

    lossIndex.set_error_type(OpenNN::LossIndex::MEAN_SQUARED_ERROR);
    lossIndex.set_regularization_type(OpenNN::LossIndex::NEURAL_PARAMETERS_NORM);

    // Training strategy
    trainingStr.set(&lossIndex);

    trainingStr.set_main_type(TrainingStrategy::QUASI_NEWTON_METHOD);
    QuasiNewtonMethod* quasiNewtonMethodPtr = trainingStr.get_quasi_Newton_method_pointer();
    quasiNewtonMethodPtr->set_minimum_loss_increase(1.0e-6);
    trainingStr.set_display(false);

//    trainingStr.set_main_type(TrainingStrategy::GRADIENT_DESCENT);
//    GradientDescent* gradientDesPtr = trainingStr.get_gradient_descent_pointer();
//    gradientDesPtr->set_minimum_loss_increase(1.0e-6);
//    trainingStr.set_display(false);


    // ENTRENAR la red
    qDebug() << "Entrenando la red...";
    long t0 = clock();
    TrainingStrategy::Results results = trainingStr.perform_training();
    long t1 = clock();
    qDebug() << "Red entrenada";


    // MODEL SELECTION
//    ModelSelection modelSelection;
//    modelSelection.set_training_strategy_pointer(&trainingStr);
//    modelSelection.set_order_selection_type(ModelSelection::GOLDEN_SECTION);
//    GoldenSectionOrder* goldenSectionOrderPtr = modelSelection.get_golden_section_order_pointer();
//    goldenSectionOrderPtr->set_tolerance(1.0e-7);

//    ModelSelection::ModelSelectionResults modelSelectionResults = modelSelection.perform_order_selection();


    // TEST Y RESULTADOS______________________________________________________________________________________________________________________________________________


    TestingAnalysis testingAnalysis(&neuralNetwork, &dataSet);
    float accuracy; // En español = precisión
    float prec_h, prec_m, prec_sp; // En español = exactitud
    float sens_h, sens_m, sens_sp;


    // OBTENER la matriz de confusion con el conjunto de test del dataset

    qDebug() << "Probando la red...";
    const Matrix<size_t> conf = testingAnalysis.calculate_confusion();


    // CALCULAR los parámetros de la red
    qDebug() << "Obteniendo parámetros...";

    // Error
    Vector<double> testingError = testingAnalysis.calculate_testing_errors();

    // Tiempo de ejecución
    double time = (double(t1-t0)/CLOCKS_PER_SEC)/60;

    // Precisión
    accuracy = (float(conf[0]+conf[4]+conf[8]))/(conf[0]+conf[1]+conf[2]+conf[3]+conf[4]+conf[5]+conf[6]+conf[7]+conf[8]);

    // Exactitud
    prec_h = (float(conf[0]))/(conf[0]+conf[1]+conf[2]);
    prec_m = (float(conf[4]))/(conf[3]+conf[4]+conf[5]);
    prec_sp = (float(conf[8]))/(conf[6]+conf[7]+conf[8]);

    // Sensibilidad
    sens_h = (float(conf[0]))/(conf[0]+conf[3]+conf[6]);
    sens_m = (float(conf[4]))/(conf[1]+conf[4]+conf[7]);
    sens_sp = (float(conf[8]))/(conf[2]+conf[5]+conf[8]);


    // MOSTRAR por pantalla los resultados

    qDebug() << "Parámetros obtenidos" << endl;
    qDebug() << qSetRealNumberPrecision(4) << "Tiempo de ejecución(min):\t" << time << endl;
    qDebug() << "Matriz de confusión:\t\t" << conf[0] << "\t" << conf[3] << "\t" << conf[6];
    qDebug() << "                    \t\t" << conf[1] << "\t" << conf[4] << "\t" << conf[7];
    qDebug() << "                    \t\t" << conf[2] << "\t" << conf[5] << "\t" << conf[8] << endl;
    qDebug() << qSetRealNumberPrecision(4) << "Precisión:\t\t\t" << accuracy;
    qDebug() << qSetRealNumberPrecision(4) << "Exactitud:\t\t\t" << "Hombres = " << prec_h << "\tMujeres = " << prec_m << "\tSin persona = " << prec_sp;
    qDebug() << qSetRealNumberPrecision(4) << "Sensibilidad:\t\t" << "Hombres = " << sens_h << "\tMujeres = " << sens_m << "\tSin persona = " << sens_sp << endl;
    qDebug() << qSetRealNumberPrecision(4) << "Sum Squared Error:\t\t" << testingError[0];
    qDebug() << qSetRealNumberPrecision(4) << "Mean squared error:\t\t" << testingError[1];
    qDebug() << qSetRealNumberPrecision(4) << "Root mean squared error:\t" << testingError[2];
    qDebug() << qSetRealNumberPrecision(4) << "Normalized squared error:\t" << testingError[3] << endl;


    // GUARDAR los resultados

    // Definir las rutas de los archivos donde guardamos los parámetros
    QString dataSetDir = "/home/carmenballester/Escritorio/Practica2/resultados/dataset/data_set_1.xml";
    QFile dataSetFile(dataSetDir);
    QString neuralNetworkDir = "/home/carmenballester/Escritorio/Practica2/resultados/neuralnetwork/neural_network_1.xml";
    QFile neuralNetworkFile(neuralNetworkDir);
    QString trainingStrDir = "/home/carmenballester/Escritorio/Practica2/resultados/trainingstrategy/training_strategy_1.xml";
    QFile trainingStrFile(trainingStrDir);
    QString confusionDir = "/home/carmenballester/Escritorio/Practica2/resultados/confusion/confusion_1.dat";
    QFile confusionFile(neuralNetworkDir);

    // Guardar los resultados obtenidos
    qDebug() << "Guardando los resultados...";
    qDebug() << "Guardando dataset...";
    dataSet.save(dataSetDir.toStdString());
    qDebug() << "Guardando neural network...";
    neuralNetwork.save(neuralNetworkDir.toStdString());
    qDebug() << "Guardando training strategy...";
    trainingStr.save(trainingStrDir.toStdString());
    qDebug() << "Guardando matriz de confusion...";
    conf.save(confusionDir.toStdString());
    qDebug() << "Resultados guardados";
}

void MainWindow::testNetwork() {

    // Cargar el fichero .XML que contiene la red neuronal entrenada
    QString neuralNetworkDir = QString(QFileDialog::getOpenFileName(this, "Select neural network file (.xml)"));

    // Crear el objeto de la red neuronal a partir del fichero cargado y establecer sus parámetros
    NeuralNetwork neuralNetwork(neuralNetworkDir.toStdString());

    // Cargar la imagen y escalarla a 250x250
    QString imageDir = QString(QFileDialog::getOpenFileName(this, "Select image file"));

    QImage image;
    image.load(imageDir);
    QImage scaledImage = image.scaled(RESIZE_IMAGE,RESIZE_IMAGE);

    // Dividir la imagen en sectores (5x5) para pasar cada sector por la red
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            QImage sector;
            sector = scaledImage.copy(i*SECTOR,j*SECTOR,SECTOR,SECTOR);
            QImage scaledSector = sector.scaled(RESIZE_NN,RESIZE_NN);

            Vector<double> inputs(neuralNetwork.get_inputs_number());
            Vector<double> outputs(neuralNetwork.get_outputs_number());

            // Guardar el valor de cada pixel de la imagen
            size_t pix = 0;
            for(int x=0; x<RESIZE_NN; x++) {
                for(int y=0; y<RESIZE_NN; y++) {
                    // Escala de grises
                    inputs[pix] = qGray(sector.pixel(x,y));
                    pix++;

                    // QColor color = image.pixelColor(i,j);
                    // // Canal R
                    // inputs[pix] = color.red();
                    // pix++;

                    // // Canal G
                    // inputs[pix] = color.green();
                    // pix++;

                    // //Canal B
                    // inputs[pix] = color.blue();
                    // pix++;
                }
            }

            // Calcular las predicciones de la red
            outputs = neuralNetwork.calculate_outputs(inputs);
            size_t clase = outputs.calculate_maximal_index();

            // Dibujar los resultados en la imagen
            QPainter p;
            switch(clase){
                case 0:
                    p.begin(&scaledImage);
                    p.setPen(QPen(Qt::red));
                    p.setFont(QFont("Times", 8, QFont::Bold));
                    p.drawText(i*SECTOR+SECTOR/3,j*SECTOR+SECTOR/2,"Hombre");
                    p.drawRect(i*SECTOR-1,j*SECTOR-1,SECTOR-1,SECTOR-1);
                    p.end();
                break;

                case 1:
                    p.begin(&scaledImage);
                    p.setPen(QPen(Qt::blue));
                    p.setFont(QFont("Times", 8, QFont::Bold));
                    p.drawText(i*SECTOR+SECTOR/3,j*SECTOR+SECTOR/2,"Mujer");
                    p.drawRect(i*SECTOR-1,j*SECTOR-1,SECTOR-1,SECTOR-1);
                    p.end();
                break;

                case 2:
                    p.begin(&scaledImage);
                    p.setPen(QPen(Qt::green));
                    p.setFont(QFont("Times", 8, QFont::Bold));
                    p.drawText(i*SECTOR+SECTOR/5,j*SECTOR+SECTOR/2,"Sin persona");
                    p.drawRect(i*SECTOR-1,j*SECTOR-1,SECTOR-1,SECTOR-1);
                    p.end();
                break;
            }
        }
    }

    // Mostrar la imagen y guardarla
    QPixmap imagePM;
    imagePM.convertFromImage(scaledImage);
    ui->image->setPixmap(imagePM);

    scaledImage.save("/home/carmenballester/Escritorio/Practica2/resultados/imagetest/test_19.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}
