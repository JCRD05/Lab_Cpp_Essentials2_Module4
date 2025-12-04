# 4.2.28 LAB: Operators: representing values and values order

## Descripción del Ejercicio

El objetivo de este laboratorio es implementar una Máquina de Estados Finitos (FSM) utilizando `enums` para definir los estados y la sobrecarga de operadores para gestionar la lógica de las transiciones.

El código define la clase `FiniteStateMachine` con cuatro estados posibles: `Start`, `Running`, `Pause` y `End`. Se sobrecarga el operador `>>` para solicitar un cambio de estado. Internamente, la lógica valida si la transición es permitida según el estado actual (por ejemplo, permitiendo pasar de `Start` a `Running`, pero no directamente a `End`). Además, se sobrecarga el operador de inserción `<<` para imprimir la secuencia histórica de todos los estados válidos por los que ha pasado la máquina.

## Salida del Programa

A continuación se muestra la salida del programa, que refleja la secuencia de estados visitados tras una serie de transiciones exitosas definidas en el `main`.

```console
Start Running Pause Running End
