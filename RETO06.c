//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
//Al introducir tres variables x,y, z, el programa determina cual es la mayor de las tres y la imprime en pantalla.

#include <stdio.h>

int main() {
    int num1, num2, num3;
    int mayor;

    printf("--- DETERMINAR EL MAYOR DE TRES NUMEROS ---\n\n");

    // Solicitar los tres números enteros al usuario
    printf("Introduce el primer numero: ");
    scanf_s("%d", &num1);

    printf("Introduce el segundo numero: ");
    scanf_s("%d", &num2);

    printf("Introduce el tercer numero: ");
    scanf_s("%d", &num3);

    // Lógica utilizando operadores lógicos (&&) para evaluar las condiciones
    if (num1 >= num2 && num1 >= num3) {
        mayor = num1;
    }
    else if (num2 >= num1 && num2 >= num3) {
        mayor = num2;
    }
    else {
        mayor = num3;
    }

    // Mostrar el resultado en pantalla
    printf("\nEl numero mayor de los tres ingresados es: %d\n", mayor);

    return 0;
}
