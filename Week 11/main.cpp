#include <iostream>
#include <cstring>

using namespace std;
// defining the number of vertices globally
#define V 6
//Hardcoded adjacency matrix for the graph.Infinity is used to indicate no edge(infinite cost). So simply the Prims algorithms will avoid them.
int graph[V][V] = {
        {INT_MAX,       3, INT_MAX, INT_MAX, INT_MAX,       1},
        {      3, INT_MAX,       2,       1,      10, INT_MAX},
        {INT_MAX,       2, INT_MAX,       3, INT_MAX,       5},
        {INT_MAX,       1,       3, INT_MAX,       5, INT_MAX},
        {INT_MAX,      10, INT_MAX,       5, INT_MAX,       4},
        {      1, INT_MAX,       5, INT_MAX,       4, INT_MAX}};

int main() {
    int root=0;
    int totalCost=0;
    int no_edge=0;  // number of edges
    int selected[V]; // create an array to track selected vertex
    memset(selected, false, sizeof(selected)); // set selected to false initially
    cout<<"Enter the root node : ";
    cin>>root;

    if (0<=root and root<=V){
        selected[root] = true;

        int x,y;
        cout << "  Edge"
             << "  | "
             << "Cost";
        cout << endl;
        while (no_edge < V - 1) {
            int min = INT_MAX;
            x = 0;
            y = 0;
            for (int i = 0; i < V; i++) {
                if (selected[i]) {
                    for (int j = 0; j < V; j++) {
                        if (!selected[j] && graph[i][j]) {
                            if (min > graph[i][j]) {
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            cout << '(' << x << " - " << y << ')' << " :  " << graph[x][y]<<endl;
            totalCost+=graph[x][y];
            selected[y] = true;
            no_edge++;
        }
        cout << "Total cost of the MST : "<<totalCost;
    }
    else{
        cout<<endl;
        cout<<"Invalid Root";
    }
    return 0;
}