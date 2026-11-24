//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin 
//Ahorcado en su version final recopilando lo visto en clase 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define MAX_LINEA 128
#define MAX_FALLOS 7

typedef struct {
    char** lineas;
    int num_lineas;
} FiguraAhorcado;

typedef struct {
    FiguraAhorcado* figuras;
    int total_figuras;
} SecuenciaAhorcado;

typedef struct {
    char** palabras;
    int total_palabras;
} DiccionarioAhorcado;

static unsigned char a_mayuscula_es(unsigned char c) {
    if (c >= 'a' && c <= 'z') {
        return (unsigned char)(c - ('a' - 'A'));
    }
    switch (c) {
    case 225: return 193; /* á -> Á */
    case 233: return 201; /* é -> É */
    case 237: return 205; /* í -> Í */
    case 243: return 211; /* ó -> Ó */
    case 250: return 218; /* ú -> Ú */
    case 241: return 209; /* ñ -> Ñ */
    case 252: return 220; /* ü -> Ü */
    default:  return c;
    }
}

static unsigned char quitar_acento_es(unsigned char c) {
    switch (c) {
    case 193: case 225: return 'A';
    case 201: case 233: return 'E';
    case 205: case 237: return 'I';
    case 211: case 243: return 'O';
    case 218: case 250: return 'U';
    case 220: case 252: return 'U';
    default:  return a_mayuscula_es(c);
    }
}

static void limpiar_salto(char* cadena) {
    size_t len = strlen(cadena);
    while (len > 0 && (cadena[len - 1] == '\n' || cadena[len - 1] == '\r')) {
        cadena[len - 1] = '\0';
        len--;
    }
}

static int es_separador_figura(const char* linea) {
    if (linea[0] == '\0') {
        return 0;
    }
    for (size_t i = 0; linea[i] != '\0'; i++) {
        if (linea[i] != '*') {
            return 0;
        }
    }
    return 1;
}

static int agregar_linea_figura(FiguraAhorcado* fig, const char* texto) {
    char** nuevo_bloque = (char**)realloc(fig->lineas, sizeof(char*) * (size_t)(fig->num_lineas + 1));
    if (!nuevo_bloque) {
        return 0;
    }
    fig->lineas = nuevo_bloque;

    size_t len = strlen(texto);
    fig->lineas[fig->num_lineas] = (char*)malloc(len + 1);
    if (!fig->lineas[fig->num_lineas]) {
        return 0;
    }
    memcpy(fig->lineas[fig->num_lineas], texto, len + 1);
    fig->num_lineas++;
    return 1;
}

static void liberar_secuencia(SecuenciaAhorcado* sec) {
    if (!sec || !sec->figuras) {
        return;
    }
    for (int i = 0; i < sec->total_figuras; i++) {
        for (int j = 0; j < sec->figuras[i].num_lineas; j++) {
            free(sec->figuras[i].lineas[j]);
        }
        free(sec->figuras[i].lineas);
    }
    free(sec->figuras);
    sec->figuras = NULL;
    sec->total_figuras = 0;
}

static int nueva_figura_en_secuencia(SecuenciaAhorcado* sec, int* figura_activa) {
    FiguraAhorcado* nueva_lista = (FiguraAhorcado*)realloc(
        sec->figuras,
        sizeof(FiguraAhorcado) * (size_t)(sec->total_figuras + 1)
    );
    if (!nueva_lista) {
        return 0;
    }
    sec->figuras = nueva_lista;
    *figura_activa = sec->total_figuras;
    sec->figuras[*figura_activa].lineas = NULL;
    sec->figuras[*figura_activa].num_lineas = 0;
    sec->total_figuras++;
    return 1;
}

