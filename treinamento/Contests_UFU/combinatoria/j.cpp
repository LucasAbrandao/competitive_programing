#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

int a, b;
int factdp[20]; 

int fact(int n) {
    if (n < 2) return 1;
    if (factdp[n] != 0) return factdp[n];
    return factdp[n] = n * fact(n - 1);
}
int combinacaoSimples(int p, int n) {
    return fact(n) / (fact(p) * fact(n - p));
}

void solve() {
    int X;
    cin >> X;


    double contingente_sem_dispensa_medica = X - X * 0.37;


    double contingente_sem_dispensa_vagas = contingente_sem_dispensa_medica - contingente_sem_dispensa_medica * 0.20;

    //  ta com BO aq pra ultima impressao
    double formas_organizar_vagas = 0, cabos= X*0.30, sargentos= X*0.05;
    int qnt = floor(cabos) + floor(sargentos);
	cout << qnt << endl;

    cout << floor(contingente_sem_dispensa_medica) << " " << floor(contingente_sem_dispensa_vagas) << " " << combinacaoSimples(8,qnt) << endl;
}



int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}