#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void dijkstra(const vector<vector<int> >& graph, int start, vector<int>& distances) {
    int numNodes = graph.size();
    distances.resize(numNodes, numeric_limits<int>::max());
    vector<bool> visited(numNodes, false);

    distances[start] = 0;

    for (int count = 0; count < numNodes - 1; ++count) {
        int minDist = numeric_limits<int>::max();
        int minIndex = -1;

        // Find the node with the minimum distance
        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i] && distances[i] <= minDist) {
                minDist = distances[i];
                minIndex = i;
            }
        }

        // Mark the selected node as visited
        visited[minIndex] = true;

        // Update distances of the neighboring nodes
        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i] && graph[minIndex][i] != 0 &&
                distances[minIndex] != numeric_limits<int>::max() &&
                distances[minIndex] + graph[minIndex][i] < distances[i]) {
                distances[i] = distances[minIndex] + graph[minIndex][i];
            }
        }
    }
}

int main() {
    int numNodes = 6;
    vector<vector<int> > graph(numNodes, vector<int>(numNodes, 0));

    // Adding edges to the graph (adjacency matrix)
    graph[0][1] = 10;
    graph[0][4] = 15;
    graph[0][5] = 5;
    graph[1][0] = 10;
    graph[1][2] = 10;
    graph[1][3] = 30;
    graph[2][1] = 10;
    graph[2][3] = 12;
    graph[2][4] = 5;
    graph[3][1] = 30;
    graph[3][2] = 12;
    graph[3][5] = 20;
    graph[4][0] = 15;
    graph[4][2] = 5;
    graph[5][0] = 5;
    graph[5][3] = 20;


    
    
    
    // Printing the shortest distances from the start node
    for ( int startNode = 0 ; startNode < 6; startNode++){
        vector<int> distances;
        dijkstra(graph, startNode, distances);
        float total = 0;
        cout << "Shortest distances from node " << startNode << " to," << endl;
        for (int i = 0; i < numNodes; ++i) {
            cout << "node " << i << ": " << distances[i] << endl;
            total = total + distances[i];
    }
    //getting the avarage time
    cout << "Average time :" << total/5 << endl;
    cout << endl;
    }
     
    return 0;
}

