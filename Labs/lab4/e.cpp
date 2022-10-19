#include <iostream>
#include <algorithm>
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
        return;
    cout << root->val << " ";
    Print(root->left);
    Print(root->right);
}

int getHeight(Tree *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int getSizeOfValLastLevel(Tree *root, int lev)
{
    int cnt = 0;
    if (root == NULL)
        return 0;
    if (lev == 1)
    {
        cnt++;
    }
    return cnt + getSizeOfValLastLevel(root->left, lev - 1) + getSizeOfValLastLevel(root->right, lev - 1);
}

void calculateLevelSum(Tree *Tree, int level, int sum[], int height)
{
    if (Tree == NULL)
        return;
    // Add current Tree data to the sum
    // of the current Tree's level
    sum[level] += 1;

    // Recursive call for left and right sub-tree
    calculateLevelSum(Tree->left, level + 1, sum, height);
    calculateLevelSum(Tree->right, level + 1, sum, height);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y, z;
    cin >> n;
    Tree *root = new Tree(1);
    for (int i(1); i < n; i++)
    {
        cin >> x >> y >> z;
        root = Insert(root, x, y, z);
    }
    int height = getHeight(root);
    int sum[height] = {0};
    calculateLevelSum(root, 0, sum, height);
    int maximum = 0;
    for (int i(0); i < height; i++)
    {
        if (maximum < sum[i])
        {
            maximum = sum[i];
        }
    }
    cout << maximum << endl;
    return 0;
}