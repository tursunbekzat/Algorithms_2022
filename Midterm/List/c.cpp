#include <iostream>
using namespace std;

struct List
{
    int val;
    List *next;
    List(int val)
    {
        this->val = val;
        next = NULL;
    }
};

List *Insert(List *last, int val)
{
    List *node = new List(val);
    if (last == NULL)
    {
        last = node;
        last->next = last;
        return last;
    }
    node->next = last->next;
    last = node;
    return last;
}

void Print(List *last)
{
    List *p = last->next;
    do
    {
        cout << p->val << "==>";
        p = p->next;
    } while (p != last->next);
    if (p == last->next)
        cout << p->val;
    cout << "\n\n";
}

int main()
{
    int n;
    cin >> n;

    List *last = NULL;

    int value;
    for (int i(0); i < n; i++)
    {
        cin >> value;
        last = Insert(last, value);
    }
    Print(last);
    return 0;
}