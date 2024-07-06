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

void solve()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    pii coordMic;
    cin >> coordMic.first >> coordMic.second;

    int minutos = 0, x_atual = 0, y_atual = 0, direc = 0, k;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> direc;

        switch (direc)
        {
        case 1:
            y_atual++;
            break;
        case 2:
            y_atual--;
            break;
        case 3:
            x_atual++;
            break;
        case 4:
            x_atual--;
            break;
        }

        if (x_atual >= coordMic.first - 1 &&
            x_atual <= coordMic.first + 1 &&
            y_atual >= coordMic.second - 1 &&
            y_atual <= coordMic.second + 1)
            minutos++;
    }



    cout << minutos << endl;
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
