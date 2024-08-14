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

const int INF = 1e9;
const int MAXN = 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct State {
    int ax, ay, bx, by, cx, cy;
    int dist;
};

int N;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN][MAXN][MAXN][MAXN];

bool valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] != '#';
}

void solve() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        int ax, ay, bx, by, cx, cy;
        vector<pii> targets;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'A') ax = i, ay = j;
                if (grid[i][j] == 'B') bx = i, by = j;
                if (grid[i][j] == 'C') cx = i, cy = j;
                if (grid[i][j] == 'X') targets.push_back({i, j});
            }
        }

        memset(visited, false, sizeof(visited));
        queue<State> q;
        q.push({ax, ay, bx, by, cx, cy, 0});
        visited[ax][ay][bx][by][cx][cy] = true;

        bool found = false;

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            if ((cur.ax == targets[0].first && cur.ay == targets[0].second) ||
                (cur.ax == targets[1].first && cur.ay == targets[1].second) ||
                (cur.ax == targets[2].first && cur.ay == targets[2].second)) {
                if ((cur.bx == targets[0].first && cur.by == targets[0].second) ||
                    (cur.bx == targets[1].first && cur.by == targets[1].second) ||
                    (cur.bx == targets[2].first && cur.by == targets[2].second)) {
                    if ((cur.cx == targets[0].first && cur.cy == targets[0].second) ||
                        (cur.cx == targets[1].first && cur.cy == targets[1].second) ||
                        (cur.cx == targets[2].first && cur.cy == targets[2].second)) {
                        cout << "Case " << t << ": " << cur.dist << endl;
                        found = true;
                        break;
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                int nax = cur.ax + dx[i], nay = cur.ay + dy[i];
                int nbx = cur.bx + dx[i], nby = cur.by + dy[i];
                int ncx = cur.cx + dx[i], ncy = cur.cy + dy[i];

                if (!valid(nax, nay)) nax = cur.ax, nay = cur.ay;
                if (!valid(nbx, nby)) nbx = cur.bx, nby = cur.by;
                if (!valid(ncx, ncy)) ncx = cur.cx, ncy = cur.cy;

                if (nax == nbx && nay == nby) continue;
                if (nax == ncx && nay == ncy) continue;
                if (nbx == ncx && nby == ncy) continue;

                if (!visited[nax][nay][nbx][nby][ncx][ncy]) {
                    visited[nax][nay][nbx][nby][ncx][ncy] = true;
                    q.push({nax, nay, nbx, nby, ncx, ncy, cur.dist + 1});
                }
            }
        }

        if (!found) {
            cout << "Case " << t << ": trapped" << endl;
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
