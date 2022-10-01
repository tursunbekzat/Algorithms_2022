// deque

#include <iostream>
#include <deque>

using namespace std;

int main()
{

    deque<int> d;
    char symbol;
    int value;

    cin >> symbol;
    if (symbol != '!' && symbol != '*')
    {
        cin >> value;
    }
    while (symbol != '!')
    {

        switch (symbol)
        {

        case '+':
            d.push_front(value);

            break;
        case '-':
            d.push_back(value);

            break;
        case '*':
            if (d.empty())
            {

                cout << "error" << '\n';
                symbol = '!';
                break;
            }

            cout << d[0] + d[d.size() - 1] << endl;
            if (d.size() == 1)
            {
                d.pop_front();
            }
            else
            {
                d.pop_front();
                d.pop_back();
            }
            break;
        }
        cin >> symbol;
        if (symbol != '!' && symbol != '*')
            cin >> value;
    }

    return 0;
}