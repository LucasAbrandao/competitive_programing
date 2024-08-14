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

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, adj, visited, finishStack);
        }
    }
    finishStack.push(v);
}

void dfs2(int v, vector<vector<int>>& adjT, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adjT[v]) {
        if (!visited[u]) {
            dfs2(u, adjT, visited);
        }
    }
}

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> adj(N + 1);
    vector<vector<int>> adjT(N + 1);

    f(i, 0, N) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adjT[B].push_back(A);
    }

    stack<int> finishStack;
    vector<bool> visited(N + 1, false);

    f(i, 1, N + 1) {
        if (!visited[i]) {
            dfs1(i, adj, visited, finishStack);
        }
    }

    fill(all(visited), false);
    int numComponents = 0;

    while (!finishStack.empty()) {
        int v = finishStack.top();
        finishStack.pop();

        if (!visited[v]) {
            dfs2(v, adjT, visited);
            ++numComponents;
        }
    }

    if (numComponents == 1) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }
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
