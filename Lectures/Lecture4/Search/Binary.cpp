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

void Menu(vector<int> &values, int &n, int &c)
{

    cout << "Count of sorted values: ";
    cin >> n;
    cout << "Print sorted values: ";
    Input(values, n);
    cout << "Value of searching: ";
    cin >> c;
}

bool BinarySearch(vector<int> values, int n, int c, int low, int hight)
{
    if (values.empty() || low > hight)
    {
        cout << "Not found!\n";
        return 0;
    }
    int mid = (low + hight) / 2;
    if (c == values[mid])
    {
        cout <<"This value located in " << mid + 1<<" order\n";
        return 0;
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
    Menu(values, n, c);
    int low = 0, hight = values.size() - 1;
    cout << BinarySearch(values, n, c, low, hight) << endl;
    return 0;
}