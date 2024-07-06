#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> arr;
long long n, k;

int main() {
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    long long i = 1, j = 2e18;

    while (i < j) {
        long long m = i + (j - i) / 2;
        long long count = 0;

        for (int i = 0; i < n; i++) {
            if (m >= arr[i].first) {

                count += (m - arr[i].first) / arr[i].second + 1;

                if (count >= k) {
                    break;
            }
            }
        }

        if (count >= k) {

            j = m;
        } else {
            i = m + 1;
        }
    }

    cout << i << endl;

    return 0;
}
