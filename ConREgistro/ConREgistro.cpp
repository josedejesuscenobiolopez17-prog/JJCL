// UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
// REcauda datos de personales del usuario y los protege bajo contrasena 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

typedef struct Persona {                                                                                                                                                          
    char nombre[80];
    char usuario[80];
    char correo[80];
    char contraseña[20 ];
    int edad;
    float altura;
} Usuario;

int main () {
         HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
         DWORD modoOriginal, modoNuevo;
         GetConsoleMode(hStdin, &modoOriginal);
         modoNuevo = modoOriginal;

         Usuario* arreglo[2];
         for (int j=0; j < 2; j++){
                  arreglo[j] = (Usuario*)malloc(sizeof(Usuario));

                          printf("Ingresa el nombre:");
                          fgets(arreglo[j]->nombre, sizeof(arreglo[j]->nombre), stdin);
                          printf("Ingresar el usuario:");
                          fgets(arreglo[j]->nombre, sizeof(arreglo[j]->usuario), stdin);
                          printf("Ingrese el correo:");
                          fgets(arreglo[j]->nombre, sizeof(arreglo[j]->correo), stdin);
    
                          printf("Ingrese la contraseña:");
                          modoNuevo &= -ENABLE_ECHO_INPUT;
                          SetConsoleMode(hStdin, modoNuevo);
                          fgets(arreglo[j]->contraseña, sizeof(arreglo[j]->contraseña), stdin);
                          SetConsoleMode(hStdin, modoOriginal);

                          printf("Ingrese la edad:");
                          scanf_s("%d", &arreglo[j] -> edad);
                          printf("Ingrese la altura:");
                          scanf_s("%f", &arreglo[j] -> altura);
                          getchar();
         
         }
         for(int j = 0; j < 2; j++) {
                          printf("/nDatos de usuario %d: /n", j + 1);
                          printf("Nombre: %s", arreglo[j] -> nombre);
                          printf("Usuario: %s", arreglo[j] -> usuario);
                          printf("Coreeo: %s", arreglo[j] -> correo);
                          printf("Contraseña: %s", arreglo[j] -> contraseña);
                          printf("Edad: %d anhos", arreglo[j] -> edad);
                          printf("Altura: %.2fm/n", arreglo[j] ->altura);

         }
         for (int j = 0; j < 2; j++) {
                  free(arreglo[j]);


         }

         return 0;
}