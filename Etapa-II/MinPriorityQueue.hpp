#ifndef MINPRIORITYQUEUE_HPP
#define MINPRIORITYQUEUE_HPP

#include <iostream>

using namespace std;

/*Implementación de una Min Priority Queue, la cuál deberá soportar los 4 métodos: Insertar, Ver Mínimo,
Extraer Mínimo y Reducir llave. Dicha cola deberá de ser implementada para los objetos dados durante su laboratorio. */

class TreeNode
{
private:
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    string symbol;
    double probability;

public:
    TreeNode();
    ~TreeNode();
    TreeNode(string symbol, double probability);
    TreeNode *CreateNode(string symbol, double probability);
    string getSymbol();
    void setSymbol(string newSymbol) { symbol = newSymbol; }
    double getProbability();
    void setProbability(double newProbability) { probability = newProbability; }
    void minHeapify(TreeNode **nodes, int size, int index);
    void buildMinHeap(TreeNode **nodes, int size);
    void minHeapInsert(TreeNode **nodes, int &size, TreeNode *newNode);
    TreeNode *MinHeapMinimum(TreeNode **nodes, int size);
};

// Default constructor for TreeNode class
TreeNode::TreeNode()
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    symbol = ' ';
    probability = 0.0;
}

// Destructor for TreeNode class
TreeNode::~TreeNode()
{
    delete parent;
    delete left;
    delete right;
}

// Constructor with symbol and probability for TreeNode
TreeNode::TreeNode(string symbol, double probability)
{
    this->symbol = symbol;
    this->probability = probability;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

// Create a new TreeNode with symbol and probability
TreeNode *TreeNode::CreateNode(string symbol, double probability)
{
    TreeNode *newNode = new TreeNode(symbol, probability);
    return newNode;
}

// Get the symbol of the TreeNode
string TreeNode::getSymbol()
{
    return symbol;
}

// Get the probability of the TreeNode
double TreeNode::getProbability()
{
    return probability;
}

// Function to maintain the minHeap property
void TreeNode::minHeapify(TreeNode **nodes, int size, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && nodes[left]->probability < nodes[smallest]->probability)
        smallest = left;

    if (right < size && nodes[right]->probability < nodes[smallest]->probability)
        smallest = right;

    if (smallest != index)
    {
        swap(nodes[index], nodes[smallest]);
        minHeapify(nodes, size, smallest);
    }
}

// Function to build the minHeap
void TreeNode::buildMinHeap(TreeNode **nodes, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(nodes, size, i);
}

// Function to insert a new node into the minHeap
void TreeNode::minHeapInsert(TreeNode **nodes, int &size, TreeNode *newNode)
{
    size++;
    int i = size - 1;
    nodes[i] = newNode;

    while (i > 0 && nodes[(i - 1) / 2]->probability > nodes[i]->probability)
    {
        std::swap(nodes[i], nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to get the minimum node from the minHeap
TreeNode *TreeNode::MinHeapMinimum(TreeNode **nodes, int size)
{
    if (size <= 0)
        return nullptr; // Empty heap
    return nodes[0];
}

#endif