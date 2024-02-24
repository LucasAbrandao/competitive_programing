#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define f(i,s,e)       for(int i=s;i<e;i++)
#define rf(i,e,s)      for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool canBeFactored(int n) {
    if (n <= 3) return false;
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0 && isPrime(i) && isPrime(n / i)) {
            return true;
        }
    }
    return false;
}

void solve() {

    int n;
    cin >> n;

    cout << canBeFactored(n) << endl;
}

int32_t main() { _
    
    clock_t z = clock();

    int t = 1; // cin >> t;
    while (t--) 
        solve();

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
