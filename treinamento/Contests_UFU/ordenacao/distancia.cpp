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


double distOrig (pair<double, double> coord) {
	
	double dist = sqrt(pow(coord.first, 2) + pow(coord.second, 2));

	return dist;
}

bool compare(pair<double, double> a, pair<double, double> b) {

	return distOrig(a) < distOrig(b);
}

void solve() {
	int N;
    cin >> N;

    vector<pair<double, double>> pontos(N);

    for (int i = 0; i < N; i++) {
        cin >> pontos[i].first >> pontos[i].second;
    }

    sort(pontos.begin(), pontos.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << pontos[i].first << " " << pontos[i].second << endl;
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