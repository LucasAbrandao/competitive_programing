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
    while (cin >> n) {
        stack<int> stk;
        queue<int> que;
        priority_queue<int> priQue;

        bool isStack = true, isQueue = true, isPriorityQueue = true;

        for (int i = 0; i < n; ++i) {
            int command;
            cin >> command;
            if (command == 1) {
                int x;
                cin >> x;
                if (isStack) stk.push(x);
                if (isQueue) que.push(x);
                if (isPriorityQueue) priQue.push(x);
            } else if (command == 2) {
                int x;
                cin >> x;
                if (isStack) {
                    if (stk.empty() || stk.top() != x) isStack = false;
                    else stk.pop();
                }
                if (isQueue) {
                    if (que.empty() || que.front() != x) isQueue = false;
                    else que.pop();
                }
                if (isPriorityQueue) {
                    if (priQue.empty() || priQue.top() != x) isPriorityQueue = false;
                    else priQue.pop();
                }
            }
        }

        int possibilities = isStack + isQueue + isPriorityQueue;
        if (possibilities > 1) {
            cout << "not sure" << endl;
        } else if (isStack) {
            cout << "stack" << endl;
        } else if (isQueue) {
            cout << "queue" << endl;
        } else if (isPriorityQueue) {
            cout << "priority queue" << endl;
        } else {
            cout << "impossible" << endl;
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
