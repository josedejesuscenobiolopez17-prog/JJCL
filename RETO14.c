//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//El programa utiliza estructuras arreglos y apuntadores a manera de almacenar y mostrar los datos.

#include <stdio.h>
#include <string.h>

#define TOTAL_ELEMENTOS 3

typedef struct {
    int id;
    char nombre[60]; // Aumentado a 60 para nombres largos con espacios
    float promedio;
} Estudiante;

void capturarDatos(Estudiante* ptrGrupo, int cantidad);
void mostrarConApuntadores(const Estudiante* ptrGrupo, int cantidad);
void aplicarBono(Estudiante* ptrEstudiante, float puntosExtra);

int main(void) {
    Estudiante grupo[TOTAL_ELEMENTOS];

    Estudiante* ptr = grupo;

    printf(" ARREGLOS, ESTRUCTURAS Y APUNTADORES EN C \n");

    capturarDatos(ptr, TOTAL_ELEMENTOS);

    printf("\n- RESULTADOS INICIALES -\n");
    mostrarConApuntadores(ptr, TOTAL_ELEMENTOS);

    printf("\n- APLICANDO BONO DE +0.5 AL SEGUNDO ESTUDIANTE VIA APUNTADOR -\n");
    aplicarBono(ptr + 1, 0.5f);

    printf("\n- RESULTADOS ACTUALIZADOS -\n");
    mostrarConApuntadores(ptr, TOTAL_ELEMENTOS);

    return 0;
}

void capturarDatos(Estudiante* ptrGrupo, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Registro #%d:\n", i + 1);

        (ptrGrupo + i)->id = 100 + (i + 1);

        printf("  Ingresa nombre completo: ");
        fgets((ptrGrupo + i)->nombre, sizeof((ptrGrupo + i)->nombre), stdin);

        (ptrGrupo + i)->nombre[strcspn((ptrGrupo + i)->nombre, "\n")] = '\0';

        printf("  Ingresa promedio: ");
        scanf_s("%f", &(ptrGrupo + i)->promedio);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\n");
    }
}

void mostrarConApuntadores(const Estudiante* ptrGrupo, int cantidad) {
    for (int i = 0; i < cantidad; i++) {

        const Estudiante* actual = ptrGrupo + i;

        printf("Elemento [%d] | Direccion Memoria: %p\n", i, (void*)actual);
        printf("   -> ID: %d | Nombre: %-30s | Promedio: %.2f\n",
            actual->id, actual->nombre, actual->promedio);
    }
}

void aplicarBono(Estudiante* ptrEstudiante, float puntosExtra) {
    if (ptrEstudiante != NULL) {
        printf("Modificando registro en direccion %p (%s)...\n",
            (void*)ptrEstudiante, ptrEstudiante->nombre);
        ptrEstudiante->promedio += puntosExtra;
    }
}