// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//Tras ingresar una frase el programa captura un solo caracter y lo busca en la frase, si lo encuentra muestra la posicion de la primera aparicion, si no lo encuentra muestra un mensaje de error.

#include <stdio.h>
#include <string.h> 
#include <windows.h> // Para soporte correcto de acentos y caracteres especiales

// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
// Captura una frase y busca un caracter especifico dentro de ella mostrando su posicion

int main() {
    // Configurar la consola en formato UTF-8 para evitar caracteres extraños
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char frase[100];
    char buscar;
    int i = 0;
    int encontrado = 0; // Funciona como una bandera (0 = no hallado, 1 = hallado)

    printf("--- BÚSQUEDA EN TEXTO ---\n\n");

    // 1. Capturar la frase completa con espacios
    printf("Introduce una frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Eliminar el Enter sobrante de fgets

    // 2. Capturar el carácter a buscar
    printf("Introduce el carácter que deseas buscar: ");
    // El espacio antes de %c es VITAL. Limpia el "Enter" que quedó flotando en el teclado.
    scanf_s(" %c", &buscar);

    printf("\n--- RESULTADOS DE LA BÚSQUEDA ---\n");

    // 3. Recorrer la frase hasta el final marcado por '\0'
    while (frase[i] != '\0') {
        if (frase[i] == buscar) {
            // Imprimimos i + 1 para que la primera letra sea la posición 1 ante el usuario
            printf("¡Hallado! El carácter '%c' se encuentra en la posición: %d\n", buscar, i + 1);
            encontrado = 1; // Cambiamos el estado a encontrado
        }
        i++;
    }

    // 4. Si recorrió todo el texto y la bandera se quedó en 0, no existía la letra
    if (encontrado == 0) {
        printf("El carácter '%c' no fue hallado dentro de la frase.\n", buscar);
    }

    return 0;
}
