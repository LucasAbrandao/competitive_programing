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



void solve() {

	int rep;
	cin >> rep;

	int result=0;

	for(int u=0; u<rep; u++){
		
		int duracao,tamanho =10,qntBolhas=0, acrescDebolha=4;
		cin >> duracao;

		for(int i=0; i<duracao; i++){

			qntBolhas += acrescDebolha;

			if(acrescDebolha > 1){
				acrescDebolha--;
			}
			if(tamanho > 1){
				tamanho--;	
			}
			
			if(tamanho == 1){
				result++;
			}
			
		}
		

	}
	cout << result << endl;
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