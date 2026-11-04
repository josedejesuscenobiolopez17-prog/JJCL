//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//El programa logra diferenciar si un numero es par o impar.

#include <stdio.h>

int main() {
    // Declaración de variable para almacenar el número entero
    int numero;

    printf("--- VERIFICADOR DE NUMEROS PARES E IMPARES ---\n\n");

    // Solicitar y leer el número entero ingresado por el usuario
    printf("Introduce un numero entero: ");
	scanf_s("%d", &numero);

    // Condicional utilizando el operador módulo (%) para verificar el residuo
    if (numero % 2 == 0) {
        printf("\nEl numero %d es PAR.\n", numero);
    } else {
        printf("\nEl numero %d es IMPAR.\n", numero);
    }

    return 0;
}
