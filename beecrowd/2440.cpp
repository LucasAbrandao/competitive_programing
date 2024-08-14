#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii	         pair<int,int>
#define endl         "\n"
#define print_v(a)   for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a)  for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e9;    // 2^31-1
const int LLINF = 4e18; // 2^63-1
const double EPS = 1e-9;
const int MAX = 1e6+10; // 10^6 + 10



// Union-Find (Disjoint Set Union) implementation
class UnionFind {
private:
    vector<int> parent, rank;
    int num_components;
    
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        num_components = n;
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);  
        }
        return parent[u];
    }
    
    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            num_components--;  
        }
    }
    
    int getNumComponents() {
        return num_components;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    
    UnionFind uf(N);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }
    
    cout << uf.getNumComponents() << endl;
}

int32_t main() { _
	
	clock_t z = clock();
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
