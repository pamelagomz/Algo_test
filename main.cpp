#include <iostream>
#include "MinPriorityQueue.hpp"

using namespace std;



int main(){

    //Creación de los nodos
    
    // Datos de símbolos y probabilidades
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'};
    double probabilities[] = {0.43, 0.27, 0.93, 0.90, 0.69, 0.89, 0.81, 0.53, 0.47, 0.00, 0.12, 0.49, 0.87, 0.96, 0.42, 0.08, 0.75, 0.63, 0.14, 0.50, 0.31, 0.63};

    const int size = sizeof(symbols) / sizeof(symbols[0]);
    TreeNode* nodes[size];

    // Crear nodos usando un bucle
    for (int i = 0; i < size; i++) {
        nodes[i] = new TreeNode(symbols[i], probabilities[i]);
    }

    // Acceder a los nodos creados
    for (int i = 0; i < size; i++) {
        cout << "Nodo " << i + 1 << ": Símbolo - " << nodes[i]->getSymbol() << ", Probabilidad - " << nodes[i]->getProbability() << endl;
    }

    
    return 0;
}