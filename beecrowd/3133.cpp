#include <bits/stdc++.h>

using namespace std;

int memo[101][3][3001];
vector<pair<int, int>> arr;
int n;

int prej = 0;
int lucr = 0;

int k = 0;

int dp(int i, int t, int l, int p) {
    //k++;
    if (t == 3) {
        return l - (prej - p);
    }

    if (i == n) {
        return -INT_MAX;
    }

    if (memo[i][t][l] != -1) {
        return memo[i][t][l];
    }

    int include = dp(i + 1, t + 1, l + arr[i].first, p + arr[i].second);
    int exclude = dp(i + 1, t, l, p);

    return memo[i][t][l] = max(include, exclude);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        b = -b;
        prej += b;
        lucr += a;
        arr.push_back({a, b});
            }

    memset(memo, -1, sizeof(memo));

    int r = dp(0,0,0,0);

    if(r == -1023){
        cout << -1007 << endl;
    }else{
        cout << r << endl;
    }

    //cout << k << endl;

    return 0;
}