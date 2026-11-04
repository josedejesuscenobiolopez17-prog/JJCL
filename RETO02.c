//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//Es una pequeña calculadora con las operciones basicas de suma, resta, multiplicacion y division

#include <stdio.h>

int main() {
    // Declaración de variables para almacenar los números decimales
    float num1, num2;
    float suma, resta, multiplicacion, division;

    printf("--- CALCULADORA BASICA ---\n\n");

    // Solicitar y leer los dos números del usuario
    printf("Introduce el primer numero: ");
    scanf_s("%f", &num1);

    printf("Introduce el segundo numero: ");
    scanf_s("%f", &num2);

    // Realizar las operaciones aritméticas
    suma = num1 + num2;
    resta = num1 - num2;
    multiplicacion = num1 * num2;

    // Mostrar los resultados en pantalla
    printf("\n--- RESULTADOS ---\n");
    printf("Suma:          %.2f + %.2f = %.2f\n", num1, num2, suma);
    printf("Resta:         %.2f - %.2f = %.2f\n", num1, num2, resta);
    printf("Multiplicacion: %.2f * %.2f = %.2f\n", num1, num2, multiplicacion);

    // Validación para evitar la división por cero
    if (num2 != 0) {
        division = num1 / num2;
        printf("Division:       %.2f / %.2f = %.2f\n", num1, num2, division);
    }
    else {
        printf("Division:       No es posible dividir entre cero.\n");
    }

    return 0;
}
