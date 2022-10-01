#include <iostream>
using namespace std;

struct Value
{
    int v;
};

struct List
{
    Value value;
    List *next;
};

void Init(List **begin, List **end)
{
    (*begin) = new List;
    int n;
    cin >> n;
    Value a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].v;
    }
    // (*begin)->next = NULL;
    (*begin)->value = a[0];
    *end = *begin;
    for (int i = 1; i < n; i++)
    {
        (*end)->next = new List;
        (*end) = (*end)->next;
        (*end)->value = a[i];
        (*end)->next = NULL;
    }
}

void Print(List *b)
{
    List *print = b;
    while (print)
    {
        cout << print->value.v << " -> ";
        print = print->next;
    }
    cout << "NULL\n";
}

void SearchNearValue(List **begin, const Value &k)
{
    if (*begin == NULL)
    {
        return;
    }

    int s, cnt = 0, count = 0;
    List *t = *begin;
    List *t1 = t->next;
    s = abs(t->value.v - k.v);
    while (t1)
    {
        cnt++;
        if (abs(t1->value.v - k.v) < s)
        {
            s = abs(t1->value.v - k.v);
            // cout << s << endl;
            count = cnt;
        }
        t = t1;
        t1 = t->next;
    }
    cout << count;
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

    Init(&begin, &end);
    // Print(begin);

    Value k;
    cin >> k.v;

    SearchNearValue(&begin, k);

    Free(&begin);
    return 0;
}