#include <iostream>
#include "MinPriorityQueue.hpp"

using namespace std;

int main()
{
    // Data for Fenice symbols and probabilities
    string symbols[] = {"\u10900", "\u10901", "\u10902", "\u10903", "\u10904",
                        "\u10905", "\u10906", "\u10907", "\u10908", "\u10909",
                        "\u1090A", "\u1090B", "\u1090C", "\u1090D", "\u1090E",
                        "\u1090F", "\u10910", "\u10911", "\u10912", "\u10913",
                        "\u10914", "\u10915"};
    double probabilities[] = {0.43, 0.27, 0.93, 0.90, 0.69, 0.89, 0.81, 0.53, 0.47, 0.00, 0.12, 0.49, 0.87, 0.96, 0.42, 0.08, 0.75, 0.63, 0.14, 0.50, 0.31, 0.63};

    const int size = sizeof(symbols) / sizeof(symbols[0]);

    // Create nodes using an array
    TreeNode *nodes[size];

    // Create nodes and add them to the array
    for (int i = 0; i < size; i++)
    {
        nodes[i] = new TreeNode(symbols[i], probabilities[i]);
    }

    // Access the created nodes
    for (int i = 0; i < size; i++)
    {
        cout << "Node " << i + 1 << ": Symbol - " << nodes[i]->getSymbol() << ", Probability - " << nodes[i]->getProbability() << endl;
    }

    // Clean up and delete the allocated nodes
    for (int i = 0; i < size; i++)
    {
        delete nodes[i];
    }

    return 0;
}