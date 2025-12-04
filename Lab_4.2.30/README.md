# 4.2.30 LAB: Operators: arithmetic operators

## Descripción del Ejercicio

El objetivo de este laboratorio es implementar una clase `Matrix` robusta que soporte operaciones aritméticas mediante la sobrecarga de operadores. El código permite realizar sumas, restas y multiplicaciones, tanto con valores escalares (enteros) como entre dos matrices.

La implementación incluye:
* **Operadores Aritméticos (`+`, `-`, `*`)**: Sobrecargados para soportar operaciones escalar-matriz y matriz-matriz.
* **Multiplicación Matricial**: La lógica del operador `*` entre matrices implementa el producto matricial (fila por columna).
* **Manejo de Excepciones**: Se validan rigurosamente las dimensiones. Se lanzan excepciones `std::invalid_argument` si se intenta crear una matriz con dimensiones inválidas, llenar una matriz con datos insuficientes, sumar/restar matrices de tamaños distintos o multiplicar matrices cuyas dimensiones internas no coinciden (columnas de A != filas de B).

## Salida del Programa

A continuación se muestra la salida del programa, que demuestra las operaciones exitosas y luego ejecuta una batería de pruebas para confirmar que todas las excepciones se lanzan y capturan correctamente.

```console
--- Initial Matrices ---
Matrix 1 (All 1s):
   1    1    1 
   1    1    1 
   1    1    1 

Matrix 2 (All 3s):
   3    3    3 
   3    3    3 
   3    3    3 

--- Scalar Operations ---
Mat1 + 5:
   6    6    6 
   6    6    6 
   6    6    6 

Mat3 - 1:
   2    2    2 
   2    2    2 
   2    2    2 

Mat1 * 2:
   2    2    2 
   2    2    2 
   2    2    2 

--- Matrix Operations ---
Mat1 + Mat3:
   4    4    4 
   4    4    4 
   4    4    4 

Mat3 - Mat1:
   2    2    2 
   2    2    2 
   2    2    2 

Mat1 * Mat3:
   9    9    9 
   9    9    9 
   9    9    9 

Matrix 3 (Different Size 2x4):
   2    2    2    2 
   2    2    2    2 

--- Testing Exceptions ---
Test 1: Invalid Constructor... Caught: Error: Number of rows/columns cannot be less than 1
Test 2: Invalid Fill size... Caught: Error: not enough values to fill the matrix
Test 3: Addition Dimension Mismatch (3x3 + 2x4)... Caught: Error: Unmatch Matrices Dimensions (Rows and Columns must match)
Test 4: Subtraction Dimension Mismatch (3x3 - 2x4)... Caught: Error: Unmatch Matrices Dimensions (Rows and Columns must match)
Test 5: Multiplication Dimension Mismatch (3x3 * 2x4)... Caught: Error: Invalid Matrices Dimensions for Multiplication
