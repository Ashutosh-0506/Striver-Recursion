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
#include <bits/stdc++.h>
using namespace ::std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int c = 0, sum = 0;
        map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]) % k;
            if (sum < 0)
            {
                sum += k;
            }
            c += m[sum];
            m[sum]++;
        }
        return c;
    }
};