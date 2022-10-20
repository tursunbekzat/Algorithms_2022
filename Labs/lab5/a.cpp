#include <iostream>

using namespace std;

struct Tree
{
    int val;
    Tree *left, *right;
    Tree(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

Tree *Insert(Tree *root, int val)
{
    if (root == NULL)
    {
        root = new Tree(val);
        // return root;
    }
    else if (root->val < val)
    {
        root->right = Insert(root->right, val);
        // root->right = new Tree(val);
    }
    else
    {
        root->left = Insert(root->left, val);
        // root->left = new Tree(val);
    }
    return root;
}

void Print(Tree *root)
{
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    Print(root->left);
    Print(root->right);
}

int main()
{
    Tree *root = NULL;
    int n, x;
    cin >> n;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = Insert(root, x);
    }
    Print(root);
    cout << endl;
    return 0;
}