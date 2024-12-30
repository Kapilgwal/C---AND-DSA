#include <iostream>
using namespace std;

int main()
{

    int a = 5;
    int b = 6;

    while (b != 0)
    {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    cout << a << endl;

    return 0;
}