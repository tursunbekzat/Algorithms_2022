#include <iostream>
#include <vector>
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
        cnt = 1;
    }
};

Tree *Insert(Tree *root, int x, int y, int z)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->val == x)
    {
        if (z > 0)
        {
            root->right = new Tree(y);
        }
        else
        {
            root->left = new Tree(y);
        }
        return root;
    }
    root->left = Insert(root->left, x, y, z);
    root->right = Insert(root->right, x, y, z);
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

int Sum(Tree *root)
{
    if (root == NULL)
    {
        cout << "NULL";
        return 1;
    }
    int sum = 0;
    if (root->left)
    {
        if (root->right)
        {
            cout << root->left->val << " <- " << root->val << " -> " << root->right->val;
            sum = root->left->val + root->right->val;
        }
        else
        {
            cout << root->left->val << " <- " << root->val << " -> NULL";
            sum = root->left->val;
        }
    }
    else if (root->right)
    {
        cout << "NULL <- " << root->val << " -> " << root->right->val;
        sum = root->right->val;
    }
    else
    {
        cout << "NULL <- " << root->val << " -> NULL";
        sum = root->val;
    }
    return sum;
}

int getMax(Tree *root)
{
    if(root == NULL){
        return 0;
    }
    int max = root->val;
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    if (max < getMax(root->left))
        max = getMax(root->left);
    if (max < getMax(root->right))
        max = getMax(root->right);
    return max;
}

int main()
{
    Tree *root = NULL;
    root = new Tree(1);
    int n;
    cin >> n;
    for (int i(0); i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        root = Insert(root, x, y, z);
    }
    // Print(root);
    // cout << endl;

    cout << getMax(root)
         << endl;
    // cout << endl;
    // Sum(root);
    // cout << endl;
    // Sum(root->left);
    // cout << endl;
    // Sum(root->right);
    // cout << endl;
    return 0;
}