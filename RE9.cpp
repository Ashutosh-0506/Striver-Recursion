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
    void comb(int index, int target, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            for (int i = index; i < candidates.size(); i++)
            {
                if (i > index && candidates[i] == candidates[i - 1])
                {
                    continue;
                }
                if (candidates[i] > target)
                {
                    break;
                }
                temp.push_back(candidates[i]);
                comb(i + 1, target - candidates[i], candidates, temp, ans);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        comb(0, target, candidates, temp, ans);
        return ans;
    }
};
int main()
{

    return 0;
}