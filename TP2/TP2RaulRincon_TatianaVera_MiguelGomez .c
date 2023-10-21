/*
******* CODIGO HECHO POR **********

Miguel Gomez - 202122562 - ma.gomezc123@uniandes.edu.co
Raul Rincon - 202120414 - r.rincon@uniandes.edu.co 
Tatiana Vera - 202113341 - k.verah@uniandes.edu.co

*/

#include <stdio.h>

int main(){
    
    // Se definen todos los datos con sus respectivos datos necesarios
    int tramo;
    int overbyte;
    int tiempo;
    float tasa;
    float datos;
    
    // Se solicita al usuario ingresar los datos con los cuales quiera
    // calcular la velocidad de transferencia efectiva.
    
    printf("Ingrese el valor de la trama en Mb: ");
    scanf( "%d" , &tramo );

    printf("Ingrese el valor del Overbyte en Mb: ");
    scanf( "%d" , &overbyte);

    printf("Ingrese el tiempo en segundos: ");
    scanf( "%d" , &tiempo);

    // Se calcula la velocidad de transferencia efectiva con la formula
    // escrita abajo 

    datos = (tramo-overbyte);
    tasa = datos/tiempo;
   
    // Imprime y retorna la tasa calculada 
    printf("\nLa tasa de transferencia es %.2f Mb/s. ", tasa ) ;
    
    return tasa;
}