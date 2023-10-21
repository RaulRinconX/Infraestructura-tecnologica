#include <stdio.h>
#include <stdlib.h>

//realizar el desplazamiento logico hacia la izquierda de cada vector 
//y luego realizar la operacion OR para incluir el nuevo hexadecimal
//en el vector.


int main() {
    // Declaración de variables
    int tamanioVector, numeroCorrimientos, i;
    int *apuntadorVectorEnteros;
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &tamanioVector);

    //validar que tamaño del vector sea mayor a 0

    if (tamanioVector <= 0) {
        printf("El tamaño del vector debe ser mayor a 0");
        return 0;

    /*
    Declara e inicializa el apuntador al vector de int. La inicialización consiste en
    ponerlo a apuntar a un vector de int del tamaño pedido. El vector se crea
    dinámicamente usando la función de C calloc.
    */

    } else {
        apuntadorVectorEnteros = (int *) calloc(tamanioVector, sizeof(int));
    }

    //Inicializa el vector: le pide al usuario que teclee el valor de cada elemento.
    //Transforma el valor tecleado a hexadecimal y lo guarda en el vector.
    for (i = 0; i < tamanioVector; i++) {
        printf("Ingrese el valor del elemento %d: ", i);
        scanf("%i", &apuntadorVectorEnteros[i]);
    }


    //Le pide al usuario el número de posiciones (k) de la rotación (validar 0 < k ≤ 32).
   
    printf("Ingrese el número de posiciones de la rotación: ");
    scanf("%d", &numeroCorrimientos);

    //validar que el número de corrimientos sea mayor a 0 y menor o igual a 32
    if (numeroCorrimientos <= 0 || numeroCorrimientos > 32) {
        printf("El número de corrimientos debe ser mayor a 0 y menor o igual a 32");
        return 0;
    }

    //Invoca el procedimiento que realiza la rotación en el vector.

    rotarIzquierdaBit(apuntadorVectorEnteros, tamanioVector, numeroCorrimientos);
   
    //Imprime el resultado (el vector de int) posición por posición en hexadecimal.
   
    for (i = 0; i < tamanioVector; i++) {
        printf("v[%d] = 0x%X \n", i, apuntadorVectorEnteros[i]);
    }

    return 0;
}