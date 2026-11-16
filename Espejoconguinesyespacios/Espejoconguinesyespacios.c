//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//El codigo es capaz de leer un texto aun con espacios y guiones bajos (_)

#include <stdio.h>
#include <string.h>

int main() {
    char texto[500];

    printf("Ingresa una palabra o texto:");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    int len = strlen(texto);

    printf("\nGenerando espejo:\n\n");
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", texto[j]);
        }
    
        printf("_");
        for (int j = i; j >= 0;j--) {
             printf("%c", texto[j]);
        }
        printf("\n");

    }
    return 0;

}