// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
// Multiplica dos matrizes cada una con un valor de 

#include <stdio.h>

int main() {
    int filasA, columnasA;
    int filasB, columnsB; // columnasB

    // 1. Pedir dimensiones de la Matriz A
    printf("--- MATRIZ A ---\n");
    printf("Introduce el numero de filas de A: ");
    scanf_s("%d", &filasA);
    printf("Introduce el numero de columnas de A: ");
    scanf_s("%d", &columnasA);

    // 2. Pedir dimensiones de la Matriz B
    printf("\n--- MATRIZ B ---\n");
    printf("Introduce el numero de filas de B: ");
    scanf_s("%d", &filasB);
    printf("Introduce el numero de columnas de B: ");
    scanf_s("%d", &columnsB);

    // 3. VALIDACIÓN DE ORO: Columnas de A debe ser igual a Filas de B
    if (columnasA != filasB) {
        printf("\n[ERROR] No se pueden multiplicar las matrices.\n");
        printf("El numero de columnas de A (%d) debe ser IGUAL al numero de filas de B (%d).\n", columnasA, filasB);
        return 1; // Termina el programa con código de error
    }

    // 4. Creación de matrices con espacio máximo estático (Solución para Visual Studio)
    int matrizA[100][100];
    int matrizB[100][100];
    int matrizResultante[100][100];

    int i, j, k; // Variables para los bucles for

    // 5. Leer los datos de la Matriz A
    printf("\n--- INTRODUCE LOS DATOS DE LA MATRIZ A (%dx%d) ---\n", filasA, columnasA);
    for (i = 0; i < filasA; i++) {
        for (j = 0; j < columnasA; j++) {
            printf("MatrizA[%d][%d]: ", i, j);
            scanf_s("%d", &matrizA[i][j]);
        }
    }

    // 6. Leer los datos de la Matriz B
    printf("\n--- INTRODUCE LOS DATOS DE LA MATRIZ B (%dx%d) ---\n", filasB, columnsB);
    for (i = 0; i < filasB; i++) {
        for (j = 0; j < columnsB; j++) {
            printf("MatrizB[%d][%d]: ", i, j);
            scanf_s("%d", &matrizB[i][j]);
        }
    }

    // 7. Inicializar la Matriz Resultante con ceros e implementar la Multiplicación
    // El algoritmo requiere 3 bucles anidados ('i' para filas de A, 'j' para columnas de B, 'k' para recorrer el producto)
    for (i = 0; i < filasA; i++) {
        for (j = 0; j < columnsB; j++) {
            matrizResultante[i][j] = 0; // Limpieza preventiva para evitar basura
            for (k = 0; k < columnasA; k++) {
                matrizResultante[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // 8. Imprimir el resultado final
    printf("\n=========================================\n");
    printf("   MATRIZ RESULTANTE (%dx%d)\n", filasA, columnsB);
    printf("=========================================\n");
    for (i = 0; i < filasA; i++) {
        for (j = 0; j < columnsB; j++) {
            printf("%d\t", matrizResultante[i][j]);
        }
        printf("\n");
    }

    return 0;
}
