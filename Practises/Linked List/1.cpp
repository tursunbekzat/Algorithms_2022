//\****************************///
//|*** reversed linked list ***|//
///****************************\//
#include <iostream>
using namespace std;

// create structer
struct List
{
    // value of Node
    int num;
    // pointer for next Node
    List *next;
    // constructer
    List(int num)
    {
        this->num = num;
        this->next = next;
    }
};

// initialize List
void Init(List **begin, int value)
{
    // create new Node with value 'value'
    List* newNode = new List(value);
    // create new pointerfor iterating in List
    List* tmp = *begin;
    // finding end of the List
    while(tmp->next){
        tmp=tmp->next;
    }
    // add newNode in the back of the List
    tmp->next = newNode;
    tmp->next->next = NULL;
}

// print current List
void Print(List** begin){
    List* tmp = *begin;
    while(tmp){
        cout << tmp->num << " -> ";
        tmp=tmp->next;
    }cout<<"NUll\n";
}

// reverse List
void Reverse(List* begin){
    if(!begin) return;
    Reverse(begin->next);
    cout << " <- " << begin->num;
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

// main function
int main()
{
    List *begin = new List(0);
    int n, x;
    cin >> n;
    cin >> x;
    begin->num = x;
    for (int i(1); i < n; i++)
    {
        cin >> x;
        Init(&begin, x);
    }
    cout<<"Current List:\n";
    Print(&begin);
    cout <<"Reserved List:\nNULL";
    Reverse(begin);
    cout << endl;
    // Print(&begin);
    Free(&begin);

    return 0;
}