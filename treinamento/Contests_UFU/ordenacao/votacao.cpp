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

struct Marca {
    string nome;
    int pontuacao;
    int ordemOcorrencia;
};

bool comparaMarcas(const Marca& a, const Marca& b) {
    if (a.pontuacao == b.pontuacao) {
        return a.ordemOcorrencia < b.ordemOcorrencia;
    }
    return a.pontuacao > b.pontuacao;
}

void solve() {
    int N;
    cin >> N;

    vector<Marca> marcas;
    unordered_map<string, int> mapaPontuacao;
    int ordem = 1;

    for (int i = 0; i < N; i++) {
        string nomeMarca;
        cin >> nomeMarca;

        if (mapaPontuacao.count(nomeMarca) > 0) {
            mapaPontuacao[nomeMarca]++;
        } else {
            Marca novaMarca;
            novaMarca.nome = nomeMarca;
            novaMarca.pontuacao = 1;
            novaMarca.ordemOcorrencia = ordem++;

            marcas.push_back(novaMarca);
            mapaPontuacao[nomeMarca] = 1;
        }
    }

    sort(marcas.begin(), marcas.end(), comparaMarcas);

    for (int i = 0; i < marcas.size(); i++) {
        cout << marcas[i].nome << endl;
    }
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