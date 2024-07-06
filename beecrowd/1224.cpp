#include <bits/stdc++.h>
using namespace std;

// Estrutura do nó da AVL Tree
struct Node {
    int key;
    Node *left, *right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Classe da AVL Tree
class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    // Função para obter a altura de um nó
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Função para realizar uma rotação simples à direita
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Realiza a rotação
        x->right = y;
        y->left = T2;

        // Atualiza alturas
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Função para realizar uma rotação simples à esquerda
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Realiza a rotação
        y->left = x;
        x->right = T2;

        // Atualiza alturas
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Função para inserir um novo valor na árvore AVL
    Node* insert(Node* node, int key) {
        // Passo de inserção padrão de uma BST
        if (node == nullptr) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Chaves iguais não são permitidas na árvore AVL
            return node;

        // Atualiza a altura deste nó ancestral
        node->height = 1 + max(height(node->left), height(node->right));

        // Calcula o fator de balanceamento deste nó para verificar se houve desbalanceamento
        int balance = getBalance(node);

        // Se o nó se tornou desbalanceado, existem quatro casos de rotação

        // Caso Esquerda-Esquerda
        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        // Caso Direita-Direita
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        // Caso Esquerda-Direita
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Caso Direita-Esquerda
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        // Retorna o ponteiro do nó (inalterado)
        return node;
    }

    // Função para obter o fator de balanceamento de um nó
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Função para encontrar o menor valor na árvore AVL
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Função para deletar um valor na árvore AVL
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;

        // Passo de deleção padrão de uma BST
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Nó com somente um filho ou nenhum filho
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                // Caso sem filho
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else // Caso com um filho
                    *root = *temp; // Copia o conteúdo do filho não vazio
                delete temp;
            } else {
                // Nó com dois filhos: obtem o sucessor inordem (menor na subárvore direita)
                Node* temp = minValueNode(root->right);

                // Copia o valor do sucessor inordem para este nó
                root->key = temp->key;

                // Deleta o sucessor inordem
                root->right = deleteNode(root->right, temp->key);
            }
        }

        // Se a árvore tinha somente um nó, então retorna
        if (root == nullptr) return root;

        // Atualiza a altura deste nó ancestral
        root->height = 1 + max(height(root->left), height(root->right));

        // Calcula o fator de balanceamento deste nó para verificar se houve desbalanceamento
        int balance = getBalance(root);

        // Se o nó se tornou desbalanceado, existem quatro casos de rotação

        // Caso Esquerda-Esquerda
        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

        // Caso Esquerda-Direita
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Caso Direita-Direita
        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

        // Caso Direita-Esquerda
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Função para encontrar o menor valor na árvore AVL
    int findMin() {
        Node* current = root;
        while (current->left != nullptr)
            current = current->left;
        return current->key;
    }
};

void solve() {
    int N;
    cin >> N;
    
    vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    // Arrays para armazenar dpA e dpW
    vector<int> dpA(N);
    vector<int> dpW(N);

    // Inicializa a árvore AVL
    AVLTree avl;

    // Preenche dpA e dpW de trás para frente
    for (int i = N - 1; i >= 0; --i) {
        // Insere o cartão atual na árvore AVL
        avl.root = avl.insert(avl.root, cards[i]);

        // Calcula dpW[i] (o mínimo que Wanderley pode fazer a partir da posição i)
        dpW[i] = avl.findMin();

        // Calcula dpA[i] (o máximo que Alberto pode fazer a partir da posição i)
        dpA[i] = cards[i];
        if (i < N - 1) {
            dpA[i] += dpW[i + 1]; // Melhor soma possível a partir de i+1 (considerando que é a vez de Wanderley)
        }
    }

    // A resposta para este caso é dpA[0]
    cout << dpA[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
