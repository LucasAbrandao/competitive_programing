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


void solve() {
    int N, K;
    
    while(true) {
        cin >> N >> K;

        if (N == 0 && K == 0) {
            return; 
        }
        
        vector<pair<int, int>> cars(N);
        for (int i = 0; i < N; ++i) {
            cin >> cars[i].first >> cars[i].second;
        }
        
        vector<int> estacionamento;
        
        bool possible = true;
        for (int i = 0; i < N; ++i) {
            int Ci = cars[i].first;
            int Si = cars[i].second;
            
            while (!estacionamento.empty() && estacionamento[0] <= Ci) {
                estacionamento.erase(estacionamento.begin());
            }
            
            if (estacionamento.size() >= K) {
                possible = false;
                break;
            }
            
            if (!estacionamento.empty() && estacionamento[0] < Si) {
                possible = false;
                break;
            }
            
            estacionamento.push_back(Si);
            
            sort(estacionamento.begin(), estacionamento.end());
        }
        
        if (possible) {
            cout << "Sim" << endl;
        } else {
            cout << "Nao" << endl;
        }
    }

}

int32_t main() { _
	
	clock_t z = clock();
	int t = 1; // cin >> t;
	while (t--) {
		solve();

	}
	//cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
