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
        left = right = NULL;
    }
};

Tree *Insert(Tree *root, int x, int y, int z)
{
    if (root == NULL)
        return root;
    if (root->val > x)
    {
        Insert(root->left, x, y, z);
    }
    else if (root->val < x)
    {
        Insert(root->right, x, y, z);
    }
    else
    {
        if (z == 0)
        {
            // cout << 1 << endl;
            root->left = Insert(root->left, x, y, z);
            // cout << 2 << endl;
        }
        else
        {
            root->right = Insert(root->right, x, y, z);
        }
    }
    return root;
}

void Print(Tree *root)
{
    if (root == NULL)
    {
        return;
    }   
    cout << root->val << " ";
    Print(root->left);
    Print(root->right);
}

int main()
{
    Tree *root;
    root = new Tree(1);
    int n;
    cin >> n;
    for (int i(1); i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        root = Insert(root, x, y, z);
    }
    Print(root);
    return 0;
}