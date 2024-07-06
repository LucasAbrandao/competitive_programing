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
    int qntMed, intervalo, turma = 0;
    while (cin >> qntMed >> intervalo && qntMed != 0 && intervalo != 0) {
        turma++;
        cout << "Teste " << turma << endl;


			vi temp,medias;

			for(int i=0;i<qntMed;i++){
				int aux;
				cin >> aux;
				temp.push_back(aux);
			}

			/*
				1 2 3 4 5 6 7     size = 7  foi ate pos 3  7- intervalo+1
				1 2 3 4
				  2 3 4 5
				    3 4 5 6
					  4 5 6 7
			
			*/
			for(int i=0;i<=temp.size()-intervalo;i++){

				int media=0;
				for(int j=i;j<intervalo+i;j++){
					media += temp[j];
				}
				medias.push_back(media/intervalo);
				
			}
	
			sort(medias.begin(), medias.end());

			cout << medias[0] << " " << medias[medias.size()-1] ;


        cout << endl << endl;
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
