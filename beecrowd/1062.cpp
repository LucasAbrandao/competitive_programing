#include <bits/stdc++.h>
using namespace std;

#define _                             \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define int long long int
#define double long double
#define vi vector<int>
#define pii pair<int, int>
#define endl "\n"
#define print_v(a)        \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_vp(a)  \
    for (auto x : a) \
    cout << x.first << " " << x.second << endl
#define f(i, s, e) for (int i = s; i < e; i++)
#define rf(i, e, s) for (int i = e - 1; i >= s; i--)
#define CEIL(a, b) ((a) + (b - 1)) / b
#define TRUNC(x, n) floor(x *pow(10, n)) / pow(10, n)
#define ROUND(x, n) round(x *pow(10, n)) / pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e9;    // 2^31-1
const int LLINF = 4e18; // 2^63-1
const double EPS = 1e-9;
const int MAX = 1e6 + 10; // 10^6 + 10

bool canReorder(int n, vi &desiredOrder)
{
    stack<int> station;
    int current = 1;

    for (int i = 0; i < n; i++)
    {
        while (current <= desiredOrder[i])
        {
            station.push(current);
            current++;
        }
        if (!station.empty() && station.top() == desiredOrder[i])
        {
            station.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        while (true)
        {
            vi desiredOrder(n);
            cin >> desiredOrder[0];
            if (desiredOrder[0] == 0)
                break;
            for (int i = 1; i < n; i++)
            {
                cin >> desiredOrder[i];
            }

            if (canReorder(n, desiredOrder))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
}
int32_t main()
{
    _

        clock_t z = clock();
    int t = 1; // cin >> t;
    while (t--)
    {
        solve();
    }
    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
