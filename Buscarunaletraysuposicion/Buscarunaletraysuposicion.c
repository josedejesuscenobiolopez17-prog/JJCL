//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete  Medellin
//El codigo captura un texto en un arreglo de caracteres y luego busca una letra seleccionada por el usuario y determina su posicion 

#include <stdio.h>
#include <string.h>

int main() {
    char texto[256];
    char letraBuscada;
    int contador = 0;

    printf("Ingresa un texto:");
    fgets(texto, sizeof(texto), stdin);

    texto[strcspn(texto, "\n")] = '\0';
    printf("Ingresa la letra que deseas buscar:");
    scanf_s("%c", &letraBuscada);

    printf("\nBuscando la letra %c en el texto...\n\n", letraBuscada);

    for (int i = 0; texto[i] != '\0';i++) {
        if (texto[i] == letraBuscada){
            contador++;
            printf("- Encontrada en la posicion %d (indice %d)\n", i + 1, i);
        }
       
    }

    if (contador > 0) {
        printf("\nTotal de coincidencias encontradas: %d\n", contador);
    }
    else {
        printf("\nLa letra '%c' no se encuentra en el texto.\n", letraBuscada);

    }

    return 0;

}
