#include <bits/stdc++.h>
using namespace std;

const double INF = numeric_limits<double>::max();

double hungarianAlgorithm(const vector<vector<double>>& costMatrix) {
    int n = costMatrix.size();
    int m = costMatrix[0].size();
    vector<double> u(n + 1, 0), v(m + 1, 0);
    vector<int> p(m + 1, 0), way(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        vector<double> minv(m + 1, INF);
        vector<bool> used(m + 1, false);
        int j0 = 0;
        p[0] = i;
        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            double delta = INF;
            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    double cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                   if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    double totalCost = -v[0];
    for (int j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            totalCost += costMatrix[p[j] - 1][j - 1];
        }
    }

    return totalCost;
}
int main() {
    int n, m; 
    while(true){
    cin >> n >> m;
    if(n == 0 && m == 0){
        break;
    }

    vector<pair<int, int>> xy_n(n);
    vector<pair<int, int>> xy_m(m);
    vector<double> v(n);
    vector<set<int>> postos(m);

    for (int i = 0; i < n; i++) {
        int x, y; 
        double vv; 
        cin >> x >> y >> vv;
        xy_n[i] = {x, y};
        v[i] = vv;
    }

    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        xy_m[i] = {x, y};
        int k;
        while (true) {
            cin >> k;
            if (k == 0) {
                break;
            }
            postos[i].insert(k - 1);
        }
    }

    vector<vector<double>> mat(n, vector<double>(m, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (postos[j].find(i) != postos[j].end()) {
                mat[i][j] = sqrt(pow(xy_n[i].first - xy_m[j].first, 2) + pow(xy_n[i].second - xy_m[j].second, 2)) / v[i];
            }
        }
            }

    double r = hungarianAlgorithm(mat)/2.;

    cout << fixed << setprecision(1) << r << endl;

    }

    return 0;
}