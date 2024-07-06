#include <bits/stdc++.h>
using namespace std;

#define _                        \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define int long long
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

int n;
vector<set<int>> ini;

int func(int idx, int tot, set<int> np)
{
    if (idx >= n)
        return tot;

    if (np.find(idx) != np.end())
        return func(idx + 1, tot, np);

    int n1 = -1;

    if (!ini[idx].empty())
    {
        np.insert(idx);
        n1 = func(idx + 1, tot, np);
        np.erase(idx);

        for (auto a : ini[idx])
            np.insert(a);
    }

    int n2 = func(idx + 1, tot + 1, np);

    return max(n1, n2);
}

void solve(int cont)
{
    cout << "Teste " << cont << endl;

    ini.clear();
    ini.resize(n);
    int aux;

    for (int i = 0; i < n; i++)
    {
        while (cin >> aux)
        {
            if (aux == 0)
                break;

            ini[i].insert(aux - 1);
            ini[aux - 1].insert(i);
        }
    }

    cout << func(0, 0, set<int>()) << endl;

    cout << endl;
}

int32_t main()
{
    _

        clock_t z = clock();
    int cont = 1;
    while (cin >> n)
    {
        if (n == 0)
            break;
        solve(cont++);
    }

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
