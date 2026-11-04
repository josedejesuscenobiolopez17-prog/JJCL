//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//Multiplicacion de una variable numerica desde el 1 hasta el 10

#include <stdio.h>

int main() {
    // Variables para el número que elija el usuario y para el contador del ciclo
    int numero;
    int i;

    printf("--- GENERADOR DE TABLAS DE MULTIPLICAR ---\n\n");

    // Solicitar el número al usuario
    printf("De que numero deseas ver la tabla de multiplicar?: ");
    scanf_s("%d", &numero);

    printf("\n--- TABLA DEL %d ---\n", numero);

    /*
       Bucle 'for':
       - Comienza en i = 1
       - Se repite mientras i sea menor o igual a 10 (i <= 10)
       - Aumenta de 1 en 1 en cada vuelta (i++)
    */
    for (i = 1; i <= 10; i++) {
        // Imprime de forma ordenada: Numero x i = Resultado
        printf("%d x %2d = %d\n", numero, i, numero * i);
    }

    printf("--------------------\n");

    return 0;
}
