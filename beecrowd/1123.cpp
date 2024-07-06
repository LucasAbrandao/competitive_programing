#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define int long long
#define double long double
#define vi vector<int>
#define pii pair<int,int>
#define endl "\n"
#define print_v(a) for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a) for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e) for(int i=s;i<e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define CEIL(a, b) ((a) + (b - 1))/b
#define TRUNC(x, n) floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n) round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e18;
const int MAX = 250;

int n; 
vector<vector<pair<int, int>>> adj;
vector<int> dist, parent;
vector<bool> vis;

void dijkstra(int s) {
    dist.assign(n, INF);
    vis.assign(n, false);
    parent.assign(n, -1);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});

    while (!q.empty()) {
        int a = q.top().second; q.pop();

        if (vis[a]) continue;
        vis[a] = true;

        for (auto [b, w] : adj[a]) {
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                q.push({dist[b], b});
            }
        }
    }
}

vector<int> restorePath(int v) {
    vector<int> path;
    for (int u = v; u != -1; u = parent[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    int N, M, C, K;
    cin >> N >> M >> C >> K;

    if (N == 0 && M == 0 && C == 0 && K == 0)
        return;

    n = N;
    adj.clear();
    adj.resize(n);

    for (int i = 0; i < M; ++i) {
        int U, V, P;
        cin >> U >> V >> P;
        adj[U].push_back({V, P});
        adj[V].push_back({U, P});
    }

    dijkstra(K);

    vector<int> path_to_dest = restorePath(C - 1);
    int min_cost = dist[C - 1];

    for (int i = 1; i < path_to_dest.size() - 1; ++i) {
        int city_in_route = path_to_dest[i];
        if (city_in_route < C - 1) {
            vector<int> part1 = restorePath(city_in_route);
            vector<int> part2 = restorePath(C - 1);

            int cost_part1 = 0;
            for (int j = 0; j < part1.size() - 1; ++j) {
                int u = part1[j], v = part1[j + 1];
                for (auto [neighbor, cost] : adj[u]) {
                    if (neighbor == v)
                        cost_part1 += cost;
                }
            }
            int cost_part2 = dist[C - 1] - dist[city_in_route];

            min_cost = min(min_cost, cost_part1 + cost_part2);
        }
    }

    cout << min_cost << endl;
}

int32_t main() { _
    
    clock_t z = clock();
    int t = 1;
    while (t--) {
        solve();
    }
    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
