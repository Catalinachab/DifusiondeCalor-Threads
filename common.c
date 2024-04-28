#include "common.h"



void init(void) {
    for (int i = 0; i < MAXFILAS; i++) {
        for (int j = 0; j < MAXCOLUMNAS; j++) {
            data[i][j] = 25;
        }
    }
}

void fijarCondicionesDeContorno(void) {
    for (int i = 1; i < MAXFILAS - 1; i++) data[i][0] = 25;
    for (int i = 1; i < MAXFILAS - 1; i++) data[i][MAXCOLUMNAS - 1] = 25;
    for (int i = 0; i < MAXCOLUMNAS; i++) data[0][i] = 25;
    for (int i = 0; i < MAXCOLUMNAS; i++) data[MAXFILAS - 1][i] = 25;
}

void fijarCalor(int x, int xCount, int y, int yCount) {
    for (int i = y; i < y+yCount; i++) {
        for (int j = x; j < x+xCount; j++) {
                data[i][j] = 500;
        }
    }
}

void fijarCondicionesiniciales(void) {
    int size = (7 * GRUPO + 3) % 10 + 6;
    int pos = (7 * GRUPO + 3) % (MAXFILAS/4);
    fijarCalor(0, 3, MAXFILAS/2-size/2-pos, size);
    fijarCalor(MAXCOLUMNAS-3, 3, MAXFILAS/2-size/2+pos, size);

}

void cicloDiffusion(int x, int xCount, int y, int yCount) {
    for (int i = y+1; i < y+yCount-1; i++) {
        for (int j = x+1; j < x+xCount-1; j++) {
            data[i][j] = (data[i-1][j] +
                          data[i][j-1] +
                          data[i][j]   +
                          data[i+1][j] +
                          data[i][j+1]) / 5.0;
        }
    }
}

void imprimirArchivo(char* file) {
    FILE* fp;
    fp = fopen(file, "w");
    for (int i = 0; i < MAXFILAS; i++) {
        fprintf(fp, "%.2f", data[i][0]);
        for (int j = 0; j < MAXCOLUMNAS; j++) {
            fprintf(fp, " %.2f", data[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
