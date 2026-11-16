//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
//El programa entrega un millon de numeros aleatorios al usuario

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 1000000;
    int* arreglo = (int*)malloc(n * sizeof(int));
    if (arreglo == NULL) {
        printf("Error: No se pudo asignar la memoria ");
        return 1;
    }

    arreglo[0] = 10;
    arreglo[500000] = 500;
    arreglo[999999] = 999;

    printf("Primer elemento: %d\n", arreglo[0]);
    printf("Elemento en la posicion 500000: %d\n", arreglo[500000]);
    printf("Ultimo elemento: %d\n", arreglo[999999]);

    free(arreglo);
    
    return 0;

}
