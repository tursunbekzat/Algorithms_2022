#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct A
{
    int a;
};

struct List
{
    A list;
    List *next;
};

void Init(List **begin, List **end, int n, A nums[])
{
    *begin = new List();

    for (int i(0); i < n; i++)
    {
        cin >> nums[i].a;
    }

    (*begin)->list.a = nums[0].a;
    (*begin)->next = NULL;
    (*end) = (*begin);

    for (int i(1); i < n; i++)
    {
        (*end)->next = new List();
        (*end) = (*end)->next;
        (*end)->list.a = nums[i].a;
        (*end)->next = NULL;
    }
}

void Print(List *begin)
{
    List *p = begin;
    while (p)
    {
        cout << p->list.a << " ";
        p = p->next;
    }
    cout << endl;
}

void Free(List **begin)
{
    List *d = *begin;
    while (d)
    {
        (*begin) = d->next;
        delete d;
        d = (*begin);
    }
}

void Sort(List **begin)
{
    vector<pair<int, int>> vp;
    set<int> s;
    List *p = (*begin);
    while (p)
    {
        s.insert(p->list.a);
        p = p->next;
    }

    //  // print the set of unique numbers
    // set<int>::iterator it;
    // for(it=s.begin();it!=s.end();++it){
    //     cout << *it << " ";
    // }
    // cout << endl;

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it)
    {
        int cnt = 0;
        p = (*begin);
        // int x = p->list.a;
        while (p)
        {
            if (p->list.a == *it)
            {
                cnt++;
            }
            p = p->next;
        }
        vp.push_back(make_pair(cnt, *it));
    }

    sort(vp.begin(), vp.end());

    // // print pair
    // for (int i = 0; i < vp.size(); ++i)
    // {
    //     cout << vp[i].first << ":" << vp[i].second << " ";
    // }
    // cout << endl;

    int max = vp[vp.size() - 1].first;
    // cout << max;
    for (int i(vp.size() - 1); i > -1; i--)
    {
        if (max == vp[i].first)
        {
            cout << vp[i].second << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    A nums[n];

    List *begin = NULL;
    List *end;

    Init(&begin, &end, n, nums);
    // Print(begin);
    Sort(&begin);
    Free(&begin);
    return 0;
}
