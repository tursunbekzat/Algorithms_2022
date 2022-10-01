#include <iostream>
#include<math.h>

using namespace std;

struct XY
{
    double x;
    double y;
};

struct Polar
{
    double angle;
    double distance;
};

void showPolar(const Polar &p)
{
    const double degree = 57.3;
    cout << "Distanse: " << p.distance << endl;
    cout << "Angle : " << p.angle * degree << endl;
}

Polar Convert(const XY &xy){
    Polar p;
    p.distance = sqrt(pow(xy.x, 2) + pow(xy.y, 2)); 
    p.angle = atan2(xy.x, xy.y);
    return p;
}

int main()
{
    XY a;
    Polar b;

    a.x = 10;
    a.y = 10;

    b = Convert(a);
    showPolar(b);

    return 0;
}