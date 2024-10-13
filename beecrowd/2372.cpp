#include <bits/stdc++.h>
using namespace std;

int minD(const vector<vector<int>>& dist, int V) {

    int minDist = INT_MAX;
 
    for (int i = 0; i < V; ++i) {
        int max_dist = -1;
        for (int j = 0; j < V; ++j) {
            max_dist = max(dist[i][j], max_dist);
        }

        if(max_dist < minDist){
            minDist = max_dist;
        }
    }

    return minDist;
}

int floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(graph);

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                //   se o vértice k  é um caminho mais curto de i para j,  atualiza dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int m = minD(dist, V);
    return m;
}

int main(){

    int n, m; cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    while(m--){
        int a, b, w; cin >> a >> b >> w;
        if(graph[a][b] < INT_MAX){

            if(w < graph[a][b]){
                graph[a][b] = w;
                graph[b][a] = w;
            }else{
                continue;
            }

        }else{
            graph[a][b] = w;
            graph[b][a] = w;
        }
    }

    cout << floydWarshall(graph, n) << endl;









    return 0;
}