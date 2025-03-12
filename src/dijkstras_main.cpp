#include "dijkstras.h"

int main()
{
    Graph G;
    file_to_graph("../src/medium.txt", G);
    vector<int> prev;

    vector<int> distances = dijkstra_shortest_path(G, 0, prev);

    // Print all distances for debugging
    cout << "Distances from vertex 0:\n";
    for (int i = 0; i < G.numVertices; ++i) {
        if (distances[i] == INF)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << distances[i] << "\n";
    }

    // Extract and print path to vertex 3
    vector<int> shortPath = extract_shortest_path(distances, prev, 3);
    if (!shortPath.empty() && distances[3] != INF) {
        print_path(shortPath, distances[3]);
    } else {
        cout << "No path from 0 to 3 exists\n";
    }

    return 0;
}