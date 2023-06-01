#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

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

// Function to perform Dijkstra's algorithm on a graph represented as an adjacency matrix
vector<double> modifiedDijkstra(const vector<vector<int>>& graph, int src)
{
    double averageTime=0; // Average time taken to go to another vertex from the source vertex exactly once.
    int V = graph.size();
    vector<int> dist(V, numeric_limits<int>::max()); // Stores the shortest distance from the source
    vector<bool> visited(V, false); // Tracks visited vertices
    vector<int> parent(V, -1); // Stores the parent of each vertex in the shortest path

    dist[src] = 0; // Distance from source to itself is 0 hence doesnt affect the average time and total Time

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
    averageTime = (double)(accumulate(dist.begin(), dist.end(), 0))/(V-1);
    return {(double)src,averageTime};//the average time to visit another vertex from the source.
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

    double bestTime = numeric_limits<double>::infinity();;//This will become the bestPossibleAverageTime.

    cout << "Source" << "\t" << "Average Time" << "\t\t"<<endl;
    vector<vector<double>>aveTimeVector(V);
    for (int src=0;src<6;src++){ // Iterating over all the vertices.
         aveTimeVector[src]= modifiedDijkstra(graph, src);
        cout << aveTimeVector[src][0] << "\t" << aveTimeVector[src][1] << "\t\t"<<endl;
        if (aveTimeVector[src][1]<=bestTime){
            bestTime = aveTimeVector[src][1];
        }
    }
    //Printing the best vertex
    cout<<"The best city to build the hospital is/are city number/numbers : ";
    for (const vector<double>&pair : aveTimeVector) {
        if (pair[1]==bestTime)
            cout<<pair[0]<<", ";
    }
    return 0;
}

//Below code calculates the required answer for question 4. Below functions are called inside dijkstra() function.


