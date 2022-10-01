#include <iostream>

using namespace std;

struct A
{
    int a;
};

struct List
{
    A num;
    List *next;
};

void InsertPosition(List **begin)
{
    List *el = new List;
    int i, k;
    cin >> i >> k;
    el->num.a = i;
    if(k == 0){
        el->next = *begin;
        *begin = el;
        return;
    }

    int cnt = 0;
    List *ip = *begin;
    List *ip1 = ip->next;
    while (ip)
    {
        if (cnt + 1 == k)
        {
            ip->next = el;
            el->next = ip1;
            return;
        }
        ip = ip->next;
        ip1 = ip->next;
        cnt++;
    }
}

void Insert(List **begin, List **end)
{
    *begin = new List;

    int n;
    cin >> n;

    int x;
    cin >> x;
    (*begin)->num.a = x;
    *end = *begin;

    for (int i(1); i < n; i++)
    {
        cin >> x;
        (*end)->next = new List;
        *end = (*end)->next;
        (*end)->num.a = x;
        (*end)->next = NULL;
    }

    // int k;
    // cin >> k;
}

void Print(List *begin)
{
    List *p = begin;
    while (p)
    {
        cout << p->num.a << " ";
        p = p->next;
    }

    cout << endl;
}

void Free(List **begin)
{
    List *f = *begin;
    while (f)
    {
        *begin = f->next;
        delete f;
        f = *begin;
    }
}

int main()
{
    List *begin = NULL;
    List *end;
    Insert(&begin, &end);
    // Print(begin);
    InsertPosition(&begin);
    Print(begin);
    return 0;
}