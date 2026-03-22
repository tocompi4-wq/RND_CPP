#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Función 1: Generar la lista
vector<int> lineal_congruente(int a, int c, int M, int r) {
    vector<int> r_list;
    r_list.push_back(r);
    for (int i = 0; i < (2 * M); i++) {
        r = (a * r + c) % M;
        r_list.push_back(r);
    }
    return r_list;
}

// Función 2: Detectar el periodo
struct ResultadoPeriodo {
    int inicio;
    int longitud;
    int numero;
};

ResultadoPeriodo detectar_periodo(int a, int c, int M, int semilla) {
    //unordered_map<llave, valor>
    unordered_map<int, int> vistos; 
    int r = semilla;
    int posicion = 0;

    // .find() busca la llave. Si llega al final (.end()), es que no está.
    while (vistos.find(r) == vistos.end()) {
        vistos[r] = posicion; // Guardar número y posición
        r = (a * r + c) % M;
        posicion++;
    }

    int inicio_rep = vistos[r];
    int longitud_per = posicion - inicio_rep;

    return {inicio_rep, longitud_per, r};
}

int main() {
    // Parámetros
    int a2 = 57, c2 = 1, M2 = 256, r2 = 10;

    // 1. Probar generación simple
    vector<int> lista = lineal_congruente(a2, c2, M2, r2);
    cout << "Primeros 10 numeros: ";
    for(int i=0; i<10; i++) cout << lista[i] << " ";
    cout << "..." << endl;

    // 2. Detectar periodo
    ResultadoPeriodo res = detectar_periodo(a2, c2, M2, r2);

    cout << "------------------------------------" << endl;
    cout << "Se repitio el numero " << res.numero 
         << " que aparecio primero en la posicion " << res.inicio << "." << endl;
    cout << "La longitud del periodo es de " << res.longitud << " numeros." << endl;

    return 0;
}