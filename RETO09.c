//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
//Al introducir dos variables los apuntadores de estas  se pasan a una funcion que intercambia los valores 

#include <stdio.h>

// Definición de la función que recibe las direcciones de memoria (punteros)
void intercambiar(int* a, int* b) {
    int temporal;

    // 1. Guardamos el valor que está dentro de la dirección 'a' en la variable temporal
    temporal = *a;

    // 2. Copiamos el valor que está en la dirección 'b' dentro de la dirección 'a'
    *a = *b;

    // 3. Colocamos el valor guardado en temporal dentro de la dirección 'b'
    *b = temporal;
}

int main() {
    int x, y;

    printf("--- INTERCAMBIO CON PUNTEROS ---\n\n");

    // Solicitar los dos valores iniciales
    printf("Introduce el valor para X: ");
    scanf_s("%d", &x);

    printf("Introduce el valor para Y: ");
    scanf_s("%d", &y);

    printf("\nValores originales antes del intercambio:\n");
    printf("X = %d, Y = %d\n", x, y);

    // Llamamos a la función enviando las DIRECCIONES de memoria usando el símbolo '&'
    intercambiar(&x, &y);

    printf("\nValores finales despues del intercambio:\n");
    printf("X = %d, Y = %d\n", x, y);

    return 0;
}
