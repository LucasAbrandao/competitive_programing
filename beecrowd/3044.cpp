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


int a, b;



int V;
vector<vi> adj;
vi ans;

void dfs(vector<bool>& vis, int i, int curr) {
	vis[curr] = 1;
	for (auto x : adj[curr]) {
		if (x != i) {
			if (!vis[x]) {
				dfs(vis, i, x);
			}
		}
	}
}

void AP() {

    f(i,1,V+1) {
		int components = 0;
		vector<bool> vis(V + 1, 0);
        f(j,1, V+1) {
			if (j != i) {
				if (!vis[j]) {
					components++;
					dfs(vis, i, j);
				}
			}
		}
		if (components > 1) {
			ans.push_back(i);
		}
	}
}



void solve() {
    int qntComp, qntConec, teste = 0;
    while (cin >> qntComp >> qntConec) {
        if(qntComp == 0 and qntConec == 0) break;
        teste++;
        cout << "Teste " << teste << endl;



        V = qntComp; 
        adj.clear(), ans.clear(); 
        adj.resize(V+1);
        
        while(qntConec--) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        AP();

        // Vertices articulacao: ans

        if (ans.size() != 0){

            for(int i=0;i<ans.size();i++){
                cout << ans[i] << ' ';
            }
        }else{
            cout << "nenhum";
        }
        




        cout << endl << endl;
    }
}

int32_t main() { _
    
    clock_t z = clock();

    int t = 1; // cin >> t;
    while (t--) 
        solve();

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
