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
    void prem(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, vector<int> &freq)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[i] == 0)
            {
                temp.push_back(nums[i]);
                freq[i] = 1;
                prem(nums, temp, ans, freq);
                temp.pop_back();
                freq[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> freq(nums.size(), 0);
        prem(nums, temp, ans, freq);
        return ans;
    }
};