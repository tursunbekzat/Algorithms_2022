#include <iostream>
#include <list>

using namespace std;

struct fio
{
    string last_name;
    string first_name;
};
struct info
{
    struct fio fio;
    int year;
    double height;
    string job;
};

int main()
{
    struct info peoples[4];  
    struct info people = {{ "Tursun", "Bekzat"}, 2004, 175, "student"};

    peoples[0].fio.first_name = "Erik";
    peoples[0].fio.last_name = "Eppaev";
    peoples[0].year = 1970;
    peoples[0].height = 170;
    peoples[0].job = "structure";

    peoples[0].fio.first_name = "Erik";
    peoples[0].fio.last_name = "Eppaev";
    peoples[0].year = 1970;
    peoples[0].height = 170;
    peoples[0].job = "structure";

    peoples[0].fio.first_name = "Erik";
    peoples[0].fio.last_name = "Eppaev";
    peoples[0].year = 1970;
    peoples[0].height = 170;
    peoples[0].job = "structure";

    peoples[0].fio.first_name = "Erik";
    peoples[0].fio.last_name = "Eppaev";
    peoples[0].year = 1970;
    peoples[0].height = 170;
    peoples[0].job = "structure";

    cout << people.fio.first_name << endl;

    return 0;
}