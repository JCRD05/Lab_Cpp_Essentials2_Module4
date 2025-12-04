# 4.2.29 LAB: Operators: complex classes

## Descripción del Ejercicio

Este laboratorio avanzado combina la herencia, el polimorfismo y la sobrecarga de operadores para gestionar diferentes recorridos de un Árbol Binario.

El código define una clase base abstracta `BinaryTree` que gestiona la estructura de nodos y la inserción de datos. A partir de ella, se derivan tres clases específicas: `InorderTree`, `PostorderTree` y `PreorderTree`.

Cada clase derivada implementa su propia lógica para dos operadores clave:
1.  **Operador `<<`**: Sobrecargado para imprimir los valores del árbol siguiendo el algoritmo de recorrido específico (In-order, Post-order o Pre-order).
2.  **Operador `[]`** (Indexación): Implementado en la clase base pero dependiente de un método virtual puro (`saveValues`), permite acceder al n-ésimo elemento del árbol según el orden de recorrido correspondiente.

En la función `main`, se insertan los mismos valores (3, 5, 6, 1) en los tres tipos de árboles para demostrar cómo la estructura interna y la salida varían según la lógica de recorrido implementada.

## Salida del Programa

A continuación se muestra la salida del programa. Dado que se insertaron los valores 3, 5, 6 y 1 (formando un árbol donde 3 es la raíz, 1 a la izquierda, y 5 a la derecha con 6 a su derecha), los resultados de los recorridos son:

* **Inorder (Izq-Raíz-Der):** 1, 3, 5, 6 (Orden ascendente).
* **Postorder (Izq-Der-Raíz):** 1, 6, 5, 3 (Hijos procesados antes que padres).
* **Preorder (Raíz-Izq-Der):** 3, 1, 5, 6 (Padres procesados antes que hijos).

```console
Inorder: 1 3 5 6 
Postorder: 1 6 5 3 
Preorder: 3 1 5 6
