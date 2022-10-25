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

// Preorder 
void Preorder(Tree* root) {
  if (root == NULL)
    return;

  cout << root->val << "->";
  Preorder(root->left);
  Preorder(root->right);
}

// Postorder 
void Postorder(Tree* root) {
  if (root == NULL)
    return;

  Postorder(root->left);
  Postorder(root->right);
  cout << root->val << "->";
}

// Inorder 
void Inorder(struct Tree* root) {
  if (root == NULL)
    return;

  Inorder(root->left);
  cout << root->val << "->";
  Inorder(root->right);
}

// Find the inorder successor
Tree *minValueTree(Tree *root)
{
    Tree *current = root;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Tree *Delete(Tree *root, int val)
{
    if (root == NULL)
        return root;

    // Find the Tree to be deleted
    if (val < root->val)
        root->left = Delete(root->left, val);
    else if (val > root->val)
        root->right = Delete(root->right, val);
    else
    {
        // If the Tree is with only one child or no child
        if (root->left == NULL)
        {
            struct Tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Tree *temp = root->left;
            free(root);
            return temp;
        }

        // If the Tree has two children
        Tree *temp = minValueTree(root->right);

        // Place the inorder successor in position of the Tree to be deleted
        root->val = temp->val;

        // Delete the inorder successor
        root->right = Delete(root->right, temp->val);
    }
    return root;
}

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

    Inorder(root);
    cout << endl;
    Preorder(root);
    cout << endl;
    Postorder(root);
    cout << endl;

    cin >> val;
    root = Delete(root, val);

    return 0;
}