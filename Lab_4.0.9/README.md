# 4.0.9 LAB: Operators: non-natural way of using

## Descripción del Ejercicio

El objetivo de este laboratorio es explorar usos alternativos de la sobrecarga de operadores en C++. En lugar de usar los operadores de flujo (`<<` y `>>`) solamente para entrada y salida de texto, se utilizan para modificar el estado de una estructura de datos.

El código implementa una clase `Stack` (Pila) dinámica utilizando punteros inteligentes (`std::unique_ptr`) y una clase `Node` auxiliar.
* **Operador `>>`**: Se sobrecarga para realizar la operación `push`. Al escribir `cin >> stack`, se lee un entero y se inserta en el tope de la pila.
* **Operador `<<`**: Se sobrecarga para inspeccionar el tope (`top`) de la pila sin modificarlo. Si la pila está vacía, captura internamente la excepción y muestra el mensaje de error.

El programa también implementa manejo de excepciones (`std::underflow_error`) para proteger contra intentos de hacer `pop` o leer el tope en una pila vacía.

## Salida del Programa

A continuación se muestra una simulación de la ejecución. En este ejemplo, se insertan 2 elementos pero se intentan sacar 3, demostrando el funcionamiento normal y el manejo de errores.

```console
How many items should be pushed onto the stack? 2
Enter item 1: 10
Enter item 2: 20

How many items should be printed and popped? 3

Popping items:
Popped value: 20
Popped value: 10
Exception occurred: Stack underflow: Cannot pop from empty stack.

Current top of stack: Stack underflow: Cannot print top from empty stack.
