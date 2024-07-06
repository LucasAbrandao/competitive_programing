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




void solve(int n, int t) {
    int qntPessoasTotais = 0;
    double qntConsumoTotal = 0;
    map<int, int> m; // consumo -- qntpessoa

    f(i, 0, n) {
        int x, y; cin >> x >> y;
        qntPessoasTotais += x;
        qntConsumoTotal += y;
        m[y / x] += x;
    }

    cout << "Cidade# " << t << ":" << endl;

    int i = 0;
    for (auto it = m.begin(); it != m.end(); ++it, ++i) {
        cout << it->second << "-" << it->first;
        if (i != m.size() - 1) cout << " ";
    }

    cout << endl;
    cout << "Consumo medio: " << fixed << setprecision(2) << TRUNC(qntConsumoTotal / qntPessoasTotais, 2) << " m3." << endl;
}

int32_t main() {
    _

    clock_t z = clock();
    int t = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        if (t > 1) cout << endl; 
        solve(n, t);
        t++;
    }
    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}