// #include <iostream>
// #include <vector>
// using namespace std;

// struct Value
// {
//     int v;
// };

// struct List
// {
//     Value value;
//     List *next;
// };

// void Init(List **begin, List **end)
// {
//     (*begin) = new List;
//     int n;
//     cin >> n;
//     Value a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i].v;
//     }
//     (*begin)->value = a[0];
//     *end = *begin;
//     for (int i = 1; i < n; i++)
//     {
//         (*end)->next = new List;
//         (*end) = (*end)->next;
//         (*end)->value = a[i];
//         (*end)->next = NULL;
//     }
// }

// // void Print(List *b)
// // {
// //     List *print = b;
// //     while (print)
// //     {
// //         cout << print->value.v << " -> ";
// //         print = print->next;
// //     }
// //     cout << "NULL\n";
// // }



// void Find(List **begin)
// {
//     vector<pair<int, int>> vp;
//     int N, M;
//     cin >> N >> M;
//     int b[N][M];
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             cin >> b[i][j];
//         }
//     }
//     List *f = *begin;
//     while (f)
//     {
//         int v1 = vp.size();
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < M; j++)
//             {
//                 if (f->value.v == b[i][j])
//                 {
//                     vp.push_back(make_pair(i, j));
//                     break;
//                 }
//             }
//             if(v1 != vp.size()) break;
//         }
//         if(v1 == vp.size())
//         {
//             vp.push_back(make_pair(-1, -1));
//         }
//         f = f->next;
//     }
//     Print_Solution(vp);
// }

// void Free(List **begin)
// {
//     List *t = *begin;
//     while (t)
//     {
//         *begin = t->next;
//         delete t;
//         t = *begin;
//     }
// }

// int main()
// {
//     List *begin = NULL;
//     List *end;

//     Init(&begin, &end);
//     // Print(begin);
//     Find(&begin);

//     Free(&begin);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void Print_Solution(vector<pair<int, int>> vp)
{
    for (int i = 0; i < vp.size(); i++)
    {
        if (vp[i].first == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << vp[i].first << " " << vp[i].second << endl;
        }
    }
}

int main()
{
    int k;
    cin >> k;
    vector<int> v;
    vector<int> v1;
    vector<int> v2;
    vector<pair<int, int>> v0;
    int x;
    for (int i(0); i < k; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i(0); i < n; i++)
    {
        for (int j(0); i < m; i++)
        {
            cin >> x;
            a[i][j] = x;
        }
    }
    int size = 0;
    for (int r(0); r < k; r++)
    {
        size = v0.size();
        for (int i(0); i < n; i++)
        {
            for (int j(0); i < m; i++)
            {
                if (v[r] == a[i][j])
                {
                    v0.push_back(make_pair(i, j));
                    break;
                }
            }
        }
        if(size == v0.size()){
            v0.push_back(make_pair(-1, -1));
        }
    }
    Print_Solution(v0);
    return 0;
}
