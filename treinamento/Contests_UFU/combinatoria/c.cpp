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



int permutacaoComRepeticao(string s) {
    int vogal = 0, consoante = 0, result=1;
    for(char c : s) {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vogal++;
        else
            consoante++;
    }


	for (  int i=0; (vogal>0) && (consoante>0) ;i++){
		
		if(i%2==0 && consoante>0){
			result *= consoante;
			consoante--;
		}else{
			if(vogal>0){
				result *= vogal;
				vogal--;
			}
			
		
		}
	}
	
	return result/2;
}


void solve() {

	string nhe;
	getline(cin, nhe);
	cout << nhe << endl;
	nhe.erase(remove(nhe.begin(), nhe.end(), ' '), nhe.end());
	cout << nhe << endl;


	cout << permutacaoComRepeticao(nhe) << endl;
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