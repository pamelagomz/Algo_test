#include <iostream>
#include "MinPriorityQueue.hpp"

using namespace std;

int main() {
    // Data for Fenice symbols and probabilities
    string symbols[] = {"𝚱", "𝚲", "𝚳", "𝚴", "𝚵", "𝚶", "𝚷", "𝚸", "𝚹", "𝚺", "𝚻", "𝚼", "𝚽", "𝚾", "𝚿", "𝛀", "𝛁", "𝛂", "𝛃", "𝛄", "𝛅", "𝛆"};
    double probabilities[] = {0.43, 0.27, 0.93, 0.90, 0.69, 0.89, 0.81, 0.53, 0.47, 0.00, 0.12, 0.49, 0.87, 0.96, 0.42, 0.08, 0.75, 0.63, 0.14, 0.50, 0.31, 0.63};

    const int size = sizeof(symbols) / sizeof(symbols[0]);

    // Create nodes using an array
    TreeNode* nodes[size];

    // Create nodes and add them to the array
    for (int i = 0; i < size; i++) {
        nodes[i] = new TreeNode(symbols[i], probabilities[i]);
    }

    // Access the created nodes
    for (int i = 0; i < size; i++) {
        cout << "Node " << i + 1 << ": Symbol - " << nodes[i]->getSymbol() << ", Probability - " << nodes[i]->getProbability() << endl;
    }

    // Clean up and delete the allocated nodes
    for (int i = 0; i < size; i++) {
        delete nodes[i];
    }

    return 0;
}