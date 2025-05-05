#include<iostream>
using namespace std;

#define ROW 10
#define COL 10
#define infi 9999

class prims {
    int graph[ROW][COL], nodes;
public:
    void createGraph();
    void primsAlgo();
};

void prims::createGraph() {
    cout << "Enter Total Offices: ";
    cin >> nodes;
    cout << "\nEnter Adjacency Matrix: \n";
    
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << "Enter distance between " << i << " and " << j << ": ";
            cin >> graph[i][j];

            if (i != j && graph[i][j] == 0)
                graph[i][j] = infi;  // Set infinity for no path
        }
    }
}

void prims::primsAlgo() {
    int selected[ROW] = {0};  // Initially, no node is selected
    int ne = 0, cost = 0;

    selected[0] = 1;  // Start with node 0

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (ne < nodes - 1) {
        int min = infi, x = -1, y = -1;

        for (int i = 0; i < nodes; i++) {
            if (selected[i]) {  // If node is already selected
                for (int j = 0; j < nodes; j++) {
                    if (!selected[j] && graph[i][j] < min) {  // Find minimum weight edge
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {  // Ensure a valid edge is found
            selected[y] = 1;
            cout << x << " --> " << y << "  (Cost: " << graph[x][y] << ")\n";
            cost += graph[x][y];
            ne++;
        }
    }

    cout << "\nTotal cost is: " << cost << endl;
}

int main() {
    prims MST;
    cout << "\nPrims Algorithm to connect several offices\n";
    MST.createGraph();
    MST.primsAlgo();
    return 0;
}
