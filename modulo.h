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

// Inicializa una matriz con un valor específico
void inicializarMatriz(int *matriz, int N, int valor);

// Mide el tiempo de ejecución de una función
double medir_tiempo(void (*func)(void *), void *param);

// Multiplica dos matrices de tamaño N x N
void multiplicarMatrices(int *mA, int *mB, int *mC, int N);

// Imprime una matriz en pantalla
void imprimirMatriz(int *matriz, int N, const char *nombre);

// Libera la memoria asignada dinámicamente
void liberarMemoria(int *mA, int *mB, int *mC);

#endif

