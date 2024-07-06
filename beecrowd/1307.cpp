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


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para verificar se uma string é válida
bool isValid(const string& s) {
    return s.size() >= 2 && s[0] != '0' && count(s.begin(), s.end(), '0') != s.size() && count(s.begin(), s.end(), '1') != s.size();
}

// Função para verificar se é possível construir ambas as strings somente com o mesmo padrão
bool canBuildWithSamePattern(const string& s1, const string& s2) {
    int gcd_value = gcd(s1.size(), s2.size());
    string pattern1 = s1.substr(0, gcd_value);
    string pattern2 = s2.substr(0, gcd_value);

    // Verifica se os padrões são iguais
    if (pattern1 != pattern2) {
        return false;
    }

    // Verifica se o padrão é repetido para construir cada string
    for (int i = 0; i < s1.size(); i += gcd_value) {
        if (s1.substr(i, gcd_value) != pattern1) {
            return false;
        }
    }

    for (int i = 0; i < s2.size(); i += gcd_value) {
        if (s2.substr(i, gcd_value) != pattern2) {
            return false;
        }
    }

    return true;
}

void solve() {
    int N;
    cin >> N;
    
    for (int p = 1; p <= N; ++p) {
        string s1, s2;
        cin >> s1 >> s2;
        
        cout << "Pair #" << p << ": ";
        if (isValid(s1) && isValid(s2) && canBuildWithSamePattern(s1, s2)) {
            cout << "All you need is love!" << endl;
        } else {
            cout << "Love is not all you need!" << endl;
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
