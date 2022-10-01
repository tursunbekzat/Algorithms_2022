#include <iostream>
using namespace std;

struct A
{
    int key;
};

struct List
{
    A a;
    List *next;
};

void Print(List *b)
{
    List *print = b;
    while (print)
    {
        cout << print->a.key << " -> ";
        print = print->next;
    }
    cout << "NULL\n";
}

/*
void InitMy(List **begin, List **end, int n)
{
    *begin = new List();

    int s;
    cin >> s;

    (*begin)->a.key = s;
    (*begin)->next = NULL;
    (*end) = (*begin);

    for (int i(1); i < n; i++)
    {
        cin >> s;
        (*end)->next = new List();
        (*end) = (*end)->next;
        (*end)->a.key = s;
        (*end)->next = NULL;
    }
}
*/

void Init(List **begin, List **end)
{
    (*begin) = new List;

    A a[5] = {1, 2, 3, 4, 5};

    (*begin)->a.key = 0;
    (*begin)->next = NULL;

    *end = *begin;

    for (int i = 0; i < 5; i++)
    {
        (*end)->next = new List;
        (*end) = (*end)->next;
        (*end)->a = a[i];
        (*end)->next = NULL;
    }
}

void Add_Begin(List **begin, const A &a)
{
    List *t = new List;
    t->a = a;
    t->next = *begin;
    *begin = t;
}

void Add_End(List **end, const A &a)
{
    List *t = new List;
    t->a = a;
    (*end)->next = t;
    (*end) = t;
    (*end)->next = NULL;
}

void Insert(List **begin, const A &a)
{
    List *inst = new List;
    inst->a = a;

    if (*begin == NULL)
    {
        inst->next = NULL;
        *begin = inst;
        return;
    }

    List *t = *begin;
    if (t->a.key >= inst->a.key)
    {
        inst->next = t;
        *begin = inst;
        return;
    }

    List *t1 = t->next;

    while (t1)
    {
        if (t->a.key < inst->a.key && inst->a.key <= t1->a.key)
        {
            t->next = inst;
            inst->next = t1;
            return;
        }
        t = t->next;
        t1 = t->next;
    }
    t->next = inst;
    inst->next = NULL;
}

void Delete(List **begin, const A &a)
{
    if (*begin == NULL)
    {
        return;
    }

    List *delet = *begin;
    if (delet->a.key == a.key)
    {
        *begin = delet->next;
        delete delet;
        return;
    }

    List *t = delet->next;

    while (t)
    {
        if (t->a.key == a.key)
        {
            delet->next = t->next;
            delete t;
            return;
        }
        delet = t;
        t = t->next;

    }
}

void Free(List **begin){
    List *t = *begin;
    while(t){
        *begin = t->next;
        delete t;
        t = *begin;
    }
}

int main()
{
    List *begin = NULL;
    List *end;
    A a = {-12};
    A b = {6};
    A c = {2};
    A d = {3};

    Init(&begin, &end);
    Print(begin);

    Add_Begin(&begin, a);
    Print(begin);

    Add_End(&end, b);
    Print(begin);

    Insert(&begin, c);
    Print(begin);

    Delete(&begin, d);
    Print(begin);

    Free(&begin);
    Print(begin);
    return 0;
}