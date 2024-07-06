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



int numeroDigitos(int n) {
    int numDigits = 0;
    while (n > 0) {
        n /= 10;
        numDigits++;
    }
    return numDigits;
}

void algarismosSeparados(int init, int end)  {
    bool ver = false;

    for(int k = init; k <= end; k++) {
        int n = k;
        int sum = 0;
        int numDigits = numeroDigitos(n);

        while (n > 0) {
            int digit = n % 10;
            sum += pow(digit, numDigits);
            n /= 10;

        }

        if (sum == k) {
            ver = true;
            cout << k << " ";
        }
    }

    if (!ver) {
        cout << "Nenhum" << endl;
    }else {
        cout << endl;
    }

}

void solve() {
    int n;
    cin >> n;

    for(int kl = 0; kl < n; kl++) {
        int init, end;
        cin >> init >> end;
        algarismosSeparados(init, end);
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
