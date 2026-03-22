#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// Parámetros de "Trabajo Serio"
const unsigned long long M = 1ULL << 48; 
const unsigned long long A = 0x5DEECE66DULL;
const unsigned long long C = 0xBULL;

int main() {
    int N_PUNTOS = 1000;
    unsigned long long actual = 10; // Semilla para tu LCA

    // Configurar el generador de la PC
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_real_distribution<double> dis(0.0, 1.0);

    // IMPRIMIR ENCABEZADO (Muy importante para Python)
    cout << "x_lca,y_lca,x_pc,y_pc" << endl;

    for (int i = 0; i < N_PUNTOS; i++) {
        // 1. Generar coordenadas para TU algoritmo (LCA)
        actual = (A * actual + C) % M;
        double x_lca = (double)actual / M;
        actual = (A * actual + C) % M;
        double y_lca = (double)actual / M;

        // 2. Generar coordenadas para el Generador de la PC
        double x_pc = dis(gen);
        double y_pc = dis(gen);

        // 3. Imprimir las 4 columnas en una sola línea
        cout << fixed << setprecision(6) 
             << x_lca << "," << y_lca << "," 
             << x_pc << "," << y_pc << endl;
    }

    return 0;
}
