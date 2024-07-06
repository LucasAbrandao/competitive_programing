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


struct Time {
    int id; 
    int pontos; 
    int pontosMarcados; 
    int pontosRecebidos; 

    Time(int id) : id(id), pontos(0), pontosMarcados(0), pontosRecebidos(0) {}

    double cestaAverage() const {
        if (pontosRecebidos == 0) {
            return pontosMarcados;
        } else {
            return static_cast<double>(pontosMarcados) / pontosRecebidos;
        }
    }

    bool operator<(const Time &outro) const {
        if (pontos != outro.pontos) return pontos > outro.pontos;
        if (cestaAverage() != outro.cestaAverage()) return cestaAverage() > outro.cestaAverage();
        if (pontosMarcados != outro.pontosMarcados) return pontosMarcados > outro.pontosMarcados;
        return id < outro.id;
    }
};

void solve() {
    int inst = 0;

    int cont = 0;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        if(cont == 0){
            cont++;
        }else{
            cout << endl;
        }

        inst++;
        vector<Time> times;
        for (int i = 1; i <= n; ++i) {
            times.emplace_back(i);
        }

        int totalJogos = n * (n - 1) / 2;
        for (int i = 0; i < totalJogos; ++i) {
            int x, y, z, w;
            cin >> x >> y >> z >> w;

            times[x - 1].pontosMarcados += y;
            times[x - 1].pontosRecebidos += w;
            times[z - 1].pontosMarcados += w;
            times[z - 1].pontosRecebidos += y;

            if (y > w) {
                times[x - 1].pontos += 2;
                times[z - 1].pontos += 1;
            } else {
                times[x - 1].pontos += 1;
                times[z - 1].pontos += 2;
            }
        }

        sort(all(times));

        cout << "Instancia " << inst << endl;
        for (int i = 0; i < times.size(); ++i) {
            cout << times[i].id;
            if (i != times.size() - 1) cout << " ";
        }

        cout << endl;
    }
}


int32_t main() { _
	
	clock_t z = clock();
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}