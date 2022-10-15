#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int lev = 0;

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
    else if (root->val < val)
    {
        root->right = Insert(root->right, val);
    }
    else
    {
        root->cnt++;
    }
    return root;
}

void Print(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    Print(root->left);
    Print(root->right);
}

void Preorder(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    Preorder(root->right);
    Preorder(root->left);
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

Tree* SumLevel(Tree *root)
{
    int sum = 0;
    if (root == NULL)
        return root;
    SumLevel(root->left);
    SumLevel(root->right);
    v.push_back(sum);
    return root;
}

int main()
{
    int n;
    cin >> n;
    Tree *root = NULL;
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = Insert(root, x);
    }
    SumLevel(root);

    v.push_back(root->val);
    cout << lev + 1<< endl;
    for (int i(lev); i > -1; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}