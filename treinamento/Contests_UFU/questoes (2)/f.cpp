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


bool verInserir (int l,int c,int r1,int r2){

	//vertical
	if((r1+r2) <= l){
		if(r1 <= c && r2 <= c){
			return true;
		}
	}
	//comprimeto
	if((r1+r2) <= c){
		if(r1 <= l && r2 <= l){
			return true;
		}
	}
	//diagonal
	if((r1+r2) <= sqrt( (c*c) + (l*l) )){
		if(r1 <= c && r2 <= c && r1 <= l && r2 <= l){
			return true;
		}
	}
	return false;
}

void solve() {

    int l, c, r1, r2;
    while(cin >> l >> c >> r1 >> r2){

		if (l==0 && c==0 && r1==0 && r2==0) break;


		if(verInserir(l,c,r1,r2)){
			cout << "1" << endl;
		}else{
			cout << "0" << endl;
		}

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
