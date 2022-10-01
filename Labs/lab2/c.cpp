#include <iostream>

using namespace std;

struct Value
{
    int num;
};

struct List
{
    Value nums;
    List *next;
};

void Init(List **begin, List **end, Value values[], int n)
{
    *begin = new List;

    (*begin)->nums.num = values[0].num;
    (*begin)->next = NULL;
    *end = *begin;
    for (int i(1); i < n; i++)
    {
        if (i % 2 == 0)
        {
            (*end)->next = new List;
            *end = (*end)->next;
            (*end)->nums.num = values[i].num;
            (*end)->next = NULL;
        }
    }
}

void Print(List *begin)
{
    List *t = begin;
    while (t)
    {
        cout << t->nums.num << " ";
        t = t->next;
    }
    // cout << "NULL" << endl;
}

void DeleteEven(List **begin, int cnt)
{
    List *t1 = *begin;
    List *t2;
    int count = 0;
    while (count != cnt - 1)
    {
        t2 = t1->next;
        t1->next = t2->next;
        t1 = t2;
        t2 = t2->next;
        count++;
    }
    delete t1;
}

void Free(List **begin)
{
    List *t = *begin;
    while (t)
    {
        *begin = t->next;
        delete t;
        t = *begin;
    }
}

int main()
{
    List *begin = NULL;
    List *end;

    int n, x;
    cin >> n;
    Value values[n];
    for (int i(0); i < n; i++)
    {
        cin >> x;
        values[i].num = x;
    }

    Init(&begin, &end, values, n);
    
    Print(begin);

    Free(&begin);

    return 0;
}