#include <iostream>

using namespace std;

struct Word
{
    string soz;
};

struct List
{
    Word sozder;
    List *next;
};

void Init(List **begin, List **end, int n)
{
    *begin = new List;

    Word words[n];
    string s;
    for (int i(0); i < n; i++)
    {
        cin >> s;
        words[i].soz = s;
    }

    (*begin)->sozder.soz = words[0].soz;
    (*begin)->next = NULL;
    *end = *begin;

    for (int i(1); i < n; i++)
    {
        (*end)->next = new List;
        (*end) = (*end)->next;
        (*end)->sozder.soz = words[i].soz;
        (*end)->next = NULL;
    }
}

void Print(List *begin)
{
    List *t = begin;

    while (t)
    {
        cout << t->sozder.soz << " ";
        t = t->next;
    }
    // cout << "NULL" << endl;
}

void AddEnd(List **begin, List **end)
{
    Word w = (*begin)->sozder;
    List *t = *begin;
    *begin = (*begin)->next;
    (*end)->next = new List;
    (*end) = (*end)->next;
    (*end)->sozder.soz = w.soz;
    (*end)->next = NULL;
    delete t;
}

void Poem(List **begin, List **end, int m)
{
    for (int i = 0; i < m; i++)
    {
        AddEnd(&(*begin), &(*end));
    }
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

    int n, m;
    cin >> n >> m;

    Init(&begin, &end, n);
    // Print(begin);
    Poem(&begin, &end, m);
    Print(begin);
    Free(&begin);
    return 0;
}