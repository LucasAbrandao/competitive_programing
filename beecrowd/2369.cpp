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


int contaAgua (int n){

    int total=7; // preco da assin. basica  

    

    for(int i = 5; n>100; total+=i,n--){}

    for(int i = 2; n>30; total+=i,n--){}

    for(int i = 1; n>10; total+=i,n--){}

    
    return total;
    

}

void solve() {

    int N;
    cin >> N;


    cout << contaAgua(N) << endl;


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