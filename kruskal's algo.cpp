#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[10];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    int V = 5;

    Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    int E = 7;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges, edges + E, compare);

    int total = 0;
    int count = 0;

    cout << "Edge\tWeight\n";

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v << "\t" << edges[i].weight << endl;
            total += edges[i].weight;
            unite(u, v);
            count++;
        }
    }

    cout << "Total weight = " << total << endl;

    return 0;
}
