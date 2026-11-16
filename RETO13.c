//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez arturo Negrete Medellin 
//El programa utiliza estructuras para variables simples en C

#include <stdio.h>
#include <string.h>

struct  Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main(){
    struct Estudiante alumno1;
    
    strcpy_s(alumno1.nombre,sizeof(alumno1.nombre), "Carlos Perez");
    alumno1.edad = 20;
    alumno1.promedio = 9.5;

    printf("--- DATOS DEL ESTUDIANTE (Estructura) ---\n");
    printf("Nombre: %s\n", alumno1.nombre);
    printf("Edad: %d anos\n", alumno1.edad);
    printf("Promedio: %.2f\n", alumno1.promedio);

    return 0;
    
}