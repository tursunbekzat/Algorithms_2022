#include <iostream>

using namespace std;

struct Auto
{
    char *name;
    short year;
    double price;
    double weigth;
    string color;
};

void Input(Auto a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "Name of the " << i + 1 << " car: ";
        a[i].name = new char[30];
        cin.get();
        cin.getline(a[i].name, 30);

        cout << "Input year of creating of the car: ";
        cin >> a[i].year;

        cout << "Input price of the car: ";
        cin >> a[i].price;

        cout << "Input weight of the car: ";
        cin >> a[i].weigth;

        cout << "Input color of the car: ";
        cin >> a[i].color;

        cout << endl;
    }
}

void Show(const Auto cars[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "car: \n";
        cout << "Name of the car:   " << cars[i].name << endl;
        cout << "Year of the car:   " << cars[i].year << endl;
        cout << "Price of the car:  " << cars[i].price << endl;
        cout << "Weight of the car: " << cars[i].weigth << endl;
        cout << "Color of the car:  " << cars[i].color << endl;
        cout << '_' * 30 << endl;
    }
}

void Free(Auto cars[], int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] cars[i].name;
    }
}

void Menu()
{
    cout << "1. Input info: \n";
    cout << "2. Show info: \n";
    cout << "3. Exit: \n";
}

int main()
{

    int n;
    cout << "Input count of the cars: ";
    cin >> n;
    cout << endl;

    Auto *cars = new Auto[n];

    char c;

    do
    {
        Menu();
        cout << endl
             << "Choose the command: ";
        cin >> c;
        switch (c)
        {
        case '1':
            Input(cars, n);
            break;
        case '2':
            Show(cars, n);
            break;
        case '3':
            cout << "Thank you for your visiting my site!\n";
            break;
        default:
            cout << "error!";
        }
    } while (c != '3');

    Free(cars, n);
    delete[] cars;
    cout << endl;

    return 0;
}