static FILE* abrir_archivo_proyecto(const char* nombre_archivo, const char* ruta_debug, const char* ruta_raiz) {
    const char* rutas[] = {
        nombre_archivo,
        ruta_debug,
        "..\\..\\..\\ahorcado.txt",
        ruta_raiz
    };
    /* Ajustar ruta relativa genérica según el nombre solicitado */
    char ruta_relativa[MAX_LINEA];
    snprintf(ruta_relativa, sizeof(ruta_relativa), "..\\..\\..\\%s", nombre_archivo);
    rutas[2] = ruta_relativa;

    FILE* archivo = NULL;
    for (int r = 0; r < 4; r++) {
        if (fopen_s(&archivo, rutas[r], "r") == 0 && archivo != NULL) {
            return archivo;
        }
    }
    return NULL;
}

static int cargar_secuencia(SecuenciaAhorcado* sec, const char* nombre_archivo) {
    FILE* archivo = abrir_archivo_proyecto(
        nombre_archivo,
        "x64\\Debug\\ahorcado.txt",
        "C:\\Users\\DELL\\source\\repos\\JJCL\\RETO15\\ahorcado.txt"
    );
    if (!archivo) {
        return 0;
    }

    sec->figuras = NULL;
    sec->total_figuras = 0;

    char buffer[MAX_LINEA];
    int figura_activa = -1;

    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        limpiar_salto(buffer);

        if (es_separador_figura(buffer)) {
            if (!nueva_figura_en_secuencia(sec, &figura_activa)) {
                fclose(archivo);
                liberar_secuencia(sec);
                return 0;
            }
            continue;
        }

        if (figura_activa < 0) {
            if (!nueva_figura_en_secuencia(sec, &figura_activa)) {
                fclose(archivo);
                liberar_secuencia(sec);
                return 0;
            }
        }

        if (!agregar_linea_figura(&sec->figuras[figura_activa], buffer)) {
            fclose(archivo);
            liberar_secuencia(sec);
            return 0;
        }
    }

    fclose(archivo);
    return (sec->total_figuras > 0);
}

static void liberar_diccionario(DiccionarioAhorcado* dic) {
    if (!dic || !dic->palabras) {
        return;
    }
    for (int i = 0; i < dic->total_palabras; i++) {
        free(dic->palabras[i]);
    }
    free(dic->palabras);
    dic->palabras = NULL;
    dic->total_palabras = 0;
}

static int agregar_palabra_diccionario(DiccionarioAhorcado* dic, const char* texto) {
    char** nueva_lista = (char**)realloc(
        dic->palabras,
        sizeof(char*) * (size_t)(dic->total_palabras + 1)
    );
    if (!nueva_lista) {
        return 0;
    }
    dic->palabras = nueva_lista;

    size_t len = strlen(texto);
    dic->palabras[dic->total_palabras] = (char*)malloc(len + 1);
    if (!dic->palabras[dic->total_palabras]) {
        return 0;
    }
    memcpy(dic->palabras[dic->total_palabras], texto, len + 1);
    dic->total_palabras++;
    return 1;
}

static int cargar_diccionario(DiccionarioAhorcado* dic, const char* nombre_archivo) {
    FILE* archivo = abrir_archivo_proyecto(
        nombre_archivo,
        "x64\\Debug\\diccionario.csv",
        "C:\\Users\\DELL\\source\\repos\\JJCL\\RETO15\\diccionario.csv"
    );
    if (!archivo) {
        return 0;
    }

    dic->palabras = NULL;
    dic->total_palabras = 0;

    char buffer[MAX_LINEA];
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        limpiar_salto(buffer);
        if (buffer[0] == '\0') {
            continue;
        }
        if (!agregar_palabra_diccionario(dic, buffer)) {
            fclose(archivo);
            liberar_diccionario(dic);
            return 0;
        }
    }

    fclose(archivo);
    return (dic->total_palabras > 0);
}

static void mostrar_figura(const SecuenciaAhorcado* sec, int indice) {
    if (!sec || sec->total_figuras <= 0) {
        return;
    }

    if (indice < 0) {
        indice = 0;
    }
    if (indice >= sec->total_figuras) {
        indice = sec->total_figuras - 1;
    }

    const FiguraAhorcado* fig = &sec->figuras[indice];
    for (int i = 0; i < fig->num_lineas; i++) {
        printf("%s\n", fig->lineas[i]);
    }
}

