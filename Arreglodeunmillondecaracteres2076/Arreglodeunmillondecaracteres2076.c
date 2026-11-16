// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//El codigo presenta un caracter entre millones posibles

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 1000000;
    char* arreglo = (char*)malloc(n * sizeof(char));

    if (arreglo == NULL) {
        printf("Error: No se pudo asignar la memoria");
        return 1;
    }
    arreglo[0] = 'A';
    arreglo[500000] = 'M';
    arreglo[999999] = 'Z';

    printf("Primer caracter: %c\n", arreglo[0]);
    printf("Caracter en la posicion 500000: %C\n", arreglo[500000]);
    printf("Ultimo caracter: %c\n", arreglo[999999]);

    free(arreglo);

    return 0;

}