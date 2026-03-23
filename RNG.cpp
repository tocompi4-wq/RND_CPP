#include <iostream>
#include <vector>

using namespace std;

// Definimos la función. 
// "vector<int>" significa que la función devuelve una lista de enteros.
vector<int> lineal_congruente(int a, int c, int M, int r) {
    vector<int> r_list; // Creamos el vector vacío
    r_list.push_back(r); // Equivalente a .append() en Python
    
    for (int i = 0; i < (2 * M); i++) {
        r = (a * r + c) % M; // La fórmula es idéntica
        r_list.push_back(r);
    }
    
    return r_list;
}

int main() {
    // Parámetros
    int a = 1;
    int c = 3;
    int M = 10;
    int r = 10;

    // Llamamos a la función
    vector<int> resultado = lineal_congruente(a, c, M, r);

    // Imprimir la lista C++
    cout << "[ ";
    for (int num : resultado) {
        cout << num << " ";
    }
    cout << "]" << endl;

    return 0;
}
