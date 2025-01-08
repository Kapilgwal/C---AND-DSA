#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str = "[ ()";

    stack<char> st;

    for (auto it : str)
    {
        if (it == '(' || it == '{' || it == '[')
        {
            st.push(it);
        }
        else if (it == ')' || it == '}' || it == ']')
        {
            if (st.empty())
            {
                cout << "Not Balanced\n";
                return 0;
            }

            if ((it == ')' && st.top() == '(') ||
                (it == '}' && st.top() == '{') ||
                (it == ']' && st.top() == '['))
            {
                st.pop();
            }
            else
            {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }

    if (st.empty())
    {
        cout << "Balanced\n";
    }
    else
    {
        cout << "Not Balanced\n";
    }

    return 0;
}
