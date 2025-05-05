/*
            To implement the following three algorithms using a menu driven program
                                1.Prim's Algorithm
                                2.Kruskal's Algorithm
                                3.Dijikstra's Algorithm
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

#define INF INT_MAX
#define MAX_DIST 1000000  // Define a large number instead of INF

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w);
};

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;
    vector<Edge> edges;

public:
    Graph(int vertices);
    void addEdge(int u, int v, int w);
    void display();
    void prims();
    int findParent(int u, vector<int> &parent);
    void kruskal();
    void dijkstra(int src);
};

int main() {
    int V, choice;
    cin >> V;

    Graph g(V);
    while (true) {
        cout << "\nMenu:\n"
             << "1. Add Edge\n"
             << "2. Display Graph\n"
             << "3. Prim’s Algorithm\n"
             << "4. Kruskal’s Algorithm\n"
             << "5. Dijkstra’s Algorithm\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.display();
        } else if (choice == 3) {
            g.prims();
        } else if (choice == 4) {
            g.kruskal();
        } else if (choice == 5) {
            int src;
            cin >> src;
            g.dijkstra(src);
        } else if (choice == 6) {
            break;
        }
    }

    return 0;
}

Edge::Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}

Graph::Graph(int vertices) {
    V = vertices;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adjList[u].emplace_back(v, w);
    adjList[v].emplace_back(u, w);
    edges.emplace_back(u, v, w);
}

void Graph::display() {
    for (int i = 0; i < V; ++i) {
        cout << i << " -> ";
        for (auto& pair : adjList[i]) {  // Iterate over the adjacency list
            int v = pair.first;   // Destination vertex
            int w = pair.second;  // Edge weight
            cout << "(" << v << ", " << w << ") ";
        }
        cout << "\n";
    }
}

void Graph::prims() {
    vector<int> key(V, MAX_DIST), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        // Find the vertex with the minimum key value that is not yet included in MST
        for (int i = 0; i < V; ++i)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        if (u == -1) {
            cout << "The graph is disconnected!" << endl;
            return;
        }

        inMST[u] = true;

        for (auto& pair : adjList[u]) {
            int v = pair.first;   // Destination vertex
            int w = pair.second;  // Edge weight
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree (Prim's):\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
}

int Graph::findParent(int u, vector<int> &parent) {
    if (parent[u] != u)
        parent[u] = findParent(parent[u], parent);
    return parent[u];
}

void Graph::kruskal() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    cout << "Minimum Spanning Tree (Kruskal's):\n";
    for (Edge &e : edges) {
        int pu = findParent(e.src, parent);
        int pv = findParent(e.dest, parent);
        if (pu != pv) {
            cout << e.src << " - " << e.dest << " (Weight: " << e.weight << ")\n";
            parent[pu] = pv;
        }
    }
}

void Graph::dijkstra(int src) {
    vector<int> dist(V, MAX_DIST);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& pair : adjList[u]) {
            int v = pair.first;
            int w = pair.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << "Shortest paths from source " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == MAX_DIST)
            cout << "No path to " << i << "\n";
        else
            cout << "Distance to " << i << " = " << dist[i] << "\n";
    }
}
