#include <iostream>
using namespace std;

int cnt = 0;

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

Tree *Insert(Tree *root, int val)
{
    if (root == NULL)
    {
        root = new Tree(val);
        return root;
    }
    if (root->val < val)
    {
        root->right = Insert(root->right, val);
    }
    else if (root->val > val)
    {
        root->left = Insert(root->left, val);
    }
    else
    {
        root->cnt++;
    }
    return root;
}

int SumBinaryTriangle(Tree *root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->right != NULL)
    {
        cnt++;
    }
    return SumBinaryTriangle(root->left) + SumBinaryTriangle(root->right);
}

int main()
{
    Tree *root = NULL;
    int n;
    cin >> n;
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = Insert(root, x);
    }
    SumBinaryTriangle(root);
    cout << cnt << endl;
    return 0;
}