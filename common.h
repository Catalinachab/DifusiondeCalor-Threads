#ifndef _COMMON_HH_
#define _COMMON_HH_

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>

#define GRUPO 33 // colocar el nro de grupo que corresponda

#define MAXFILAS 128
#define MAXCOLUMNAS 256
#define maxIter 10000
static float data[MAXFILAS][MAXCOLUMNAS];

// == init ==
// Inicializa la matriz
void init(void);

// == fijarCondicionesDeContorno ==
// Setea las condiciones de contorno
void fijarCondicionesDeContorno(void);

// == fijarCondicionesiniciales ==
// Setea las condiciones iniciales
void fijarCondicionesiniciales(void);

// == cicloDiffusionFilas ==
// Hace la difusion sobre xCount columnas e yCount filas,
// partiendo desde la columna x e fila y.
void cicloDiffusion(int x, int xCount, int y, int yCount);

// == imprimirArchivo ==
// Imprime el archivo de salida
void imprimirArchivo(char* file);

#endif
