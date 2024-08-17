#include <bits/stdc++.h>
using namespace std;

vector<int> parent, ranking;

void make_set(int v) {
    parent[v] = v;
    ranking[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranking[a] < ranking[b])
            swap(a, b);
        parent[b] = a;
        if (ranking[a] == ranking[b])
            ranking[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

int main() {
    int n, m;

    while (cin >> n >> m) {
        vector<Edge> edges;

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >>a >> b >> c;
            a--; b--;
            Edge e; e.u = a; e.v = b; e.weight = c;

            edges.push_back(e);
        }

        parent.resize(n);
        ranking.resize(n);
        for (int i = 0; i < n; i++)
            make_set(i);

        sort(edges.begin(), edges.end());


        int cost = 0;
        vector<Edge> result;

        for (Edge e : edges) {
            if (find_set(e.u) != find_set(e.v)) {
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);
            }
        }


        if (result.size() != n - 1) {
            cout << "impossivel\n";
        } else {
            cout << cost << endl;
        }
    }

    return 0;
}
