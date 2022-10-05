// #include <iostream>
// #include <vector>

// using namespace std;

// struct Value
// {
//     int v;
// };

// struct List
// {
//     Value num;
//     List *next;
// };

// void Input(List **begin, List **end, int n)
// {
//     int x;
//     cin >> x;
//     *begin = new List;
//     (*begin)->num.v = x;
//     *end = *begin;
//     for (int i = 1; i < n; i++)
//     {
//         cin >> x;
//         (*end)->next = new List;
//         *end = (*end)->next;
//         (*end)->num.v = x;
//         (*end)->next = NULL;
//     }
// }

// string BinarySearch(int c, List **begin, List **end, int mid)
// {
//     if (*begin == NULL)
//     {
//         return "No";
//     }
//     // cout <<"l - " <<low << " h - " << hight << endl;
//     List *p = *begin;
//     cout <<"m - "<< mid <<endl;
//     int cnt = mid;
//     while (cnt > 0)
//     {
//         cnt--;
//         p = p->next;
//     }
//     cout << "p - " << p->num.v << endl;
//     if (p->num.v == c || (mid == 0 && (*begin)->num.v == c))
//     {
//         return "Yes";
//     }
//     if (p->num.v > c)
//     {
//         cout << "lower"<<endl;
//         (*end) = p;
//         (*end)->next = NULL;
//         return BinarySearch(c, &*begin, &*end, mid/2);
//     }
//     cout <<"highter"<<endl;
//     p->next = *begin;
//     return BinarySearch(c, &*begin, &*end, mid/2);
// }

// int main()
// {
//     List *begin = NULL, *end;
//     int n;
//     cin >> n;
//     Input(&begin, &end, n);
//     int c;
//     cin >> c;
//     int low = 0, hight = n - 1;
//     int mid = (n - 1) / 2;
//     cout << BinarySearch(c, &begin, &end, mid) << endl;
//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

void Input(vector<int> &values, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        values.push_back(x);
    }
}

// void Menu(vector<int> &values, int &n, int &c)
// {

//     cout << "Count of sorted values: ";
//     cin >> n;
//     cout << "Print sorted values: ";
//     Input(values, n);
//     cout << "Value of searching: ";
//     cin >> c;
// }

string BinarySearch(vector<int> values, int n, int c, int low, int hight)
{
    if (values.empty() || low > hight)
    {
        // cout << "Not found!\n";
        return "No";
    }
    int mid = (low + hight) / 2;
    if (c == values[mid])
    {
        // cout <<"This value located in " << mid + 1<<" order\n";
        return "Yes";
    }
    else
    {
        if (c > values[mid])
        {
            return BinarySearch(values, n, c, low = mid + 1, hight);
        }
        else
        {
            return BinarySearch(values, n, c, low, hight = mid - 1);
        }
    }
}

int main()
{
    vector<int> values;
    int n, c;
    // Menu(values, n, c);
    cin >> n;
    Input(values, n);
    cin >> c;
    int low = 0, hight = values.size() - 1;
    cout << BinarySearch(values, n, c, low, hight) << endl;
    return 0;
}