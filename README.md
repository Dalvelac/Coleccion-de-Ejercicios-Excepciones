https://github.com/Dalvelac/Coleccion-de-Ejercicios-Excepciones

# Coleccion-de-Ejercicios-Excepciones

## Enunciado de los ejercicios

```
    Los enfoques de bajo nivel: Banderas e interrupciones y tratamiento de los errores en lenguaje C:
        Ejercicio: Implementa un programa en C++ que simule un sistema con banderas de error. Si ocurre un error, en lugar de lanzar una excepción, establece una bandera de error. Luego, comprueba regularmente la bandera de error para manejarla.

    Las excepciones son más seguras que los errores:
        Ejercicio: Implementa dos versiones de una función que pueda provocar un error (como la división por cero). La primera versión debe manejar el error devolviendo un valor de error, mientras que la segunda versión debe lanzar una excepción en caso de error. Compara la seguridad y facilidad de uso de ambas versiones.

    Propagación explícita:
        Ejercicio: Crea un programa que demuestre cómo se propaga una excepción a través de varias funciones. Asegúrate de que algunas funciones no manejen la excepción, de modo que tenga que propagarse hasta una función que la maneje.

    Tipos de excepciones personalizadas: Definición de clases de excepción, Instanciación de clases, Clases de excepción derivadas:
        Ejercicio: Define tus propias clases de excepción que hereden de la clase std::exception. Haz que estas clases representen diferentes tipos de errores que podrían ocurrir en tu programa. Utiliza estas excepciones en tu programa y asegúrate de que se manejan correctamente.

    Manejo de una excepción y reactivación:
        Ejercicio: Escribe un programa en el que una función lanza una excepción, la cual es manejada en otra parte del programa. Luego, la excepción se relanza para que sea manejada por otro manejador de excepciones.

    Excepciones no interceptadas:
        Ejercicio: Escribe un programa que lance una excepción que no sea capturada por ningún bloque de catch. Observa lo que sucede cuando se ejecuta el programa.

    Adquisición de recursos:
        Ejercicio: Implementa una clase que adquiere un recurso (como memoria dinámica o un archivo) en su constructor y libera el recurso en su destructor. Haz que el constructor lance una excepción si no se puede adquirir el recurso. Demuestra que, a pesar de la excepción, no se produce una fuga de recursos.

Recuerda que debes encerrar cada uno de estos ejercicios en bloques de try/catch para manejar las excepciones y así evitar que tu programa se cierre inesperadamente.

```

## Output de cada ejercicio y explicación

### Ejercicio 1 - Banderas de error 

```
Error: Division por 0 
```
En este ejercicio, se utiliza una bandera (`flag`) para indicar si ha ocurrido un error durante una operación de división. Si el divisor es 0, el programa activa una bandera de error y luego verifica esta bandera para determinar si ocurrió una división por cero. Este es un manejo de errores básico que usa una variable booleana para indicar el error sin interrumpir el programa.

### Ejercicio 2 - Excepciones

```
Error: Division por 0
Esta es la excepcionError: Division por 0
```
Aquí se utiliza el manejo de excepciones para interceptar errores como la división por cero. En lugar de usar una bandera de error, se lanza una excepción (`throw`) que es capturada con un bloque `catch`. Esto permite manejar el error y evitar que el programa termine de forma abrupta.

### Ejercicio 3 - Propagacion de excepciones

```
Esta es la excepcion: Error en func3
``` 
Este ejercicio demuestra la **propagación de excepciones**. Una excepción lanzada en una función más profunda (como `func3`) se propaga hacia arriba en la cadena de llamadas hasta que es capturada en un nivel superior, posiblemente en el `main`. Esto permite delegar el manejo de errores a niveles más altos cuando las funciones internas no pueden manejarlos directamente.

### Ejercicio 4 - Excepciones personalizadas

```
Esta es la excepcion: Error en func3a
```
Se introduce el concepto de **excepciones personalizadas**. En lugar de usar las excepciones estándar de C++, se crea una clase personalizada para las excepciones. Esto permite que el mensaje de error y el tipo de excepción sean específicos a las necesidades del programa, proporcionando más control sobre cómo se manejan los errores.

### Ejercicio 5 - Manejo de excepciones y reactivacion

```
Esta es la excepcion: Error en func3b 
```
Este ejercicio trata sobre la **reactivación de excepciones**. Después de capturar una excepción en un bloque `catch`, se puede decidir no manejarla completamente en ese nivel y volver a lanzarla (`throw`) para que sea manejada en un nivel superior de la pila de llamadas. Esto permite que las funciones manejen parcialmente un error y deleguen el manejo final a otras funciones.

### Ejercicio 6 - Excepciones no interceptadas

```
Esta es la excepcion: Error en func3b
```
Aquí se ilustra lo que ocurre cuando una excepción no es capturada en ningún nivel de la pila de llamadas. La excepción se propaga sin ser manejada, lo que podría provocar que el programa termine abruptamente si no se implementa un mecanismo de captura global. Este comportamiento se observa cuando una función lanza una excepción pero ninguna otra función la maneja.

### Ejercicio 7 - Adquisicion de recursos

```
Memoria creada exitosamente
```
Este ejercicio muestra el patrón RAII (**Resource Acquisition Is Initialization**) en C++, donde los recursos como la memoria dinámica se adquieren y liberan automáticamente utilizando constructores y destructores. El programa crea correctamente memoria, asegurándose de que los recursos se liberen adecuadamente al finalizar, evitando fugas de memoria.

### Ejercicio 8 - Excepciones no interceptadas

```
Esta es la excepcion: No se puede escribir en el archivo
```
El ejercicio muestra cómo se maneja una excepción cuando ocurre un error al escribir en un archivo. Si el archivo no se puede abrir o escribir, se lanza una excepción, que luego puede ser capturada para manejar el error de forma adecuada. Esto es útil para detectar problemas relacionados con la escritura de archivos, como permisos o espacio insuficiente en disco.