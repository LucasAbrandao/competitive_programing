#include <bits/stdc++.h>
using namespace std;

#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi                          vector<int>
#define pii                 pair<int,int>
#define endl         "\n"
#define print_v(a)   for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a)  for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e)          for(int i=s;i<e;i++)
#define rf(i,e,s)          for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;
const int MAX = 112345;

vector<int> adj[MAX];
unordered_set<int> newGraph[MAX];
stack<int> stk;
int counter, vis[MAX], scc[MAX], inStack[MAX], cycle[MAX], topoSort[MAX];

void topologicalSort(int u, int &topoSortIndex) {
    vis[u] = 1;
    for(int v : newGraph[u]) {
        if(!vis[v]) topologicalSort(v, topoSortIndex);
    }
    topoSort[topoSortIndex++] = u;
}

void tarjan(int u, int& ord) {

    vis[u] = cycle[u] = ord++;
    stk.push(u);
    inStack[u] = 1;

        for(int &v : adj[u]) {
        if(!vis[v]) 
                        tarjan(v, ord);
        if(inStack[v]) 
                        cycle[u] = min(cycle[u], cycle[v]);
    }

        if(vis[u] == cycle[u]) {
        int w;
        do {
            w = stk.top();
            stk.pop();
            inStack[w] = 0;
            scc[w] = counter;
        } while(w != u);
        counter++;
    }
}

bool isSemiStronglyConnected(int n) {

        memset(vis, 0, (n + 1) * sizeof(vis[0]));
    memset(inStack, 0, (n + 1) * sizeof(inStack[0]));
    int ord = 1; counter = 0;

        f(i,0,n) {
        if(!vis[i]) 
                        tarjan(i, ord);
    }

        f(i,0,n) {
        for(auto &v : adj[i])
            if(scc[i] != scc[v]) 
                newGraph[scc[i]].insert(scc[v]);
    }

    memset(vis, 0, (counter + 1) * sizeof(vis[0]));

    int topoSortIndex = 0;
        f(i,0,counter) {
        if(!vis[i])
            topologicalSort(i, topoSortIndex);
    }

    for(int i = topoSortIndex - 1; i > 0; i--) {
        if(!newGraph[topoSort[i]].count(topoSort[i - 1])) 
                        return false;
    }

        return true;
}

int32_t main() { _

    int n, m; cin >> n >> m;

        f(i,0,m) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }

    cout << (!isSemiStronglyConnected(n) ? "Nao Bolada" : "Bolada") << "\n";

        return 0;
}