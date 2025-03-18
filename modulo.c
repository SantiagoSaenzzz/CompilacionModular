/* Pontificia Universidad Javeriana
Fecha: 13/02/2025
Autor: Jair Santiago Vargas Saenz
Materia: Sistemas Operativos
Temas: Memoria dinámica - Programación modular - Compilación automática
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h"

void inicializarMatriz(int *matriz, int N, int valor) {
    for (int i = 0; i < N * N; i++) {
        matriz[i] = valor + i;
    }
}

void multiplicarMatrices(int *mA, int *mB, int *mC, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mC[i * N + j] = 0;
            for (int k = 0; k < N; k++) {
                mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
            }
        }
    }
}

//función para medir el tiempo de ejecución
double medir_tiempo(void (*func)(void *), void *param) {
    clock_t inicio, fin;
    inicio = clock();
    func(param);  // Llamada a la función con parámetro
    fin = clock();
    return ((double)(fin - inicio)) / CLOCKS_PER_SEC;
}

void imprimirMatriz(int *matriz, int N, const char *nombre) {
    printf("\n%s:\n", nombre);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", matriz[i * N + j]);
        }
        printf("\n");
    }
}

void liberarMemoria(int *mA, int *mB, int *mC) {
    free(mA);
    free(mB);
    free(mC);
}

