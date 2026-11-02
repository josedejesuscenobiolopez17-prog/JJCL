//UPT Programacion Estructurada Jose de Jesus Cenonio Lopez Arturo Negrete Medellin 
//El programa calcular el numero factorial de una variable x enviada por el usuario, debe ser un numero entero positivo, el programa debe validar que el numero sea positivo 
 
#include <stdio.h>

int main() {
    int numero;
    int i;

    // Usamos 'unsigned long long' (64 bits sin signo) debido al "Desbordamiento de tipos"
    // Inicializado en 1 porque es el elemento neutro de la multiplicacion
    unsigned long long factorial = 1;

	printf("--- CALCULO DE UN FACTORIAL ---\n\n");

    // Solicitar el número al usuario
    printf("Introduce un numero entero positivo: ");
    scanf_s("%d", &numero);

    // 1. Validar que el número no sea negativo
    if (numero < 0) {
        printf("\nError: No se puede calcular el factorial de un numero negativo.\n");
    }
    // 2. Controlar el desbordamiento de tipo (Límite físico de 64 bits)
    else if (numero > 20) {
        printf("\n[Alerta de Desbordamiento]: El numero es demasiado grande.\n");
        printf("El resultado supera los 64 bits de almacenamiento (limite en 20!).\n");
    }
    // 3. Proceder con el cálculo si está en el rango seguro
    else {
        // El bucle multiplica consecutivamente: 1 * 2 * 3 * ... * numero
        for (i = 1; i <= numero; i++) {
            factorial = factorial * i; // Acumulador multiplicativo
        }

        // %llu es el especificador de formato para unsigned long long
        printf("\nEl factorial de %d (%d!) es: %llu\n", numero, numero, factorial);
    }

    return 0;
}