//UPT Programacion Estructurada Jose de Jesus Cenobio Lopez Arturo Negrete Medellin
//El codigo llena un arreglo de 56 elementos con numeros aleatorios entre 1 y 1,000,000

#include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    srand(static_cast<unsigned int>(time(NULL)));

    const int TAMANO = 56;
    int numeros[TAMANO];

    for (int i = 0; i < TAMANO; i++) {

        int aleatorioGrande = (rand() * 32768) + rand();
        numeros[i] = (aleatorioGrande % 1000000) + 1;
    }

    cout << "= 56 NUMEROS ALEATORIOS (DEL 1 AL 1,000,000) =" << endl << endl;

    for (int i = 0; i < TAMANO; i++) {
        cout << "Posicion [" << i + 1 << "]: " << numeros[i] << endl;
    }

    cout << endl;
    system("pause"); 

    return 0;
}
