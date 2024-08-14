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

const int MAX = 300;
vector<int> adj[MAX];
bool visited[MAX];
map<string, int> nameToNode;
int nodeCount = 0;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

void solve() {
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string name1, relation, name2;
        cin >> name1 >> relation >> name2;

        if (nameToNode.find(name1) == nameToNode.end()) {
            nameToNode[name1] = nodeCount++;
        }
        if (nameToNode.find(name2) == nameToNode.end()) {
            nameToNode[name2] = nodeCount++;
        }

        int u = nameToNode[name1];
        int v = nameToNode[name2];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int familyCount = 0;

    for (int i = 0; i < nodeCount; i++) {
        if (!visited[i]) {
            familyCount++;
            dfs(i);
        }
    }

    cout << familyCount << endl;
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
