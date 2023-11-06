#ifndef MINPRIORITYQUEUE_HPP
#define MINPRIORITYQUEUE_HPP

#include <iostream>

using namespace std;


/*Implementación de una Min Priority Queue, la cuál deberá soportar los 4 métodos: Insertar, Ver Mínimo, 
Extraer Mínimo y Reducir llave. Dicha cola deberá de ser implementada para los objetos dados durante su laboratorio. */


class TreeNode {
    private: 

    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    string symbol;
    double probability;
    
public:
    
    //Constructor
    TreeNode();
    TreeNode(string symbol, double probability);

    TreeNode *CreateNode(string symbol, double probability);

    //Funciones publicas para acceder a los valores de los nodos
    string getSymbol();
    void setSymbol(string newSymbol){symbol = newSymbol;}
    
    double getProbability();
    void setProbability(double newProbability){probability = newProbability;}

    void minHeapify(TreeNode **nodes, int size, int index);
    void buildMinHeap(TreeNode** nodes, int size);
    void minHeapInsert(TreeNode **nodes, int &size, TreeNode *newNode);
    TreeNode *MinHeapMinimum(TreeNode **nodes, int size);
};

TreeNode::TreeNode(){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    symbol = "";
    probability = 0.0;
    
}

TreeNode::TreeNode(string symbol, double probability){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    this->symbol = symbol[0];
    this->probability = probability;
}

TreeNode *TreeNode::CreateNode(string symbol, double probability){
    TreeNode* newNode = new TreeNode(symbol, probability);
    return newNode;
}

string TreeNode::getSymbol(){
    return symbol;
}

double TreeNode::getProbability(){
    return probability;
}

// Función para mantener el minHeap
void TreeNode::minHeapify(TreeNode** nodes, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && nodes[left]->probability < nodes[smallest]->probability)
        smallest = left;

    if (right < size && nodes[right]->probability < nodes[smallest]->probability)
        smallest = right;

    if (smallest != index) {
        swap(nodes[index], nodes[smallest]);
        minHeapify(nodes, size, smallest);
    }
}


// Función para construir el minHeap
void TreeNode::buildMinHeap(TreeNode** nodes, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(nodes, size, i);
}

// Función para insertar un nuevo nodo en el minHeap
void TreeNode::minHeapInsert(TreeNode** nodes, int& size, TreeNode* newNode) {
    size++;
    int i = size - 1;
    nodes[i] = newNode;

    while (i > 0 && nodes[(i - 1) / 2]->probability > nodes[i]->probability) {
        std::swap(nodes[i], nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Función para obtener el nodo mínimo del minHeap
TreeNode *TreeNode::MinHeapMinimum(TreeNode** nodes, int size) {
    if (size <= 0) {
        return nullptr; // Montículo vacío
    }
    return nodes[0];
}


#endif