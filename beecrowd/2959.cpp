#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main(){

    int n, m, p; cin >> n >> m >> p;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    vector<vector<int>> dist;
    while(m--){
        int a, b;

        cin >> a >> b; 
        graph[a][b] = 1;
        graph[b][a] = 1;

    }

    dist = floydWarshall(graph);

    while(p--){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] < INF){
            cout << "Lets que lets\n";
        }else{
            cout << "Deu ruim\n";
        }
    }





    return 0;
}