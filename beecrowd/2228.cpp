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

bool isSubsetSum(vi set, int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

void solve()
{

    int t = 1;
    while (true)
    {

        int X, Y, N;
        cin >> X >> Y >> N;

        if (X == 0 && Y == 0 && N == 0)
            break;

        vector<int> values(N);
        int total_sum = 0;

        for (int i = 0; i < N; i++)
        {
            int aux;
            cin >> aux;
            values[i] = aux;
            total_sum += aux;
        }

        total_sum += X + Y;

        cout << "Teste " << t++ << endl;

        if (total_sum % 2 == 0)
        {

            int target = (total_sum) / 2;
            target -= X;

            if (isSubsetSum(values, N, target))
                cout << "S" << endl;
            else
                cout << "N" << endl;

            cout << endl;
        }
        else
            cout << "N" << endl
                 << endl;
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
