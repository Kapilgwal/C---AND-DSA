#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 121;

    if (n < 0)
    {
        cout << "Non palindrome" << endl;
    }

    else
    {
        int temp = 0;
        int num = n;
        while (n > 0)
        {
            temp = temp * 10 + n % 10;
            n = n / 10;
        }

        if (temp == num)
        {
            cout << "Palindrome" << endl;
        }

        else
        {
            cout << "Non palindrome" << endl;
        }
    }

    return 0;
}