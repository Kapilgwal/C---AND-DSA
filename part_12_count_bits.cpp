#include <iostream>
using namespace std;

int main()
{

    int n = 11;
    int cnt = 0;

    while (n)
    {
        int rem = n % 2;
        if (rem)
        {
            cnt++;
        }

        n = n / 2;
    }

    cout << cnt << endl;

    return 0;
}