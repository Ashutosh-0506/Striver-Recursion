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

//Time complexity=o(1.6180)^n
//Time complexity=o(2^n)

#include <bits/stdc++.h>
using namespace ::std;
int febonachi(int n)
{
    int secondlast, last;
    if (n <= 1)
    {
        return n;
    }
    else
    {
        secondlast = febonachi(n - 1);
        last = febonachi(n - 2);
        return (secondlast + last);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << febonachi(n) << endl;
    return 0;
}