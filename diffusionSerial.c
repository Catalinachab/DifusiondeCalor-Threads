#include "common.h"

int main() {

    // (1) Inicializo todo en temperatura ambiente
    init();

    // (2) Ecuacion de difusion, promedio de vecinos
    for (int iter = 0; iter < maxIter; iter++) {

        // (2.1) seteo las condiciones de contorno
        fijarCondicionesDeContorno();
        // (2.2) seteo condiciones iniciales
        fijarCondicionesiniciales();

        // (2.3) Hago la difusion
        cicloDiffusion(0, MAXCOLUMNAS, 0, MAXFILAS);
        //cicloDiffusionFilas(0,MAXCOLUMNAS);
    }

    // (3) Envio resultado a archivo
    imprimirArchivo("resultadoSerial.txt");

    return 0;
}
