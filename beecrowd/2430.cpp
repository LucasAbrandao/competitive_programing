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



struct Node {
    unordered_map<string, Node*> children;
    bool isFile;
    int subtreeFiles;
    int totalLength;

    Node() : isFile(false), subtreeFiles(0), totalLength(0) {}
};

Node* root = new Node();

void insert(Node* node, const vector<string>& path, int idx) {
    if (idx == path.size()) {
        node->isFile = true;
        return;
    }
    if (!node->children.count(path[idx])) {
        node->children[path[idx]] = new Node();
    }
    node->subtreeFiles++;
    node->totalLength += accumulate(path.begin() + idx, path.end(), 0, [](int acc, const string& s) { return acc + s.size() + 1; }) - 1;
    insert(node->children[path[idx]], path, idx + 1);
}

pair<int, int> dfs(Node* node) {
    if (node->children.empty()) return {0, 0};
    int totalReduction = 0;
    for (auto& [name, child] : node->children) {
        auto [childReduction, filesBelow] = dfs(child);
        totalReduction += childReduction;
        if (!child->isFile) {
            int directPathLength = (child->subtreeFiles + 1) * 3 + (child->totalLength - filesBelow * 3);
            totalReduction += directPathLength;
        }
    }
    return {totalReduction, node->subtreeFiles};
}

int calculateTotalLength(Node* node, int currentDepth) {
    int totalLength = 0;
    for (auto& [name, child] : node->children) {
        if (child->isFile) {
            totalLength += (currentDepth + name.size() + 1);
        } else {
            totalLength += calculateTotalLength(child, currentDepth + name.size() + 1);
        }
    }
    return totalLength;
}

void solve() {
    int N;
    cin >> N;
    vector<string> files(N);
    cin.ignore();
    for (int i = 0; i < N; ++i) {
        getline(cin, files[i]);
        vector<string> path;
        stringstream ss(files[i]);
        string part;
        while (getline(ss, part, '/')) {
            path.push_back(part);
        }
        insert(root, path, 0);
    }

    int initialLength = calculateTotalLength(root, 0);
    auto [reduction, _] = dfs(root);

    cout << initialLength - reduction << endl;
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
