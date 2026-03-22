#include <iostream>
#include <vector>
#include <random>
#include <iomanip> // Para controlar los decimales (precision)

using namespace std;

// Definimos M como 2^48 usando desplazamiento de bits (1 desplazado 48 veces)
const unsigned long long M = 1ULL << 48; 
const unsigned long long A = 0x5DEECE66DULL;
const unsigned long long C = 0xBULL;

int main() {
    int N_PUNTOS = 1000;
    unsigned long long actual = 10; // Semilla (r)

    // --- 1. Generar pares con LCA Grande (Parámetros Java) ---
    cout << "--- DATOS LCA GRANDE (48-bits) ---" << endl;
    cout << "x_lca,y_lca" << endl;
    
    for (int i = 0; i < N_PUNTOS; i++) {
        // Generamos x
        actual = (A * actual + C) % M;
        double x = (double)actual / M;
        
        // Generamos y
        actual = (A * actual + C) % M;
        double y = (double)actual / M;
        
        // Imprimimos con 6 decimales
        cout << fixed << setprecision(6) << x << "," << y << endl;
    }

    cout << "\n--- DATOS GENERADOR PC (Mersenne Twister) ---" << endl;
    cout << "x_pc,y_pc" << endl;

    // --- 2. Generar pares con el motor de la PC ---
    random_device rd; 
    mt19937 gen(rd()); // Motor Mersenne Twister
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < N_PUNTOS; i++) {
        double x_pc = dis(gen);
        double y_pc = dis(gen);
        cout << fixed << setprecision(6) << x_pc << "," << y_pc << endl;
    }

    return 0;
} 