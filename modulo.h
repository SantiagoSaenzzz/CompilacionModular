#ifndef __MODULO_H_
#define __MODULO_H_

/* Pontificia Universidad Javeriana
Fecha: 13/02/2025
Autor: Jair Santiago Vargas Saenz
Materia: Sistemas Operativos
Temas: Memoria dinámica - Programación modular - Compilación automática
   INTERFAZ DE FUNCIONES: BIBLIOTECA
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACIDAD_INICIAL 4

// Estructura para Vector Dinámico
typedef struct vectorDinamico {
    int capacidad;
    int totalElementos;
    void **elementos;
} vectorDinamico;

// Funciones para vectores dinámicos
void vectorInicio(vectorDinamico *V);

int totalVector(vectorDinamico *V);

void addVector(vectorDinamico *V, void *elemento);

void *getVector(vectorDinamico *V, int indice);

void setVector(vectorDinamico *V, int indice, void *elemento);

void borrarVector(vectorDinamico *V, int indice);

void freeVector(vectorDinamico *V);

// Funciones para matrices
void inicializarMatriz(int *matriz, int N, int valor);

double medir_tiempo(void (*func)(void *), void *param);

void multiplicarMatrices(int *mA, int *mB, int *mC, int N);

void imprimirMatriz(int *matriz, int N, const char *nombre);

void liberarMemoria(int **mA, int **mB, int **mC);

#endif
