# 4.2.27 LAB: Operators: iostream

## Descripción del Ejercicio

El objetivo de este laboratorio es practicar la sobrecarga del operador de inserción de flujo (`<<`) aplicada a una estructura de datos no lineal: un Árbol Binario.

El código implementa dos clases: `Node`, que representa cada elemento con un valor y punteros inteligentes (`std::unique_ptr`) a sus hijos izquierdo y derecho; y `BinaryTree`, que gestiona la estructura general. Se implementa un método `add` que inserta valores siguiendo la lógica de un Árbol Binario de Búsqueda (menores a la izquierda, mayores a la derecha).

La parte central del ejercicio es la sobrecarga del operador `<<` como una función amiga (`friend`). Este operador invoca un método privado recursivo `printInorder` que recorre el árbol en orden (Izquierda -> Raíz -> Derecha), lo que resulta en la impresión de los valores ordenados de forma ascendente.

## Salida del Programa

A continuación se muestra la salida del programa. Al insertar los valores 3, 5 y 2 en ese orden, el recorrido "in-order" los imprime ordenados.

```console
2 3 5
