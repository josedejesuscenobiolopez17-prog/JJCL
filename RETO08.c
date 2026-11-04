//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
//En una cadena de caracteres  el codigo encuentra las vocales que contiene y las imprime en pantalla

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Declaramos un arreglo de caracteres para almacenar la palabra (máximo 50 letras)
    char palabra[50];
    int i = 0;
    int vocales = 0;

    printf("--- CONTADOR DE VOCALES ---\n\n");

    // Solicitar la palabra al usuario
    printf("Introduce una sola palabra: ");
    // Con %s leemos una cadena de texto completa (sin espacios)
    scanf("%s", palabra);

    /*
       Bucle 'while': Recorre la palabra letra por letra hasta llegar al
       carácter nulo '\0', que indica automáticamente el final de cualquier texto en C.
    */
    while (palabra[i] != '\0') {

        // Estructura 'switch-case' para evaluar la letra actual
        switch (palabra[i]) {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            vocales++; // Si coincide con cualquiera de estas, sumamos 1 vocal
            break;
        default:
            // Si es una consonante o cualquier otro carácter, no hace nada
            break;
        }

        i++; // Avanzamos a la siguiente posición del arreglo
    }

    // Mostrar el resultado final
    printf("\nLa palabra \"%s\" contiene un total de: %d vocales.\n", palabra, vocales);

    return 0;
}
