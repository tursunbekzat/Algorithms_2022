#include <iostream>
using namespace std;

struct Tree
{
    int val;
    struct Tree *left, *right;
    Tree(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

int depth(Tree* root) {
  int d = 0;
  while (root != NULL) {
    d++;
    root = root->left;
  }
  return d;
}

bool isPerfectR(Tree* root, int d, int level = 0) {
  if (root == NULL)
    return true;

  if (root->left == NULL && root->right == NULL)
    return (d == level + 1);

  if (root->left == NULL || root->right == NULL)
    return false;

  return isPerfectR(root->left, d, level + 1) &&
       isPerfectR(root->right, d, level + 1);
}

bool isPerfect(Tree *root) {
  int d = depth(root);
  return isPerfectR(root, d);
}

int main()
{
    Tree* root = NULL;
    root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    if (isPerfect(root))
        cout << "The tree is a perfect binary tree\n";
    else
        cout << "The tree is not a perfect binary tree\n";
    return 0;
}