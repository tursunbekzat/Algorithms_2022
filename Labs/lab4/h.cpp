#include <iostream>
#include <vector>
using namespace std;

vector<int> v, v1;

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

void sumReverse(Tree *root, vector<int> v, int k)
{
    if (root == NULL)
        return;
    sumReverse(root->left, v, k + 1);
    // cout << root->val << " ";
    v.push_back(root->val + v[k]);
    sumReverse(root->right, v, k + 1);
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
    // cout << root->val << " ";
    v.push_back(root->val);
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
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    Tree *root = NULL;

    int n, x;
    cin >> n;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = Insert(root, x);
    }
    // sumReverse(root, v, 1);
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;
    // v.push_back(0);
    // for (int i(1); i < v.size(); i++)
    // {
    //     int s = inorder(root);
    //     v.push_back(v[i-1] + inorder(root));
    // }
    inorder(root);
    // for (int i(0); i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    for (int i(0); i < v.size(); i++)
    {
        int sum = 0, j = i;
        while (j + 1)
        {
            sum += v[j];
            j--;
        }
        v1.push_back(sum);
    }
    for (int i(0); i < v.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    return 0;
}