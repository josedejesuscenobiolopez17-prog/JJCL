// LeerArduino.cpp : Este archivo contiene la función "main". 
//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin

#include <stdio.h>

int main() {
    FILE* archivo;   // Creamos un contenedor (buffer) para almacenar cada línea que leamos
    char linea[150];

    // Abrimos el archivo en modo de LECTURA ("r")
    fopen_s(&archivo, "C:\\Users\\DELL\\Documents\\Archivo de texto\\datos.txt", "r");

    // Verificamos si el archivo realmente existe en esa ruta
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo para lectura. Verifique la ruta.\n");
        return 1;
    }

    printf("--- CONTENIDO DEL ARCHIVO --- \n\n");

    // Leemos el archivo línea por línea hasta llegar al final (NULL)
    while (fgets(linea, sizeof(linea), archivo) != NULL) {           // Mostramos en la consola negra la línea que acabamos de leer
        printf("%s", linea);
    }

    printf("\n-----------------------------\n");
    printf("Archivo leido con exito.\n");

    // Cerramos el archivo para liberar la memoria del sistema
    fclose(archivo);

    return 0;
}