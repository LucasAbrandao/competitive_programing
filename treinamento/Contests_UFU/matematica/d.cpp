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

bool is_palindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

string add_reverse(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    int carry = 0;
    string result = "";

    for (int i = s.length() - 1; i >= 0; i--) {
        int sum = (s[i] - '0') + (rev[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

void solve() {
    string num;
    cin >> num;

    int steps = 0;
    while (!is_palindrome(num) && steps < 4) {
        num = add_reverse(num);
        steps++;
    }

    if (is_palindrome(num)) {
        cout << num << endl;
    } else {
        cout << 0 << endl;
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