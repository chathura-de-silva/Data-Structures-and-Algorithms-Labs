#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;
    list<int> neighbours; 
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n];

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1; 
        }
    }

    void addEdge(int u, int v) {
        nodes[u - 1].neighbours.push_back(v); 
        nodes[v - 1].neighbours.push_back(u); 
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << "Node " << nodes[i].label << " neighbours --> ";
            for (int neighbour : nodes[i].neighbours) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();
    g->addEdge(1, 2);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(1, 3);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);
    g->print();
    return 0;
}
