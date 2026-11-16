// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
// arduino.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <stdio.h>

int main() {
	FILE* archivo;
	int giroMotor = 1500;

	fopen_s(&archivo, "C:\\Users\\DELL\\Documents\\Archivo de texto\\datos.txt", "w");

	if (archivo == NULL) {
		printf("Error al crear o abrir el archivo. \n");
		return 1;
	}
		
	fprintf(archivo, "Hola Mundo desde el lenguaje C. \n");
	fprintf(archivo, "Giro del Motor: %d RPM \n", giroMotor);
	fputs("Esta es una linea adicional. \n", archivo);

	fclose(archivo);

	printf("Archivo escrito con exito \n");
	return 0;
	
}