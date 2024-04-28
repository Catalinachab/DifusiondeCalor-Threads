#include "common.h"


static void* diff1(void* arg) {
    cicloDiffusion(MAXCOLUMNAS/2-1, MAXCOLUMNAS/2+1, 0, MAXFILAS); 
    //Hace una difusión considerando todas las filas de la matriz, sin pisar los bordes (fila 0 y fila 128), desde la columna 128, incluyendo esta, hasta el final de las columnas sin pisar el borde de la matriz (columna 256).
    return 0;
}

int main() {

    pthread_t thread1;
    
    // (1) Inicializo todo en temperatura ambiente
    init();

    // (2) Ecuacion de difusion, promedio de vecinos
    for (int iter = 0; iter < maxIter; iter++) {

        // (2.1) seteo las condiciones de contorno
        fijarCondicionesDeContorno();
        // (2.2) seteo condiciones iniciales
        fijarCondicionesiniciales();

        // (2.3) Hago la difusion en dos procesos distintos
        pthread_create(&thread1, NULL, diff1, NULL);   //creo un thread que se ocupa de la ultima mitad de la matriz
        
        cicloDiffusion(0, MAXCOLUMNAS/2+1, 0, MAXFILAS); //Hace una difusión considerando todas las filas de la matriz, sin pisar los bordes (fila 0 y fila 128), desde la columna 1, para no pisar el contorno (columna 0), hasta la mitad de la matriz, la columna 128 inclusive.
        
	  
	  //se espera a que el thread creado termine antes de terminar la ejecución del proceso
        pthread_join(thread1, NULL); 
    }

    // (3) Envio resultado a archivo
        imprimirArchivo("resultadoParallel_2V.txt");

    return 0;
}
