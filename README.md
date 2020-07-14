# Gender detection using machine learning
El objetivo del desarrollo de esta práctica es crear una red neuronal que sea capaz de determinar el sexo de las personas que aparecen en una imagen. Este problema está ampliamente resuelto en la actualidad, pero es necesario sopesar la relación entre precisión de los resultados y tiempo de cómputo, ya que cuanto mejores resultados deseemos más capacidad computacional se requiere.

Para programar esta red se utiliza la librería Open Neural Network Library - OpenNN, que es una librería opensource escrita en C++ que implementa redes neuronales, y que además puede integrarse con otras herramientas como QT Creator, que es el IDE que se utiliza para el desarrollo de la práctica.

El dataset que se va a utilizar está constituido por 303 imágenes, de las cuales 101 pertenecen a hombres, 101 a mujeres y 101 son imágenes sin persona. Como el dataset no es muy grande, es necesario dividirlo en tres conjuntos de datos, de forma que el sistema no aprenda todas las imágenes. Estos conjuntos son: 
- De entrenamiento: es el que se utiliza para entrenar la red y actualizar los pesos, por lo que tiene que ser el de mayor tamaño, un 70% del dataset.
- De prueba: es el que se utiliza al final de cada época para analizar cómo de bien trabaja la red ante caras nuevas, de forma que nos aseguramos de que es capaz de generalizar correctamente. Constituye un 15% del dataset.
- De validación: es el que se utiliza cuando la red está totalmente entrenada, por lo que nos proporciona el error final de validación de esta. Lo forma un 15% del dataset.

Una vez que la red se ha entrenado y probado con fotos del dataset, hay que comprobar su eficacia en un escenario más real, por lo que tiene que ser capaz de determinar el género en una imagen donde hayan varias personas.
