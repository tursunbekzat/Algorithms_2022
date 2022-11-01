// find vertices that have no children

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

Tree *insert(Tree *root, int val)
{
    if (root == NULL)
    {
        return new Tree(val);
    }
    if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    if (root->val < val)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void print(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int FindLeave(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int cnt = 0;
    if (!root->left && !root->right)
    {
        cnt = 1;
    }
    return cnt + FindLeave(root->left) + FindLeave(root->right);
    
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
        root = insert(root, x);
    }

    // print(root);

    cout << FindLeave(root) << endl;

    return 0;
}