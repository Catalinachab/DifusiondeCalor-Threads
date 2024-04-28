#include "common.h"

static void* diff1(void* arg) {
    cicloDiffusion(MAXCOLUMNAS/4-1, MAXCOLUMNAS/4+3, 0, MAXFILAS);
    //Hace una difusión considerando todas las filas de la matriz, sin pisar los bordes (fila 0 y fila 128), desde la columna 64, incluyendo esta, hasta la columna 128, inclusive.
    return 0;
}

static void* diff2(void* arg) {
    cicloDiffusion(MAXCOLUMNAS/2-1, MAXCOLUMNAS/4+3, 0, MAXFILAS);
    //Hace una difusión considerando todas las filas de la matriz, sin pisar los bordes (fila 0 y fila 128), desde la columna 128, incluyendo esta, hasta la columna 192, inclusive.
    return 0;
}
static void* diff3(void* arg) {
    cicloDiffusion(MAXCOLUMNAS/4*3-1, MAXCOLUMNAS/4+1, 0, MAXFILAS);
    //Hace una difusión considerando todas las filas de la matriz, sin pisar los bordes (fila 0 y fila 128), desde la columna 192, incluyendo esta, hasta el final de las columnas sin pisar el borde de la matriz (columna 256).
    return 0;
}

int main() {

    pthread_t thread1, thread2, thread3;
    
    // (1) Inicializo todo en temperatura ambiente
    init();

    // (2) Ecuacion de difusion, promedio de vecinos
    for (int iter = 0; iter < maxIter; iter++) {

        // (2.1) seteo las condiciones de contorno
        fijarCondicionesDeContorno();
        // (2.2) seteo condiciones iniciales
        fijarCondicionesiniciales();

        // (2.3) Hago la difusion en cuatro procesos distintos
        pthread_create(&thread1, NULL, diff1, NULL); //creo un thread que se ocupa del 2do cuarto de la matriz
        pthread_create(&thread2, NULL, diff2, NULL); //creo un thread que se ocupa del 3er cuarto de la matriz
        pthread_create(&thread3, NULL, diff3, NULL); //creo un thread que se ocupa del ultimo cuarto de la matriz
        
        cicloDiffusion(0, MAXCOLUMNAS/4+1, 0, MAXFILAS); //Hace una difusión considerando todas las filas de la matriz, sin pisar los bordes (fila 0 y fila 128), desde la columna 1, para no pisar el contorno (columna 0), hasta un cuarto de la matriz, la columna 64 inclusive.
        
        
        //Se termina haciendo difusión sobre toda la matriz una vez, y 2 veces en las columnas 64, 128 y 192. 
        
        
	  //se espera a que los threads creados terminen antes de terminar la ejecución del proceso
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);

    }

    // (3) Envio resultado a archivo
    imprimirArchivo("resultadoParallel_4V.txt");

    return 0;
}
