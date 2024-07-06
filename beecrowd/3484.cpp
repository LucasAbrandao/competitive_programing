#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    vector<int> getMin() {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int minHeight = INT_MAX;
            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front();
                q.pop();

                minHeight = min(minHeight, currentNode->data);

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }
            result.push_back(minHeight);
        }

        return result;
    }

private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }
};

int main() {
    BinaryTree tree;

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        tree.insert(heights[i]);
    }

    vector<int> r = tree.getMin();

    for (int i = 0; i < (int)r.size(); i++) {
        cout << i << " " << r[i] << endl;
    }

    return 0;
}