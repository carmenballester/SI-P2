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
    //Cargar la carpeta donde estan las imagenes
    QString datasetDir = QString(QFileDialog::getExistingDirectory(this, "Select dataset folder"));

    //Abrir el fichero csv donde vamos a guardar los datos y crear el objeto para poder escribir en él
    QString csvDir = datasetDir + "/datasetGray.csv";
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

            //Cargar la imagen y escalarla a 50x50
            image.load(path);
            QImage scaledImage = image.scaled(50,50);

            //Guardar el valor de cada pixel de la imagen
            for(int i=0; i<scaledImage.width(); i++) {
                for(int j=0; j<scaledImage.height(); j++) {
                    //Escala de grises
                    info += info.number(qGray(image.pixel(i,j))) + " ";

                    //QColor color = image.pixelColor(i,j);
                    //Canal R
                    //info += info.number(color.red()) + " ";

                    //Canal G
                    //info += info.number(color.green()) + " ";

                    //Canal B
                    //info += info.number(color.blue()) + " ";

                    //Se pueden añadir los canales que quiera mirando los métodos de la clase QColor
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


    // DEFINIR el número de neuronas de cada capa (y el inputStatistics que a saber qué es)
    size_t numInputs = dataSet.get_variables().count_inputs_number();
    size_t numOutputs = dataSet.get_variables().count_targets_number();
//    size_t numOcultas = 5;

    const Vector<Statistics<double>> inputsStatistics = dataSet.scale_inputs_minimum_maximum();


    // CREAR la red neuronal

    Vector<size_t> arch;
    arch.push_back(numInputs);
//    arch.push_back(3);
    arch.push_back(5);
    arch.push_back(numOutputs);

    NeuralNetwork neuralNetwork(arch);
//    std::cout << neuralNetwork.get_layers_number() << endl;

    // Asignar la información del dataset a las entradas y las salidas
    Inputs* inputsPointer = neuralNetwork.get_inputs_pointer();
    Outputs* outputsPointer = neuralNetwork.get_outputs_pointer();
    inputsPointer->set_information(inputsInformation);
    outputsPointer->set_information(targetsInformation);


    // DEFINIR la capa de escalado
    neuralNetwork.construct_scaling_layer();
    ScalingLayer* scalingLayerPtr = neuralNetwork.get_scaling_layer_pointer();
    scalingLayerPtr->set_statistics(inputsStatistics);
    scalingLayerPtr->set_scaling_method(ScalingLayer::NoScaling);


    // DEFINIR la capa probabilística
    neuralNetwork.construct_probabilistic_layer();
    ProbabilisticLayer* probabilisticLayerPtr = neuralNetwork.get_probabilistic_layer_pointer();
    probabilisticLayerPtr->set_probabilistic_method(ProbabilisticLayer::Softmax);


    // ENTRENAMIENTO__________________________________________________________________________________________________________________________________________________

//    training_strategy.set_optimization_method(TrainingStrategy::OptimizationMethod::QUASI_NEWTON_METHOD);
//    ts.set_loss_method(TrainingStrategy::LossMethod::NORMALIZED_SQUARED_ERROR);

//    training_strategy.set_optimization_method(TrainingStrategy::OptimizationMethod::QUASI_NEWTON_METHOD);
//    ts.set_loss_method(TrainingStrategy::LossMethod::NORMALIZED_SQUARED_ERROR);

    // DEFINIR la estrategia de entrenamiento
    LossIndex lossIndex;
    TrainingStrategy trainingStr;

    // Loss index
    lossIndex.set_data_set_pointer(&dataSet);
    lossIndex.set_neural_network_pointer(&neuralNetwork);

    // Training strategy
    trainingStr.set(&lossIndex);
    trainingStr.set_main_type(TrainingStrategy::GRADIENT_DESCENT);

//    QuasiNewtonMethod* quasiNewtonMethodPtr = trainingStr.get_quasi_Newton_method_pointer();
//    quasiNewtonMethodPtr->set_minimum_loss_increase(1.0e-6);
//    trainingStr.set_display(false);

      GradientDescent* gradientDesPtr = trainingStr.get_gradient_descent_pointer();
      gradientDesPtr->set_minimum_loss_increase(1.0e-6);
      trainingStr.set_display(false);



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

    // Tiempo de ejecución
    double time = (double(t1-t0)/CLOCKS_PER_SEC)/60;


    // MOSTRAR por pantalla los resultados

    qDebug() << "Parámetros obtenidos" << endl;
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
    qDebug() << qSetRealNumberPrecision(4) << "Tiempo de ejecución(min):\t" << time << endl;


    // GUARDAR los resultados

    // Definir las rutas de los archivos donde guardamos los parámetros
    QString dataSetDir = "/home/carmenballester/Escritorio/Practica2/Resultados/data_set_1.xml";
    QFile dataSetFile(dataSetDir);
    QString neuralNetworkDir = "/home/carmenballester/Escritorio/Practica2/Resultados/neural_network_1.xml";
    QFile neuralNetworkFile(neuralNetworkDir);
    QString trainingStrDir = "/home/carmenballester/Escritorio/Practica2/Resultados/training_strategy_1.xml";
    QFile trainingStrFile(trainingStrDir);
    QString confusionDir = "/home/carmenballester/Escritorio/Practica2/Resultados/confusion_1.dat";
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

void MainWindow::testNetwork()
{
    qDebug() << "Test Network";
}

MainWindow::~MainWindow()
{
    delete ui;
}

