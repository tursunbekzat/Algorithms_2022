#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> boris;
    deque<int> nursik;

    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        if (i < 5)
        {
            boris.push_back(x);
        }
        else
        {
            nursik.push_back(x);
        }
    }

    int count = 0;
    while (count < 1000000)
    {

        if (boris.empty() || nursik.empty())
        {
            break;
        }

        if (boris.front() == 0 && nursik.front() == 9)
        {
            boris.push_back(boris[0]);
            boris.push_back(nursik[0]);
            boris.pop_front();
            nursik.pop_front();
        }
        else if (boris.front() == 9 && nursik.front() == 0)
        {
            nursik.push_back(boris[0]);
            nursik.push_back(nursik[0]);
            boris.pop_front();
            nursik.pop_front();
        }
        else
        {
            if (boris.front() < nursik.front())
            {
                nursik.push_back(boris[0]);
                nursik.push_back(nursik[0]);
                boris.pop_front();
                nursik.pop_front();
            }
            else
            {
                boris.push_back(boris[0]);
                boris.push_back(nursik[0]);
                boris.pop_front();
                nursik.pop_front();
            }
        }
        // cout << endl;
        // for(int i:boris){
        //     cout << i << " ";
        // }
        // cout << endl;
        // for(int i:nursik){
        //     cout << i << " ";
        // }
        // cout << endl;
        count++;
    }

    if (boris.empty())
    {
        cout << "Nursik"
             << " " << count;
    }
    else if (nursik.empty())
    {
        cout << "Boris"
             << " " << count;
    }
    else
    {
        cout << "blin nichya";
    }

    return 0;
}