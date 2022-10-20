#include<iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node* Insert_Begin(int val, Node *head){
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return head;
}

Node *Remove_Begin(Node *head){
    Node *rmv = head;
    head = head->next;
    delete rmv;
}



int main(){
    Node *a = new Node(5);
    Node *b = new Node(15);
    a->next = b;
    Node *head = a;
}