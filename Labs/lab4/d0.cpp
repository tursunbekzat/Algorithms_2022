#include <iostream>
#include <vector>
using namespace std;

vector<int> v, v1, v2;

struct Tree
{
    int val;
    int cnt;
    Tree *left, *right;
    Tree(int val)
    {
        this->val = val;
        cnt = 1;
        left = right = NULL;
    }
};

Tree *Init(Tree *root, int val)
{
    if (root == NULL)
    {
        root = new Tree(val);
        return root;
    }
    if (root->val > val)
    {
        root->left = Init(root->left, val);
    }
    else if (root->val < val)
    {
        root->right = Init(root->right, val);
    }
    else
    {
        root->cnt++;
    }
    return root;
}

// void Print(Tree *root)
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

// Utility function to print
// the contents of an array
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

// Function to return the height
// of the binary tree
int getHeight(Tree* root)
{
    if (root->left == NULL && root->right == NULL)
        return 0;
 
    int left = 0;
    if (root->left != NULL)
        left = getHeight(root->left);
 
    int right = 0;
    if (root->right != NULL)
        right = getHeight(root->right);
 
    return (max(left, right) + 1);
}
 
// Recursive function to update sum[] array
// such that sum[i] stores the sum
// of all the elements at ith level
void calculateLevelSum(Tree* Tree, int level, int sum[])
{
    if (Tree == NULL)
        return;
 
    // Add current Tree data to the sum
    // of the current Tree's level
    sum[level] += Tree->val;
 
    // Recursive call for left and right sub-tree
    calculateLevelSum(Tree->left, level + 1, sum);
    calculateLevelSum(Tree->right, level + 1, sum);
}

// int Sum(Tree *root)
// {
//     int sum = 0;
//     if (root->left)
//     {
//         if (root->right)
//         {
//             cout << root->left->val << " <- " << root->val << " -> " << root->right->val;
//             sum = root->left->val + root->right->val;
//         }
//         else
//         {
//             cout << root->left->val << " <- " << root->val << " -> NULL";
//             sum = root->left->val;
//         }
//     }
//     else if (root->right)
//     {
//         cout << "NULL <- " << root->val << " -> " << root->right->val;
//         sum = root->right->val;
//     }
//     // else
//     // {
//     //     cout << "NULL <- " << root->val << " -> NULL";
//     //     sum = root->val;
//     // }
//     return sum;
// }

int main()
{
    Tree *root = NULL;
    int n;
    cin >> n;
    int x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        root = Init(root, x);
    }
    // Count of levels in the
    // given binary tree
    int levels = getHeight(root) + 1;
    // To store the sum at every level
    int sum[levels] = { 0 };
    calculateLevelSum(root, 0, sum);
    // Print the required sums
    printArr(sum, levels);

    return 0;
}