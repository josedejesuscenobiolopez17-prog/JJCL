//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//El codigo es capaz de leer una frase aun con espacios y guiones bajos (_)

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Para system("cls")

using namespace std;

int main() {
    
    setlocale(LC_ALL, "");

    string fraseSecreta;
    cout << "= JUEGO DEL AHORCADO =" << endl;
    cout << "Introduce la palabra o frase: ";

    getline(cin, fraseSecreta);

    string progreso(fraseSecreta.length(), '*');

    for (size_t i = 0; i < fraseSecreta.length(); i++) {
        if (fraseSecreta[i] == ' ' || fraseSecreta[i] == '_') {
            progreso[i] = fraseSecreta[i];
        }
    }

    system("cls");

    int vidas = 6;
    char letra;
    bool gano = false;
    string letrasUsadas = "";

    while (vidas > 0 && !gano) {
        cout << "= JUEGO DEL AHORCADO =" << endl;
        cout << "Vidas restantes: " << vidas << endl;
        cout << "Letras intentadas: " << letrasUsadas << endl << endl;

        cout << "Frase: ";
        for (size_t i = 0; i < progreso.length(); i++) {
            cout << progreso[i] << " ";
        }
        cout << endl << endl;

        cout << "Ingresa una letra: ";
        cin >> letra;

        letrasUsadas += letra;
        letrasUsadas += " ";

        bool acierto = false;

        for (size_t i = 0; i < fraseSecreta.length(); i++) {
            if (fraseSecreta[i] == letra) {
                progreso[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            vidas--;
            cout << "\nIncorrecto. Pierdes una vida." << endl;
        }
        else {
            cout << "\nBien hecho, letra encontrada." << endl;
        }

        if (progreso == fraseSecreta) {
            gano = true;
        }

        system("pause"); 
        system("cls");   
    }

    
    if (gano) {
        cout << "FELICIDADES. Has adivinado la frase: " << fraseSecreta << endl;
    }
    else {
        cout << " Te quedaste sin vidas." << endl;
        cout << "La frase secreta era: " << fraseSecreta << endl;
    }

    return 0;
}
