# Simulación de Difusión de Calor con Threads

En este trabajo, nos enfocaremos en el uso de threads para simular la difusión de calor sobre una superficie, partiendo de un algoritmo de difusión serial como base. Nuestro objetivo es paralelizar el algoritmo en 2 y 4 threads, aplicando diversas estrategias de división del problema, y analizar el rendimiento de cada implementación.

## Threads en Programación

Los threads, también conocidos como hilos, son unidades de ejecución más pequeñas que los procesos. Mientras que un proceso es una instancia en ejecución de un programa, los threads son subprocesos que pueden ejecutar tareas de forma concurrente dentro del mismo proceso. 
### Ventajas de Utilizar Threads
- **Mejora de Rendimiento:** La ejecución concurrente de tareas mejora significativamente el rendimiento de una aplicación al utilizar eficientemente los recursos de la CPU.
- **Mayor Capacidad de Respuesta:** Permite que una aplicación pueda responder a múltiples eventos y solicitudes simultáneamente, mejorando la experiencia del usuario.
- **Uso Eficiente de Recursos:** Al compartir recursos como la memoria y otros elementos del proceso, los threads utilizan menos recursos que los procesos independientes, reduciendo la sobrecarga del sistema.
- **Programación Flexible:** La programación con threads permite desarrollar aplicaciones más flexibles y escalables al dividir tareas complejas en subprocesos manejables y paralelos.

## Implementación del Algoritmo de Difusión de Calor

Para simular la difusión de calor, como ya fue mencionado, partimos de un algoritmo serial `diffusionSerial.c` que configura las condiciones iniciales y de contorno del sistema. Este algoritmo realiza un número fijo de iteraciones del proceso de difusión, obteniendo una matriz de temperaturas que se guarda en un archivo de texto.

En nuestro enfoque de paralelización, dividimos la matriz en 2 y 4 secciones tanto horizontal como verticalmente, es decir, en columnas y filas. Las implementaciones de estas paralelizaciones se encuentran en los archivos de `diffusionParallel 2H.c`, `diffusionParallel 2V.c`, `diffusionParallel 4V.c` y `diffusionParallel 4H.c`. También desarrollamos una estrategia que emplea cuatro threads y divide la matriz simultáneamente por filas y columnas en `diffusionParallel 4Box.c`.

En el archivo `common.c` se encuentran las implementaciones de las funciones para configurar las condiciones iniciales y de contorno del sistema, así como para realizar la difusión. Los archivos `resultado*.pdf` muestran visualizaciones de las difusiones de calor realizadas con y sin threads. Estas visualizaciones fueron generadas con la librería matplotlib.

## Tabla de Tiempos y Análisis de Eficiencia

Finalmente, realizamos mediciones de tiempo para cada implementación (`duration`), incluyendo `diffusionSerial`, `diffusionParallel 2H`, `diffusionParallel 2V`, `diffusionParallel 4H`, `diffusionParallel 4V`, y `diffusionParallel 4Box`. Estas mediciones nos permitieron comparar la eficiencia y sacar conclusiones sobre el rendimiento de cada estrategia de paralelización.
