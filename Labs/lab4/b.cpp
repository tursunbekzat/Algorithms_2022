#include <iostream>
using namespace std;

struct Tree
{
    int val;
    int cnt;
    Tree *left, *right;
    Tree(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
        cnt = 1;
    }
};

Tree *Insert(int val, Tree *root)
{
    if (root == NULL)
    {
        root = new Tree(val);
    }
    else if (root->val > val)
    {
        root->left = Insert(val, root->left);
    }
    else if (root->val < val)
    {
        root->right = Insert(val, root->right);
    }
    else
    {
        root->cnt++;
    }
    return root;
}

void Preorder(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Tree *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}

void Postorder(Tree *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->val << " ";
}

int Find(Tree* root){
    if(root == NULL) return 0;
    return 1 + Find(root->left) + Find(root->right);
}

int FindNodes(int val, Tree* root){
    if(root == NULL) return 0;
    if(root->val > val){
        return FindNodes(val, root->left);
    }
    else if(root->val < val){
        return FindNodes(val, root->right);
    }
    return Find(root);
}

int main()
{
    Tree *root = NULL;
    int n;
    cin >> n;
    for (int i(0); i < n; i++)
    {
        int x;
        cin >> x;
        root = Insert(x, root);
    }
    int k;
    cin >> k;
    cout << FindNodes(k, root);
    // Inorder(root);
    // cout << endl;
    // Preorder(root);
    // cout << endl;
    // Postorder(root);
    // cout << endl;
    return 0;
}