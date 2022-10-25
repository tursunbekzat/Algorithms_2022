#include <iostream>
using namespace std;

struct Tree {
    int val;
    int cnt;
    Tree *left, *right;

    Tree(int value) {
        this->val = value;
        cnt = 1;
        left = NULL;
        right = NULL;
    }
};

Tree* getMin(Tree *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Tree* insert(int value, Tree *root) {
    if (root == NULL) {
        root = new Tree(value);
    } else if (root->val > value) {
        root->left = insert(value, root->left);
    } else if (root->val < value) {
        root->right = insert(value, root->right);
    } else {
        root->cnt++;
    }
    return root;
}

Tree* remove(int value, Tree *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->val > value) {
        root->left = remove(value, root->left);
    } else if (root->val < value) {
        root->right = remove(value, root->right);
    } else {
        if (root->cnt > 1) {
            root->cnt--;
        } else if (!(root->left)) {
            return root->right;
        } else if (!(root->right)) {
            return root->left;
        } else {
            Tree *mn = getMin(root->right);
            root->val = mn->val;
            root->cnt = mn->cnt;
            root->right = remove(mn->val, root->right);
        }
    }
    return root;
}

int count(int value, Tree *root) {
    if (root == NULL) {
        return 0;
    } else if (root->val == value) {
        return root->cnt;
    } else if (root->val > value) {
        return count(value, root->left);
    } else {
        return count(value, root->right);
    }
}

int getHeight(Tree *root) {
    if (root == NULL) return 0;
    else {
        return 1 + max(
            getHeight(root->left),
            getHeight(root->right)
        );
    }
}

int getSize(Tree *root) {
    if (root == NULL) return 0;
    else return 1 + getSize(root->left) + getSize(root->right);
}

void preorder(Tree *root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Tree *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Tree *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    // Node *root = NULL;
    // int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int a; cin >> a;
    //     root = insert(a, root);
    // }
    // inorder(root);
    // cout << endl;

    // int m; cin >> m;
    // for (int i = 0; i < m; i++) {
    //     int a; cin >> a;
    //     root = remove(a, root);
    //     inorder(root);
    // }

    int n; cin >> n;
    Tree *root = NULL;
    for (int i = 0; i < n; i++) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "insert") {
            root = insert(x, root);
        }
        if (op == "delete") {
            root = remove(x, root);
        }
        if (op == "cnt") {
            cout << count(x, root) << endl;
        }
    }
}