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


void solve() {
    int n;
    cin >> n;
    vector<string> commands(n);
    for (int i = 0; i < n; ++i) {
        cin >> commands[i];
    }

    stack<int> s;
    vector<int> memory(100, 0);
    vector<int> output;

    for (const auto& command : commands) {
        if (command.substr(0, 5) == "push_") {
            if (command[5] == 'R') {
                int pos = stoi(command.substr(6));
                s.push(memory[pos]);
            } else {
                int value = stoi(command.substr(5));
                s.push(value);
            }
        } else if (command.substr(0, 4) == "pop_") {
            int pos = stoi(command.substr(4));
            memory[pos] = s.top();
            s.pop();
        } else if (command == "add") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(a + b);
        } else if (command == "mul") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(a * b);
        } else if (command == "div") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(a / b);
        } else if (command == "sub") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(a - b);
        } else if (command == "print") {
            output.push_back(s.top());
            s.pop();
        }
    }

    for (const auto& val : output) {
        cout << val << endl;
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
