// UPT Programación Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//Maneja apuntadores con variables simples y arreglos 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // Para soporte correcto de acentos y caracteres especiales

// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
// Muestra diferentes formas de manejar los apuntadores tanto en variables simples como en arreglos

int main() {
    // Configurar la consola en formato UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // =========================================================================
    // PARTE 1: Manejo de apuntadores con variables simples
    // =========================================================================
    int numeroSimple = 42;
    int* ptrSimple = &numeroSimple; // El apuntador guarda la dirección de la variable

    printf("--- PARTE 1: APUNTADORES Y VARIABLES SIMPLES ---\n");
    printf("Valor original de la variable: %d\n", numeroSimple);
    printf("Dirección de memoria de la variable (&numeroSimple): %p\n", (void*)&numeroSimple);
    printf("Dirección almacenada en el apuntador (ptrSimple):      %p\n", (void*)ptrSimple);

    // Modificamos la variable original de forma indirecta usando el apuntador
    *ptrSimple = 99;
    printf("Nuevo valor de la variable modificado mediante el apuntador: %d\n\n", numeroSimple);


    // =========================================================================
    // PARTE 2: Manejo de apuntadores aplicados a Arreglos
    // =========================================================================
    int arreglo[5] = { 10, 20, 30, 40, 50 };
    int* ptrArreglo = arreglo; // Recuerda: el nombre del arreglo ya es una dirección
    int i;

    printf("--- PARTE 2: APUNTADORES Y ARREGLOS ---\n");
    printf("Dirección de inicio del arreglo (arreglo):   %p\n", (void*)arreglo);
    printf("Dirección asignada al apuntador (ptrArreglo): %p\n\n", (void*)ptrArreglo);

    // Forma A: Recorrer el arreglo usando la sintaxis clásica de corchetes
    printf("Forma A (Sintaxis clásica usando corchetes):\n");
    for (i = 0; i < 5; i++) {
        printf("Posición [%d] = %d\n", i, arreglo[i]);
    }

    // Forma B: Recorrer el mismo arreglo usando ARITMÉTICA DE APUNTADORES
    printf("\nForma B (Usando aritmética de apuntadores y desreferenciación):\n");
    for (i = 0; i < 5; i++) {
        // *(ptrArreglo + i) se desplaza 'i' posiciones hacia adelante en la memoria RAM
        printf("Dirección: %p -> Valor: %d\n", (void*)(ptrArreglo + i), *(ptrArreglo + i));
    }

    return 0;
}
