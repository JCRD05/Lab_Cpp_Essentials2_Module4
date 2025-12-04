# 4.1.4 LAB: Enums: representing values

## Descripción del Ejercicio

El objetivo de este laboratorio es practicar el uso de enumeraciones (`enum class`) para mejorar la legibilidad y seguridad del código al manejar conjuntos de valores relacionados, como los meses del año y los días de la semana.

El código define una clase `Calendar` que encapsula la lógica para manejar fechas posteriores al 1 de enero de 1970 (la época Unix).
* **Enums:** Se utilizan `enum class Month` y `enum class Day` para representar meses y días, mapeándolos posteriormente a cadenas de texto almacenadas en arreglos estáticos (`s_monthsName` y `s_daysName`).
* **Cálculo de fechas:** El método `daysSince1970` calcula el total de días transcurridos sumando los años (considerando bisiestos) y los meses completos.
* **Día de la semana:** El método `toWeekday` utiliza el operador módulo (`%`) sobre el total de días para determinar el día de la semana, asumiendo que el día 0 (1 de enero de 1970) fue jueves.
* **Validación:** El constructor valida rigurosamente las entradas, lanzando excepciones `std::invalid_argument` si el año es anterior a 1970 o si el día no corresponde al mes indicado.

## Salida del Programa

A continuación se muestra una simulación de la ejecución con una fecha válida.

```console
13
3
2016
13 March 2016 Sunday 16873
