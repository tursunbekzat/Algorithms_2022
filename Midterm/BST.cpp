#include<iostream>
using namespace std;

struct Tree{
    int val, cnt;
    Tree* left, *right;
    Tree(int val){
        this->val = val;
        left = right = NULL;
        cnt = 1;
    }
};

Tree* Insert(Tree* root, int val){
    if(root == NULL){
        root = new Tree(val);
        return root;
    }
    if(root->val > val){
        root->left = Insert(root->left, val);
    }
    if(root->val < val){
        root->right = Insert(root->right, val);
    }
    if(root->val == val){
        root->cnt++;
    }
    return root;
}

void Print(Tree* root){
    if(root == NULL){
        cout << "NULL" << " ";
        return;
    }
    cout << (root)->val << " ";
    Print((root)->left);
    Print((root)->right);
}

Tree* Delete(Tree* root, int val){
    if(root == NULL){
        return;
    }
    if(root->val == val){
        
    }
    return root;
}

int main(){
    int n;
    cin >> n;

    Tree* root = NULL;

    int val;
    for(int i(0);i<n;i++){
        cin >> val;
        root = Insert(root, val);
    }

    Print(root);



    return 0;
}