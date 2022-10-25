#include<iostream>

using namespace std;

struct Tree{
    int val;
    Tree *next;
    Tree(int val){
        this->val = val;
        this->next = NULL;
    }
};

Tree* Insert_Begin(int val, Tree *head){
    Tree *newNode = new Tree(val);
    newNode->next = head;
    head = newNode;
    return head;
}

Tree *Remove_Begin(Tree *head){
    Tree *rmv = head;
    head = head->next;
    delete rmv;
}



int main(){
    Tree *a = new Tree(5);
    Tree *b = new Tree(15);
    a->next = b;
    Tree *head = a;
}