#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Se crea la funcion de rotacion para el vector
void rotar(int *vector, int tamanioVector, int numeroDesplazamientos )
{
    // Se define una mascara (bit masking) la cual se utilizara para definir cuales bits queremos conservar y cuales limpiar o quitar
    // esto se realizar para poder desplazar los bits que queremos en la izquierda hacia la derecha y hacer la rotacion mediante un AND y un OR logicos (bit a bit)
    int mascara = 0;
    // Se niega la mascara para que todos los bits sean 1
    mascara = ~mascara;
    // Se desplaza la mascara a la izquierda para que quede con 1s en los bits que queremos conservar
    mascara = ~(mascara << numeroDesplazamientos);

    //crea 3 listas auxiliares y temporales para almacenar los valores de los vectores
    int  *lista1 = (int  *)calloc(tamanioVector, sizeof(int));
    int  *lista2 = (int  *)calloc(tamanioVector, sizeof(int));
    int  *lista3 = (int  *)calloc(tamanioVector, sizeof(int));
    
    // Toma cada numero del vector y lo shiftea(desplazamiento lógico) a la izquierda la cantidad especificada por el usuario
    for (int i = 0; i < tamanioVector; i++)
    {
        lista1[i] = vector[i] << numeroDesplazamientos;
    }

    // Toma cada numero del vector y lo shiftea(desplazamiento lógico) a la derecha 32 - numero de desplazamiento veces para que quede en la posicion correcta
    for (int i = 0; i < tamanioVector; i++)
    {
        lista2[i] = vector[i] >> (32 - numeroDesplazamientos); // Se desplaza a la derecha 32 - el numero de desplazamiento para obtener la posicion correcta
        lista2[i] = lista2[i] & mascara;  // Se realiza el AND Lógico con la mascara para poder obtener el valor necesario
        if (numeroDesplazamientos == 32)
        {
            lista2[i] = vector[i];
        }
    }

    // cambia las posiciones de los numeros de la lista2 ya que se considera todo el vector como una sola cadena de bits por 
    // lo tanto se usa este procedimiento para lograrlo usando el modulo para saber la posicion en la que deberia quedar
    for (int i = 0; i < tamanioVector; i++)
    {
        lista3[i] = lista2[(i + 1) % tamanioVector];
    }

    // Se realiza un OR lógico entre la lista 1 y 3 para poder obtener ya el vector rotado correctamente
    for (int i = 0; i < tamanioVector; i++)
    {
        vector[i] = lista1[i] | lista3[i]; // Se realizar el OR lógico para obtener los bits rotados y los bits desplazados
        if (numeroDesplazamientos == 32)
        {
            vector[i] = lista3[i];
        }
    }

    // Libera la memoria de las listas
    free(lista1);
    free(lista2);
    free(lista3);
}

//Complejidad general O(n)

// Se inicia el procedimiento main 
int main()
{
    // Se declaran las variables
    int tamanioVector, numeroDesplazamientos, *vector;

    // Se pide el tamaño del vector
    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &tamanioVector);

    // Si el vector es menor o igual a 0, se vuelve a solicitar el tamaño del vector
    while (tamanioVector <= 0)
    {
        printf("El tamanio del vector debe ser mayor a 0. Ingrese el tamanio del vector: ");
        scanf("%d", &tamanioVector);
    }

    // Declara e inicializa el apuntador al vector de tamaño "tamanioVector" 
    vector = (int *)calloc(tamanioVector, sizeof(int));

    // Inicializa el vector: le pide al usuario que teclee el valor de cada elemento.
    for (int i = 0; i < tamanioVector; i++)
    {
        printf("Ingrese el valor del elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    // Le pide al usuario el número de posiciones "numeroDesplazamientos" de la rotación.
    printf("Ingrese el numero de posiciones de la rotacion: ");
    scanf("%d", &numeroDesplazamientos);

    // Si el numero de posiciones es menor a 0 o mayor o igual a 32, se vuelve a solicitar el numero de posiciones
    while (numeroDesplazamientos < 0 || numeroDesplazamientos > 32)
    {
        printf("El numero de posiciones debe ser mayor o igual a 0 y menor a 32. Ingrese el numero de posiciones de la rotacion: ");
        scanf("%d", &numeroDesplazamientos);
        return 1;
    }

    // Invoca el procedimiento que realiza la rotación en el vector
    rotar(vector, tamanioVector, numeroDesplazamientos);

    // Imprime el resultado (el vector de int) posición por posición en hexadecimal.
    for (int i = 0; i < tamanioVector; i++)
    {
        printf("v[%d] = ", i);
        printf("0x%08X \n", vector[i]);
    }

    // Libera la memoria del vector
    free(vector);

	system("pause");
    // Finaliza el programa
    return 0;
}