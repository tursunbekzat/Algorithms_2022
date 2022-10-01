#include <iostream>
#include <vector>
using namespace std;

struct A
{
    string a;
};

struct List
{
    A s;
    List *next;
};

void InsertHead(List **begin, string value)
{
    List *i = new List;
    i->s.a = value;
    i->next = *begin;
    *begin = i;
}

void Print(List *begin)
{
    List *p = begin;
    while (p)
    {
        cout << p->s.a << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void PrintSolution(List *begin)
{
    vector<string> v;
    List *p = begin;
    int cnt = 0;
    while (p)
    {
        if (p->s.a != "")
        {
            cnt++;
            v.push_back(p->s.a);
        }
        p = p->next;
    }
    cout << "All in all: " << cnt << endl;
    cout << "Students:" << endl;
    for (int i(0); i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
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

void Sort(List **begin)
{
    List *s = *begin;
    List *s1 = s->next;
    while (s1)
    {
        if (s->s.a == s1->s.a)
        {
            s->next = s1->next;
            delete s1;
            s1 = s->next;
        }
        else
        {
            s = s1;
            s1 = s->next;
        }
    }
}

int main()
{
    List *begin = NULL;
    int n;
    cin >> n;

    for (int i(0); i < n; i++)
    {
        string t;
        cin >> t;
        InsertHead(&begin, t);
    }
    // cout << "Initial list: ";
    // Print(begin);
    Sort(&begin);
    // cout << "Sorted list: ";
    PrintSolution(begin);
    // PrintSolution(begin);

    Free(&begin);
    return 0;
}