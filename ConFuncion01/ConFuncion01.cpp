//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
//

#include <stdio.h>

int respuesta(int a, int b, int c );
void desplegar(int respuesta);
void lectura(int* a, int* b, int* c);

int main() {
    int a, b, c;
    lectura(&a, &b, &c);
    a = 1; b = 2; c = 3;
    desplegar(respuesta(a, b, c));
    printf("Fin del programa %dn", a);
    return 0;
}

int respuesta(int a, int b, int c) {
    if(b * b -4 * a * c >= 0){
        return a + b + c;
    }
    return 0;
}

void desplegar(int respuesta){
    if(respuesta == 0){
        printf("No hay solucion n");
    }
    else{
        printf("La respuesta es: %dn", respuesta);
    }
}

void lectura(int*a, int* b, int* c){
    printf("Ingrese el valor de a:");
    scanf("%d", a);
    printf("Ingrese el valor de b:");
    scanf("%d", b);
    printf("Ingrese el valor de c:");
    scanf("%d", c);
}
