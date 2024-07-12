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


int contarZerosADireita(int n, int p) {
    int contagem = 0;
    while (n > 0) {
        n /= p;
        contagem += n;
    }
    return contagem;
}

vector<pair<int, int>> fatoracaoPrimos(int b) {
    vector<pair<int, int>> fatores;
    for (int i = 2; i * i <= b; i++) {
        int contagem = 0;
        while (b % i == 0) {
            contagem++;
            b /= i;
        }
        if (contagem > 0) {
            fatores.push_back({i, contagem});
        }
    }
    if (b > 1) {
        fatores.push_back({b, 1});
    }
    return fatores;
}

int calcularNumeroDigitos(int n, int b) {
    if (n == 0) return 1; 
    double logFatorial = 0;
    for (int i = 1; i <= n; i++) {
        logFatorial += log10(i) / log10(b);
    }
    return floor(logFatorial) + 1;
}

void solve() {
    int n, b;
    while (cin >> n >> b) {
        vector<pair<int, int>> fatores = fatoracaoPrimos(b);

        int minZeros = INT_MAX;
        for (auto& fator : fatores) {
            int p = fator.first;
            int a = fator.second;
            int zeros = contarZerosADireita(n, p) / a;
            minZeros = min(minZeros, zeros);
        }

        int numDigitos = calcularNumeroDigitos(n, b);

        cout << minZeros << " " << numDigitos << endl;
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
