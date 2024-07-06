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

void replaceChars(string& s) {
    for (int i = 0; i < s.size(); i++) {

		char& c = s[i];

        switch (c) {
            case 'a':
                c = '@';
                break;
            case 'e':
                c = '&';
                break;
            case 'i':
                c = '!';
                break;
            case 'o':
                c = '*';
                break;
            case 'u':
                c = '%';
                break;
        }

		s[i] = c;
    }
}

void solve() {

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		replaceChars(s);
		cout << s << endl;
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