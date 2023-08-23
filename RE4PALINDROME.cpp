//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/

// String on reversal reads the same.Ex:-"M A D A M","1 1 2 1 1 ";
#include <bits/stdc++.h>
using namespace ::std;
class Solution
{
public:
    bool palindrome(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < n; i++)
        {
            m1[s[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            m2[t[i]]++;
        }
        int flag = 1;
        if (m != n)
        {
            flag = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (m1[i] != m2[i])
            {
                flag = 0;
            }
        }
        if (flag)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    string st;
    cin >> st;
    int n = st.length();
    palindrome(st, n, 0);
    return 0;
}