#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
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
    if (root->val < val)
    {
        root->right = Insert(root->right, val);
    }
    else
    {
        root->left = Insert(root->left, val);
    }
    return root;
}

void Check(Tree *root, string s)
{
    int c = 0;
    for (int i(0); i < s.size(); i++)
    {
        if (s[i] == 'L')
        {
            if (root->left != NULL)
            {
                root = root->left;
                c++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (root->right != NULL)
            {
                root = root->right;
                c++;
            }
            else
            {
                break;
            }
        }
        // root = root->left;
    }
    if (c == s.size())
    {
        v.push_back(0);
    }
    else
    {
        v.push_back(1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    Tree *root = NULL;

    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = Insert(root, x);
    }
    string s;
    char c;
    for (int i(0); i < m; i++)
    {
        cin >> s;
        Check(root, s);
    }
    for (int i(0); i < v.size(); i++)
    {
        // cout << v[i] << " ";
        if (v[i] == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}