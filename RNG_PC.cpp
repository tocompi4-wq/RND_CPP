#include <iostream>
#include <vector>
#include <random>   // Librería para números aleatorios modernos
#include <ctime>    // Para usar el tiempo actual como semilla

using namespace std;

int main() {
    int N_PARES = 500;
    float RANGO = 500.0;

    // 1. Configurar el motor de números aleatorios
    // mt19937 es el algoritmo Mersenne Twister (el estándar de la industria)
    // time(0) hace que los números cambien cada vez que corres el programa
    mt19937 generador(time(0)); 

    // 2. Definir la distribución (queremos números decimales entre 0 y 1)
    uniform_real_distribution<float> distribucion(0.0, 1.0);

    vector<float> x_pc, y_pc;

    // 3. Generar los puntos
    for (int i = 0; i < N_PARES; i++) {
        // distribucion(generador) nos da el equivalente a random.random()
        x_pc.push_back(distribucion(generador) * RANGO);
        y_pc.push_back(distribucion(generador) * RANGO);
    }

    // 4. Mostrar los primeros pares (para verificar)
    cout << "X\tY" << endl;
    for (int i = 0; i < 10; i++) {
        cout << x_pc[i] << "\t" << y_pc[i] << endl;
    }
    cout << "... (mostrando solo 10 de " << N_PARES << " pares)" << endl;

    return 0;
}