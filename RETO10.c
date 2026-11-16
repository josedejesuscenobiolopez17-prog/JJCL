//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//Recopila datos personales de un usuario y los muestra en pantalla de forma ordenada y clara

#include <stdio.h>
#include <string.h> 
#include <windows.h> // 1. Cambiamos locale.h por la librería nativa de Windows

// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
// Recopila datos personales de un usuario y los muestra en pantalla de forma ordenada y clara

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    // 2. Obliga a la terminal a procesar e imprimir en formato UTF-8 (Código 65001)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    struct Estudiante alumno;

    printf("--- REGISTRO DE ESTUDIANTE ---\n\n");

    printf("Introduce el nombre completo del alumno: ");
    fgets(alumno.nombre, sizeof(alumno.nombre), stdin);
    alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0';

    printf("Introduce la edad del alumno: ");
    scanf_s("%d", &alumno.edad);

    printf("Introduce el promedio del alumno: ");
    scanf_s("%f", &alumno.promedio);

    // 3. Mostrar la información formateada en pantalla con acentos y 'ñ' reales
    printf("\n========================================\n");
    printf("          INFORMACIÓN DEL ALUMNO        \n");
    printf("========================================\n");
    printf("Nombre:   %s\n", alumno.nombre);
    printf("Edad:     %d años\n", alumno.edad);
    printf("Promedio: %.2f\n", alumno.promedio);
    printf("========================================\n");

    return 0;
}
