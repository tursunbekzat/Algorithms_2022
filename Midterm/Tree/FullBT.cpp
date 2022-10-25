// Checking if a binary tree is a full binary tree in C++

#include <iostream>
using namespace std;

struct Tree {
  int val;
  struct Tree *left, *right;
  Tree(int val){
      this->val = val;
      left = right = NULL;
  }
};

bool isFullBinaryTree(struct Tree *root) {
  
  // Checking for emptiness
  if (root == NULL)
    return true;

  // Checking for the presence of children
  if (root->left == NULL && root->right == NULL)
    return true;

  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  return false;
}

int main() {
  struct Tree *root = NULL;
  root = new Tree(1);
  root->left = new Tree(2);
  root->right = new Tree(3);
  root->left->left = new Tree(4);
  root->left->right = new Tree(5);
  root->left->right->left = new Tree(6);
  root->left->right->right = new Tree(7);

  if (isFullBinaryTree(root))
    cout << "The tree is a full binary tree\n";
  else
    cout << "The tree is not a full binary tree\n";
}