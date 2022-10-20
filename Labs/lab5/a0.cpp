#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>

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
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    Print(root->left);
    Print(root->right);
}

int Sum(Tree *root, vector<int> *v)
{
    if (root == NULL)
    {
        return 0;
    }
    Sum(root->left, v);
    Sum(root->right, v);
    if (root->left == NULL)
    {
        if (root->right != NULL)
        {
            (*v).push_back(root->val + root->right->val);
            root->val += root->right->val;
        }
    }
    else
    {
        (*v).push_back(root->val + root->left->val);
        root->val += root->left->val;
    }
    return 0;
}

int main()
{
    vector<int> v;
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
    Sum(root, &v);
    v.push_back(v[v.size() - 1] + root->right->val);
    int sum = 0;
    for (int i(0); i < v.size(); i++)
    {
        sum += v[i];
        cout << v[i] << " ";
    }

    cout << endl
         << sum << endl;
    return 0;
}