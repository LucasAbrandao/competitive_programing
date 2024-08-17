#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
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

int time_difference(int i, int j) {
    return min(abs(i - j), 24 - abs(i - j));
}

int dp[1 << 20]; 
int n;
vi times;

int solve(int mask) {
    if (mask == (1 << n) - 1) return 0; 

    if (dp[mask] != -1) return dp[mask]; 
    int ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) { // If i is not yet paired
            for (int j = i + 1; j < n; j++) {
                if (!(mask & (1 << j))) { // If j is not yet paired
                    int new_mask = mask | (1 << i) | (1 << j);
                    int current_diff = time_difference(times[i], times[j]);
                    ans = min(ans, current_diff + solve(new_mask));
                }
            }
        }
    }

    return dp[mask] = ans;
}

int32_t main() { _
	clock_t z = clock();
    
    cin >> n;
    times.resize(n);
    f(i, 0, n) cin >> times[i];

    memset(dp, -1, sizeof(dp));
    
    cout << solve(0) << endl;

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
