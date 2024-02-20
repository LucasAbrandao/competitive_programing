#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " ";
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

int a, b;

void solve() {
	    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    vector<int> odd_numbers, even_numbers;

    for (int i = 0; i < N; i++) {
        if (numbers[i] % 2 == 1) {
            odd_numbers.push_back(numbers[i]);
        } else {
            even_numbers.push_back(numbers[i]);
        }
    }

    sort(odd_numbers.begin(), odd_numbers.end());
    sort(even_numbers.begin(), even_numbers.end());

    print_v(odd_numbers);
    print_v(even_numbers);
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