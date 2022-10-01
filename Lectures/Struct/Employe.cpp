#include <iostream>

using namespace std;

struct Employe
{
    char *name;
    int CountPropusk;
    short salary;
};

void Input(Employe *p, int n)
{

    cout << "Input name: ";
    p->name = new char[20];
    cin.get();
    cin.getline(p->name, 20);

    cout << "Input the salary: ";
    cin >> p->salary;

    cout << "Input count of propusk: ";
    cin >> p->CountPropusk;
};

void Delete(Employe *p)
{
    if (p->CountPropusk > 5)
    {
        cout << "Delete: " << p->name << endl;
    }
};

void Free(const Employe p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] p[i].name;
    }
};

int main()
{
    Employe d[4];

    for (int i = 0; i < 4; i++)
    {
        Input(&d[i], 4);
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        Delete(&d[i]);
    }

    Free(d, 4);

    return 0;
}