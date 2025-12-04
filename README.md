# Lab_Cpp_Essentials2_Module4

## Contexto del Proyecto

Este repositorio agrupa las soluciones a todos los laboratorios prácticos del **Módulo 4: "Operators"**, correspondiente al curso **"C++ Essentials 2"** de Cisco Networking Academy.

El objetivo principal de este módulo es dominar la **sobrecarga de operadores** en C++. Se explora cómo redefinir el comportamiento de los operadores estándar (aritméticos, lógicos, de flujo, etc.) para trabajar con tipos de datos definidos por el usuario, permitiendo una sintaxis más intuitiva y natural. Además, se profundiza en el uso de **enumeraciones** (`enum class`) y estructuras de datos dinámicas complejas.

## Contenido del Repositorio

A continuación se listan los proyectos y ejercicios contenidos en este repositorio:

* **4.0.8:** Operators: iostream and operators (Matrix2x2)
* **4.0.9:** Operators: non-natural way of using (Stack)
* **4.1.4:** Enums: representing values (Calendar)
* **4.2.27:** Operators: iostream (Binary Tree)
* **4.2.28:** Operators: representing values and values order (Finite State Machine)
* **4.2.29:** Operators: complex classes (Tree Hierarchy & Traversal)
* **4.2.30:** Operators: arithmetic operators (Matrix Algebra)

---

## Herramientas Utilizadas

* **Lenguaje:** C++
* **Compilador:** Compatible con g++, Clang, o MSVC (se recomienda C++14 o superior debido al uso de `std::make_unique` y `std::string_view`).
* **Librerías:** Biblioteca Estándar de C++ (`iostream`, `vector`, `memory`, `iomanip`, etc.).

---

## Compilación y Ejecución

El código de cada laboratorio es autocontenido. Para compilar y ejecutar cualquiera de los ejercicios, se puede utilizar un compilador de C++ estándar como g++.

**Ejemplo de compilación con g++:**
```bash
# Para un proyecto con varios archivos .cpp
g++ main.cpp Clase1.cpp Clase2.cpp -o ejecutable

# Para un proyecto simple
g++ main.cpp -o ejecutable
````

## Conceptos Clave Practicados

A lo largo de estos laboratorios, se aplican los siguientes conceptos clave:

  * **Sobrecarga de Operadores de Flujo:** Redefinición de `<<` y `>>` para imprimir y leer objetos personalizados directamente con `std::cout` y `std::cin`.
  * **Sobrecarga de Operadores Aritméticos:** Implementación de `+`, `-`, `*` para clases matemáticas como matrices.
  * **Sobrecarga de Operadores de Acceso:** Uso de `[]` (subscript) para acceder a elementos internos de una estructura.
  * **Funciones Amigas (Friends):** Uso de `friend` para permitir que los operadores globales accedan a miembros privados.
  * **Enumeraciones Fuertemente Tipadas:** Uso de `enum class` para representar conjuntos de valores constantes (días, meses, estados) de forma segura.
  * **Punteros Inteligentes:** Uso extensivo de `std::unique_ptr` para la gestión automática de memoria en estructuras de datos dinámicas (árboles y pilas).
  * **Estructuras de Datos Avanzadas:** Implementación y recorrido de Árboles Binarios, Máquinas de Estados Finitos (FSM) y Matrices.
