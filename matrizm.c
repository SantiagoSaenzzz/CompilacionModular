/* Pontificia Universidad Javeriana
Fecha: 13/02/2025
Autor: Jair Santiago Vargas Saenz
Materia: Sistemas Operativos
Temas: Memoria dinámica - Programación modular - Compilación automática
   Programa principal multiplicación de matrices
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h"

typedef struct {
    int *mA;
    int *mB;
    int *mC;
    int N;
} MatrizParams;

void ejecutarMultiplicacion(void *param) {
    MatrizParams *datos = (MatrizParams *)param;
    multiplicarMatrices(datos->mA, datos->mB, datos->mC, datos->N);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamaño de la matriz>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("Error: El tamaño de la matriz debe ser un número positivo.\n");
        return 1;
    }

    int *mA = (int *)malloc(N * N * sizeof(int));
    int *mB = (int *)malloc(N * N * sizeof(int));
    int *mC = (int *)malloc(N * N * sizeof(int));

    if (!mA || !mB || !mC) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    inicializarMatriz(mA, N, 2);
    inicializarMatriz(mB, N, 3);

    imprimirMatriz(mA, N, "Matriz A");
    imprimirMatriz(mB, N, "Matriz B");

    // Estructura para pasar parámetros
    MatrizParams datos = {mA, mB, mC, N};
    
    // Medir tiempo con la nueva función
    double tiempo = medir_tiempo(ejecutarMultiplicacion, &datos);

    printf("\nMultiplicación de matrices tomó %f segundos en ejecutarse\n", tiempo);
    imprimirMatriz(mC, N, "Matriz C (Resultado)");

    liberarMemoria(mA, mB, mC);
    return 0;
}

