/* Pontificia Universidad Javeriana
Fecha: 13/02/2025
Autor: Jair Santiago Vargas Saenz
Materia: Sistemas Operativos
Temas: Memoria dinámica - Programación modular - Compilación automática
   Programa principal con menú interactivo para vectores y matrices
*/

#include <stdio.h>
#include <stdlib.h>
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

int main() {
    int opcion, N;
    vectorDinamico vector;
    vectorInicio(&vector);

    do {
        printf("\nMenú Principal\n");
        printf("1. Multiplicación de Matrices\n");
        printf("2. Operaciones con Vectores Dinámicos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                printf("Ingrese el tamaño de la matriz (N): ");
                scanf("%d", &N);

                int *mA = malloc(N * N * sizeof(int));
                int *mB = malloc(N * N * sizeof(int));
                int *mC = malloc(N * N * sizeof(int));

                if (!mA || !mB || !mC) {
                    printf("Error al asignar memoria para las matrices.\n");
                    return 1;
                }

                inicializarMatriz(mA, N, 2);
                inicializarMatriz(mB, N, 3);

                imprimirMatriz(mA, N, "Matriz A");

                imprimirMatriz(mB, N, "Matriz B");

                MatrizParams datos = {mA, mB, mC, N};
                double tiempo = medir_tiempo(ejecutarMultiplicacion, &datos);

                imprimirMatriz(mC, N, "Matriz C");

                printf("\nTiempo de ejecución: %f segundos\n", tiempo);

                liberarMemoria(&mA, &mB, &mC);
                break;
            }

            case 2: {
                char *elemento = malloc(20 * sizeof(char));
                printf("Ingrese una cadena para agregar al vector: ");
                scanf("%s", elemento);
                addVector(&vector, elemento);

                printf("Elementos en el vector:\n");
                for (int i = 0; i < totalVector(&vector); i++) {
                    printf("%s ", (char *)getVector(&vector, i));
                }
                printf("\n");
                break;
            }

            case 3:
                freeVector(&vector);
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}

