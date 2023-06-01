#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to find the vertex with the minimum time value
int minTime(const vector<int>& dist, const vector<bool>& visited, int V)
{
    int minDist = numeric_limits<int>::max();
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the shortest path from source to destination
void printPath(const vector<int>& parent, int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << j << " ";
}

// Function to print the distances and paths
void printSolution(const vector<int>& dist, const vector<int>& parent, int src, int V)
{
    cout << "Vertex\tShortest Time\tPath\n";
    for (int i = 0; i < V; ++i) {
        if (i != src) { // Avoiding printing the parmaters for the source vertex.
            if (dist[i] == numeric_limits<int>::max()) {
                cout << i << "\tInfinity\t";
            } else {
                cout << i << "\t" << dist[i] << "\t\t";
            }


            printPath(parent, i);
            cout << src << endl;
        }
    }
}

// Function to perform Dijkstra's algorithm on a graph represented as an adjacency matrix
void dijkstra(const vector<vector<int>>& graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, numeric_limits<int>::max()); // Stores the shortest distance from the source
    vector<bool> visited(V, false); // Tracks visited vertices
    vector<int> parent(V, -1); // Stores the parent of each vertex in the shortest path

    dist[src] = 0; // Distance from source to itself is 0

    for (int count = 0; count < V - 1; ++count) {
        int u = minTime(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src, V);
}

int main()
{
    int V; // Number of vertices
    V=6; //Since there are 6 cities

    vector<vector<int>> graph(V, vector<int>(V));
    graph = {{0,10,0,0,15,5},
             {10,0,10,30,0,0},
             {0,10,0,12,5,0},
             {0,30,12,0,0,20},
             {15,0,5,0,0,0},
             {5,0,0,20,0,0}};

    int src; // Source vertex
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, src);

    return 0;
}
