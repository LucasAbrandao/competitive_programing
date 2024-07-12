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


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
        } else {
            _insert(root, key);
        }
    }

    void preorder(Node* node, vector<int>& res) {
        if (node) {
            res.push_back(node->val);
            preorder(node->left, res);
            preorder(node->right, res);
        }
    }

    void inorder(Node* node, vector<int>& res) {
        if (node) {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    }

    void postorder(Node* node, vector<int>& res) {
        if (node) {
            postorder(node->left, res);
            postorder(node->right, res);
            res.push_back(node->val);
        }
    }

private:
    void _insert(Node* node, int key) {
        if (key < node->val) {
            if (node->left == nullptr) {
                node->left = new Node(key);
            } else {
                _insert(node->left, key);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node(key);
            } else {
                _insert(node->right, key);
            }
        }
    }
};

void solve() {
    int C;
    cin >> C;
    for (int i = 0; i < C; ++i) {
        int N;
        cin >> N;
        BinarySearchTree bst;
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            bst.insert(num);
        }

        vector<int> pre, in, post;
        bst.preorder(bst.root, pre);
        bst.inorder(bst.root, in);
        bst.postorder(bst.root, post);

        cout << "Case " << i + 1 << ":\n";
        cout << "Pre.: ";
        for (size_t j = 0; j < pre.size(); ++j) {
            cout << (j ? " " : "") << pre[j];
        }
        cout << "\nIn..: ";
        for (size_t j = 0; j < in.size(); ++j) {
            cout << (j ? " " : "") << in[j];
        }
        cout << "\nPost: ";
        for (size_t j = 0; j < post.size(); ++j) {
            cout << (j ? " " : "") << post[j];
        }
        cout << "\n\n";
    }
}


int32_t main() { _
	
	clock_t z = clock();
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	//cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
