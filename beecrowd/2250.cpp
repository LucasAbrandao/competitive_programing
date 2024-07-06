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


bool comparar(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first == b.first) 
        return a.second < b.second; 
    return a.first > b.first; 
}


void solve() {
    int n, turma = 0;
    while (cin >> n && n != 0) {
        turma++;
        cout << "Teste " << turma << endl;

        vector<pair<int,string>> jogadores(n);

        for (int i = 0; i < n; i++) {
            cin >> jogadores[i].second;
            int pontuacoes[12];
            for (int j = 0; j < 12; j++) {
                cin >> pontuacoes[j];
            }
            sort(pontuacoes, pontuacoes + 12);
            int pontuacao = 0;
            for (int j = 1; j < 11; j++) {
                pontuacao += pontuacoes[j];
            }
            jogadores[i].first = pontuacao;
        }

        sort(jogadores.begin(), jogadores.end(), comparar);

        int posicao = 1;
        int pontuacaoAnterior = -1;
        int posicaoAnterior = 0;
        for (int i = 0; i < n; i++) {
            if (jogadores[i].first != pontuacaoAnterior) {
                cout << posicao << " " << jogadores[i].first << " " << jogadores[i].second << endl;
                pontuacaoAnterior = jogadores[i].first;
                posicaoAnterior = posicao;
            } else {
                cout << posicaoAnterior << " " << jogadores[i].first << " " << jogadores[i].second << endl;
            }
            posicao++;
        }

        cout << endl;
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