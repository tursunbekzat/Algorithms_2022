#include <iostream>
using namespace std;

struct List
{
    int value;
    List *next;
    List(int value)
    {
        this->value = value;
        this->next = next;
    }
};

void Insert(List **begin, List **end, int n)
{
    int x;
    cin >> x;
    *begin = new List(x);
    *end = (*begin);
    for (int i(1); i < n; i++)
    {
        cin >> x;
        (*end)->next = new List(x);
        (*end) = (*end)->next;
        (*end)->next = NULL;
    }
}

void Print(List *begin)
{
    List *tmp = begin;
    while (tmp)
    {
        cout << tmp->value << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

void Free(List **begin)
{
    List *tmp = (*begin);
    while (tmp)
    {
        *begin = tmp->next;
        delete tmp;
        tmp = (*begin);
    }
}

int main()
{
    int n;
    cin >> n;
    List *begin = NULL;
    List *end;
    Insert(&begin, &end, n);
    Print(begin);
    Free(&begin);
    return 0;
}