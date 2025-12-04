# 4.0.8 LAB: Operators: iostream and operators

## Descripción del Ejercicio

El objetivo de este laboratorio es practicar la sobrecarga de operadores de entrada y salida (`stream operators`) en C++. El código implementa una clase contenedora llamada `Matrix2x2` que representa una matriz matemática simple de 2x2.

Para permitir la interacción directa con `std::cin` y `std::cout`, se sobrecargan los operadores globales `>>` (extracción) y `<<` (inserción) como funciones amigas (`friend`) de la clase. El operador de entrada lee valores enteros secuencialmente y los almacena en la matriz, mientras que el operador de salida formatea los datos almacenados para mostrarlos en la consola como una cuadrícula de dos filas y dos columnas.

## Salida del Programa

A continuación se muestra una simulación de la ejecución, donde el usuario introduce cuatro números enteros y el programa imprime la matriz resultante.

```console
1
2
3
4
1 2
3 4
