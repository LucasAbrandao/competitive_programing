#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

int a, b;

int n; // n = numero de vertices
vector<bool> vis;
vector<int> d, p;
vector<vector<int>> adj; // liqa de adjacencia

void bfs(int s) {

    vis.resize(n + 1, false);
    d.resize(n + 1, -1);
    p.resize(n + 1, -1);


    adj.resize(n + 1);

    queue<int> q; 
    q.push(s);
    vis[s] = true, d[s] = 0, p[s] = -1;

    while (!q.empty()) {
        int v = q.front(); 
        q.pop(); 
        vis[v] = true;
        
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}


void solve() {
    int qntCidade, qntEstrada, cidadeInit, qntMaxPedagio,teste = 0;
    while (cin >> qntCidade >> qntEstrada >> cidadeInit >> qntMaxPedagio 
    && qntCidade != 0 && qntEstrada != 0 && cidadeInit != 0 &&qntMaxPedagio!= 0) {

        teste++;
        cout << "Teste " << teste << endl;


        adj.assign(qntCidade + 1, vector<int>());
        vis.assign(qntCidade + 1, false);
        d.assign(qntCidade + 1, -1);
        p.assign(qntCidade + 1, -1);

        for (int i=0; i<qntEstrada; i++) {
            
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x); 
        }

        n=qntCidade;

        bfs(cidadeInit);
        
        for (int i=1; i<=qntCidade; i++) {

            if (i!=cidadeInit && d[i]<=qntMaxPedagio && d[i] != -1) {
                cout << i << " ";
            }
        }

        cout << endl << endl; 
    }
}



int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}