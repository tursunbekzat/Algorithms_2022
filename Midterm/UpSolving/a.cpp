#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

struct bst
{
    int val;
    bst *left, *right;
    bst(int v);
};

bst ::bst(int v)
{
    val = v;
    left = right = NULL;
}

bst *insert(int val, bst *root)
{
    if (root == NULL)
        return new bst(val);
    if (root->val > val)
        root->left = insert(val, root->left);
    if (root->val < val)
        root->right = insert(val, root->right);
    return root;
}

// void print(bst *root)
// {
//     while (root != NULL)
//     {
//         if (root->left)
//         {
//             if (root->right)
//             {
//                 cout << root->left->val << " <- " << root->val << " -> " << root->right->val;
//             }
//             else
//             {
//                 cout << root->left->val << " <- " << root->val << " -> NULL";
//             }
//         }
//         else if (root->right)
//         {
//             cout << "NULL <- " << root->val << " -> " << root->right->val;
//         }
//         else
//         {
//             cout << "NULL <- " << root->val << " -> NULL";
//         }
//         cout << endl;
//         root = root->left;
//     }
// }

int find(bst *root)
{
    if (root == NULL)
        return 0;
    if (root->left && root->right)
        return 1;
    return 0;
}

int findtriangles(bst *root)
{
    // if (root == NULL)
    //     return 0;
    int suml = 0, sumr = 0, sum = 0;
    sum += find(root);
    // cout << "left level = " << suml << "    right level = " << sumr << "\n";
    // sum = suml + sumr;
    cout << "sum = " << sum << "\n";
    return sum;
}

void count(bst *root)
{
    cout << "root value = " << root->val << "\n";
    v.push_back(findtriangles(root));
    bool ok = true;
    bst *root1 = NULL;
    while (root)
    {
        root1 = root;
        int m = 0;
        if (ok)
        {
            root = root->left;
            if(root)
                cout << "root value = " << root->val << "\n";
            m += findtriangles(root);
            ok = false;
            root = root1;
        }
        if (!ok)
        {
            root = root->right;
            if(root)
                cout << "root value = " << root->val << "\n";
            m += findtriangles(root);
            ok = true;
            root = root1->left;
        }
        v.push_back(m);
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    bst *root = NULL;

    cin >> n;

    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = insert(x, root);
    }

    count(root);

    for (int i(0); i < n - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    // print(root);

    return 0;
}