#include "common.h"


static void* diff1(void* arg) {
    cicloDiffusion(0, MAXCOLUMNAS/2+1, 0, MAXFILAS/2+1); //Considero desde la columna 1, para no pisar el contorno, hasta la 127 inclusive, y desde la fila 1, para no pisar el contorno, hasta la fila 63 inclusive; y hago difusión sobre esa porción de la matiz
    return 0;
}

static void* diff2(void* arg) {
    cicloDiffusion(0, MAXCOLUMNAS/2+1, MAXFILAS/2-1, MAXFILAS/2+1);
    //Considero desde la columna 1, para no pisar el contorno, hasta la 127 inclusive, y desde la fila 64 inclusive, hasta la fila 127, para no pisar el contorno; y hago difusión sobre esa porción de la matiz
    return 0;
}
static void* diff3(void* arg) {
    cicloDiffusion(MAXCOLUMNAS/2-1, MAXCOLUMNAS/2+1, 0, MAXFILAS/2+1);
    //Considero desde la columna 128 inclusive, hasta la 255, para no pisar el contorno, y desde la fila 1, para no pisar el contorno, hasta la fila 63 inclusive; y hago difusión sobre esa porción de la matiz
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
        pthread_create(&thread1, NULL, diff1, NULL); //creo un thread que se ocupa del cuadrado superior izquierdo de la matriz
        pthread_create(&thread2, NULL, diff2, NULL); //creo un thread que se ocupa del cuadrado inferior izquierdo de la matriz
        pthread_create(&thread3, NULL, diff3, NULL); //creo un thread que se ocupa del cuadrado superior derecho de la matriz
        
        cicloDiffusion(MAXCOLUMNAS/2-1, MAXCOLUMNAS/2+1, MAXFILAS/2-1, MAXFILAS/2+1); //Considero desde la columna 128 inclusive, hasta la 255, para no pisar el contorno, y desde la fila 64 inclusive, hasta la fila 127, para no pisar el contorno; y hago difusión sobre esa porción de la matiz (cuadrado inferior derecho)
        

	  //se espera a que los threads creados terminen antes de terminar la ejecución del proceso
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);

    }

    // (3) Envio resultado a archivo
    imprimirArchivo("resultadoParallel_4Box.txt");

    return 0;
}
