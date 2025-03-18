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

// Implementación del vector dinámico
void vectorInicio(vectorDinamico *V) {
    V->capacidad = CAPACIDAD_INICIAL;
    V->totalElementos = 0;
    V->elementos = malloc(sizeof(void *) * V->capacidad);
}

int totalVector(vectorDinamico *V) {
    return V->totalElementos;
}

static void resizeVector(vectorDinamico *V, int capacidad) {
    printf("Redimensión: %d a %d \n", V->capacidad, capacidad);
    void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
    if (elementos) {
        V->elementos = elementos;
        V->capacidad = capacidad;
    }
}

void addVector(vectorDinamico *V, void *elemento) {
    if (V->capacidad == V->totalElementos)
        resizeVector(V, V->capacidad * 2);
    V->elementos[V->totalElementos++] = elemento;
}

void *getVector(vectorDinamico *V, int indice) {
    if (indice >= 0 && indice < V->totalElementos)
        return V->elementos[indice];
    return NULL;
}

void setVector(vectorDinamico *V, int indice, void *elemento) {
    if (indice >= 0 && indice < V->totalElementos)
        V->elementos[indice] = elemento;
}

void borrarVector(vectorDinamico *V, int indice) {
    if (indice < 0 || indice >= V->totalElementos)
        return;

    for (int i = indice; i < V->totalElementos - 1; i++) {
        V->elementos[i] = V->elementos[i + 1];
    }
    V->totalElementos--;

    if (V->totalElementos > 0 && V->totalElementos == V->capacidad / 4)
        resizeVector(V, V->capacidad / 2);
}

void freeVector(vectorDinamico *V) {
    free(V->elementos);
}

// Implementación de funciones para matrices
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

// Implementación de imprimirMatriz
void imprimirMatriz(int *matriz, int N, const char *nombre) {
    printf("\n%s:\n", nombre);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", matriz[i * N + j]);
        }
        printf("\n");
    }
}

double medir_tiempo(void (*func)(void *), void *param) {
    clock_t inicio, fin;
    inicio = clock();
    func(param);
    fin = clock();
    return ((double)(fin - inicio)) / CLOCKS_PER_SEC;
}

// Función para liberar memoria
void liberarMemoria(int **mA, int **mB, int **mC) {
    free(*mA);
    free(*mB);
    free(*mC);
    *mA = *mB = *mC = NULL;
}