static int ya_intentada(const char* usadas, int total_usadas, unsigned char letra) {
    for (int i = 0; i < total_usadas; i++) {
        if ((unsigned char)usadas[i] == letra) {
            return 1;
        }
    }
    return 0;
}

static int palabra_completa(const char* palabra, const char* usadas, int total_usadas) {
    for (size_t i = 0; palabra[i] != '\0'; i++) {
        unsigned char actual = quitar_acento_es((unsigned char)palabra[i]);
        if (actual == ' ') {
            continue;
        }
        if (!ya_intentada(usadas, total_usadas, actual)) {
            return 0;
        }
    }
    return 1;
}

static void mostrar_palabra_oculta(const char* palabra, const char* usadas, int total_usadas) {
    printf("Palabra: ");
    for (size_t i = 0; palabra[i] != '\0'; i++) {
        unsigned char original = a_mayuscula_es((unsigned char)palabra[i]);
        unsigned char base = quitar_acento_es(original);

        if (original == ' ') {
            printf("  ");
        }
        else if (ya_intentada(usadas, total_usadas, base)) {
            printf("%c ", original);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

static void limpiar_recursos(SecuenciaAhorcado* secuencia, DiccionarioAhorcado* diccionario) {
    liberar_secuencia(secuencia);
    liberar_diccionario(diccionario);
}

int main(void) {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    setlocale(LC_ALL, ".1252");

    SecuenciaAhorcado secuencia = { NULL, 0 };
    if (!cargar_secuencia(&secuencia, "ahorcado.txt")) {
        printf("No se pudo abrir o leer ahorcado.txt\n");
        return 1;
    }

    DiccionarioAhorcado diccionario = { NULL, 0 };
    if (!cargar_diccionario(&diccionario, "diccionario.csv")) {
        printf("No se pudo abrir o leer diccionario.csv\n");
        liberar_secuencia(&secuencia);
        return 1;
    }

    srand((unsigned int)time(NULL));
    const char* secreta = diccionario.palabras[rand() % diccionario.total_palabras];

    char usadas[256] = { 0 };
    int total_usadas = 0;
    int fallos = 0;

    while (fallos <= MAX_FALLOS) {
        system("cls");
        printf("Fallos: %d / %d (7mo fallo = Game Over)\n\n", fallos, MAX_FALLOS);
        mostrar_figura(&secuencia, fallos);
        printf("\n");
        mostrar_palabra_oculta(secreta, usadas, total_usadas);

        printf("Letras Usadas: ");
        for (int i = 0; i < total_usadas; i++) {
            printf("%c ", (unsigned char)usadas[i]);
        }
        printf("\n");

        if (palabra_completa(secreta, usadas, total_usadas)) {
            printf("\nGanaste. La palabra era: %s\n", secreta);
            limpiar_recursos(&secuencia, &diccionario);
            return 0;
        }

        if (fallos == MAX_FALLOS) {
            printf("\nGame Over. La palabra era: %s\n", secreta);
            limpiar_recursos(&secuencia, &diccionario);
            return 0;
        }

        char entrada[64];
        printf("\nIngresa una letra: ");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }
        limpiar_salto(entrada);

        if (strlen(entrada) == 0) {
            continue;
        }

        unsigned char letra = quitar_acento_es((unsigned char)entrada[0]);
        if (!((letra >= 'A' && letra <= 'Z') || letra == 209)) {
            continue;
        }

        if (ya_intentada(usadas, total_usadas, letra)) {
            continue;
        }

        usadas[total_usadas++] = (char)letra;

        int acierto = 0;
        for (size_t i = 0; secreta[i] != '\0'; i++) {
            if (quitar_acento_es((unsigned char)secreta[i]) == letra) {
                acierto = 1;
                break;
            }
        }

        if (!acierto) {
            fallos++;
        }
    }

    limpiar_recursos(&secuencia, &diccionario);
    return 0;
}