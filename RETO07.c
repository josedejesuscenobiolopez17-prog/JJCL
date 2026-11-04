//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
//Genera un arreglo de 5 elementos y los suma para obtener un resultado final

#include <stdio.h>

int main() {
    // Declaración del arreglo de 5 elementos enteros
    int numeros[5];

    // Variables para el ciclo y para almacenar el resultado acumulado
    int i;
    int suma = 0; // Inicializado en 0 porque es el neutro de la suma

    printf("--- SUMA DE ELEMENTOS EN UN ARREGLO ---\n\n");

    // 1. Entrada de datos: Llenar el arreglo usando un bucle
    printf("Por favor, introduce 5 numeros enteros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        // Guardamos el numero directamente en la posicion 'i' del arreglo
        scanf_s("%d", &numeros[i]);
    }

    // 2. Procesamiento: Recorrer el arreglo para sumar sus elementos
    for (i = 0; i < 5; i++) {
        suma = suma + numeros[i]; // Va sumando lo que hay en cada posicion
    }

    // 3. Salida de resultados
    printf("\nLos numeros guardados fueron: [ ");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("]\n");

    printf("La suma total de todos los elementos es: %d\n", suma);

    return 0;
}
