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
private:
    void solve(unordered_map<vector<int>, int>&m, vector<int> &temp, int index, int n, vector<int> &nums)
    {
        if (index == n)
        {
            m[temp]++;
            return;
        }
        temp.push_back(nums[index]);
        solve(m, temp, index + 1, n, nums);
        temp.pop_back();
        solve(m, temp, index + 1, n, nums);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<vector<int>, int> m;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(m, temp, 0, n, nums);
        for (auto i : m)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};