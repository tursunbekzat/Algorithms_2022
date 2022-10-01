#include <iostream>
using namespace std;

union tag_value
{
    int vi;
    double vd;
    char vc;
};

enum tag_type
{
    VT_INT,
    VT_DOUBLE,
    VT_CHAR
};

struct tag_var
{
    union tag_value value;
    // short type_var;
    tag_type type_var;
};

int main()
{
    struct tag_var var[3];
    var[0].type_var = VT_INT;
    var[0].value.vi = 2022;

    var[1].type_var = VT_DOUBLE;
    var[1].value.vd = 123.4;

    var[2].type_var = VT_CHAR;
    var[2].value.vc = 'b';

    // cout << var[0].value.vi << " " << var[1].value.vd << " " << var[2].value.vc << endl;

    for (int i = 0; i < 3; i++)
    {
        switch (var[i].type_var)
        {
        case VT_INT:
            cout << var[i].value.vi << endl;
            break;
        case VT_DOUBLE:
            cout << var[i].value.vd << endl;
            break;
        case VT_CHAR:
            cout << var[i].value.vc << endl;
            break;
        }
    }
    return 0;
}