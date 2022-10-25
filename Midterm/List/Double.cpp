#include <iostream>
using namespace std;

struct List
{
    int val;
    List *next, *prev;
    List(int val)
    {
        this->val = val;
        next = prev = NULL;
    }
};

void Init(List **begin, List **end, int n)
{
    int x;
    cin >> x;
    if ((*begin) == NULL)
    {
        (*begin) = new List(x);
        (*begin)->prev = NULL;
        (*begin)->next = NULL;
    }
    (*end) = (*begin);
    List *tmp = (*end);
    for (int i(1); i < n; i++)
    {
        cin >> x;

        (*end)->next = new List(x);
        (*end) = (*end)->next;
        (*end)->prev = tmp;
        (*end)->next = NULL;
        tmp = (*end);
    }
}

void Print(List **begin)
{
    List *tmp = (*begin);
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void AddFront(List **begin, int val)
{
    List *newNode = new List(val);
    List *tmp = (*begin);
    (*begin) = newNode;
    (*begin)->next = tmp;
    tmp->prev = (*begin);
    // (*begin)->prev = NULL;
}

void AddBack(List **begin, List **end, int val)
{
    List* tmp = (*end);
    (*end) = (*end)->next;
    (*end) = new List(val);
    (*end)->prev = tmp;
    tmp->next = (*end);
    (*end)->next = NULL;
}

void Reverse(List **end)
{
    List *tmp = (*end);
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void Free(List **begin)
{
    List *tmp = (*begin);
    while ((*begin))
    {
        (*begin) = (*begin)->next;
        delete[] tmp;
        tmp = (*begin);
    }
}

int main()
{
    int n;
    cin >> n;
    List *begin = NULL, *end;
    Init(&begin, &end, n);
    Print(&begin);

    int f;
    cin >> f;
    AddFront(&begin, f);
    Print(&begin);

    int b;
    cin >> b;
    AddBack(&begin, &end, b);
    Print(&begin);
    Reverse(&end);

    Free(&begin);

    return 0;
}