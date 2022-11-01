#include <iostream>
using namespace std;

struct Tree
{
    int val, cnt;
    Tree *left, *right;
    Tree(int val)
    {
        this->val = val;
        left = right = NULL;
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
    if (root->val < val)
    {
        root->right = Insert(root->right, val);
    }
    if (root->val == val)
    {
        root->cnt++;
    }
    return root;
}

int FindSum(Tree* root, int l){
    if(root == NULL) return 0;
    int sum = root->val - l;
    sum += (FindSum(root->left, l + 1) + FindSum(root->right, l + 1));
    return sum;
}

// void print(Tree* root){
//     if(root == NULL){
//         return;
//     }
//     cout << root->val << " ";
//     print(root->left);
//     print(root->right);
// }

int main()
{
    int n;
    cin >> n;

    Tree *root = NULL;

    int val;
    for (int i(0); i < n; i++)
    {
        cin >> val;
        root = Insert(root, val);
    }
    // print(root);
    cout << FindSum(root, 0) << endl;

    return 0;
}