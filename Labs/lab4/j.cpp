#include <iostream>
#include <math.h>
#include <vector>
#include <random>
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

Tree *Insert(Tree *root, int val)
{
    if (root == NULL)
    {
        root = new Tree(val);
        return root;
    }
    if (root->val < val)
    {
        root->left = Insert(root->left, val);
    }
    else if (root->val > val)
    {
        root->right = Insert(root->right, val);
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

void inorder(Tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void Postorder(Tree *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Tree *root = NULL;

    vector<int> v;

    int n, x;
    cin >> n;
    for (int i(0); i < pow(2, n) - 1; i++)
    {
        cin >> x;
        v.push_back(x);
        root = Insert(root, x);
    }
    vector<int> v1;
    while(1){
        v1 = {0};
    }
    return 0;
}