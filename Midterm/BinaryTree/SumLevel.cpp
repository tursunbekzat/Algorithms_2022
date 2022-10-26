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
        return root;
    }
    if (root->val > val)
    {
        root->left = Insert(root->left, val);
    }
    if (root->val < val)
    {
        root->right = Insert(root->right, val);
    }
    return root;
}

void Print(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->val << " -> ";
    Print(root->left);
    Print(root->right);
}

int getHeight(Tree *root)
{
    if (root == NULL)
        return 0;
    return (1 + getHeight(root->left) + getHeight(root->right));
}

void SumLevel(Tree *root, int sl[], int i)
{
    if (root == NULL)
    {
        return;
    }
    sl[i] += root->val;
    SumLevel(root->left, sl, i + 1);
    SumLevel(root->right, sl, i + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    Tree *root = NULL;

    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = Insert(root, x);
    }

    // Print(root);
    // cout << "NULL\n";

    int size = getHeight(root);

    // cout << size << endl;

    int sl[size - 1] = {0};

    SumLevel(root, sl, 0);

    for (int i(0); i < size - 1; i++)
    {
        cout << sl[i] << " ";
    }
    cout << endl;

    return 0;
}