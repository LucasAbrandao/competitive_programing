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

    while(true){

    int n, m; cin >> n >> m;
    if(n == 0 and m == 0){
        break;
    }

    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    vector<vector<int>> dist;
    while(m--){
        int a, b, c;

        cin >> a >> b >> c; 
        graph[a][b] = c;
        graph[b][a] = c;

    }

    dist = floydWarshall(graph);

    vector<int>centros(n+1);
    int menor = INF;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(i != j){
                sum += dist[i][j];
            }
        }

        menor = min(menor,sum);
        centros[i] = sum;

    }

    for(int i = 1; i <= n; i++){
        if(centros[i] == menor){
            cout << i << " ";
        }
    }cout << endl;

    
    }




    return 0;
}