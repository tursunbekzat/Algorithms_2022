#include<iostream>
using namespace std;

struct List{
    int data;
    List* next;
    List* prev;
};

void Init(List** end, int n){
    int x;
    for(int i(1);i<n;i++){
        cin >> x;
        (*end) = (*end)->next;
        *end = new List;
        (*end)->data = x;
        (*end)->next = NULL;
        (*end)->prev = (*end)->prev;
    }
}

// print current List
void Print(List** begin){
    List* tmp = *begin;
    while(tmp){
        cout << tmp->data << " -> ";
        tmp=tmp->next;
    }cout<<"NUll\n";
}

// delete memory for creating List
void Free(List* *begin){
    List* tmp = *begin;
    while(*begin){
        *begin = tmp->next;
        delete tmp;
        tmp = *begin;
    }
}

int main(){
    int n;
    cin >> n;

    List* begin = new List;
    begin = NULL;
    int x;
    cin >> x;
    begin->data = x;
    begin->prev = NULL;
    begin->next = NULL;
    List* end = begin;
    end->prev = NULL;
    end->next = NULL;
    Init(&end, n);
    Print(&begin);
    Free(&begin);
    return 0;
}