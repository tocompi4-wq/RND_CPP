#include <iostream>
#include <vector>
#include <random>   
#include <ctime>    

using namespace std;

int main() {
    int N_PARES = 500;
    float RANGO = 500.0;

    // Configurar el motor de números aleatorios
    mt19937 generador(time(0)); 

    // Definir la distribución
    uniform_real_distribution<float> distribucion(0.0, 1.0);

    vector<float> x_pc, y_pc;

    // Generar los puntos
    for (int i = 0; i < N_PARES; i++) {
        x_pc.push_back(distribucion(generador) * RANGO);
        y_pc.push_back(distribucion(generador) * RANGO);
    }

    // Mostrar TODOS los pares
    // Usamos x_pc.size() para asegurarnos de recorrer todo el vector
    cout << "X,Y" << endl; // Cambié el \t por coma por si quieres guardarlo como CSV
    for (int i = 0; i < x_pc.size(); i++) {
        cout << x_pc[i] << "," << y_pc[i] << endl;
    }

    return 0;
}
