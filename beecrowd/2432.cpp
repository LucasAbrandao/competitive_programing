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

const int MAXN=100010;
const int MAXM=100010;
int circulos,tiros;
int raio[MAXN];

int buscabinaria(int val){
    int ini=1;
    int fim=circulos;
    if(val>raio[circulos])
        return 0;

    while(ini<fim){
        int meio=(ini+fim)/2;
        if(raio[meio]>=val){
            fim=meio;
        }
        else{
            ini=meio+1;
        }
    }

    return circulos+1-fim;
}



void solve() {
    int x,y;
    cin>>circulos>>tiros;
    for(int x=1;x<=circulos;x++){
        cin>>raio[x];
        raio[x]=raio[x]*raio[x];
    }
    int resp=0;
    for(int k=0;k<tiros;k++){
        cin>>x>>y;
        resp+=buscabinaria(x*x+y*y);
    }
    cout<<resp<<"\n";

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
